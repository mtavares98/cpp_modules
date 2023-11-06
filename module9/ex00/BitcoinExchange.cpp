/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:04:00 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/03 12:49:23 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

#include "helper.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const std::string &filePath) {
  std::fstream db;
  std::fstream file;

  file.open(filePath.c_str(), std::ios_base::in);
  if (!file.is_open()) {
    throw std::runtime_error("could not open file");
  }
  db.open("data.csv", std::ios_base::in);
  if (!db.is_open()) {
    throw std::runtime_error("could not open file");
  }
  try {
    loadData(db, 1);
  } catch (std::exception &e) {
    throw;
  }
  try {
    loadData(file, 0);
  } catch (std::exception &e) {
    throw;
  }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
    : _database(copy._database) {
  *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
  this->_database = copy._database;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadData(std::fstream &file, bool isDatabase) {
  std::string line;
  bool isFirst = true;
  std::string separator = "|";

  while (std::getline(file, line)) {
    if (isFirst) {
      isFirst = false;
      if (isDatabase) {
        if (line != "date,exchange_rate" && line != "date;exchange_rate")
          throw std::runtime_error("invalid database header");
        if (line.find(",") == std::string::npos)
          separator = ";";
        else
          separator = ",";
      } else {
        if (line != "date | value") throw std::runtime_error("invalid header");
      }
      continue;
    }
    try {
      treatLine(line, isDatabase, separator);
    } catch (std::exception &e) {
      if (isDatabase)
        throw;
      else {
        std::cerr << "Error: " << e.what() << std::endl;
        continue;
      }
    }
  }
}

void BitcoinExchange::treatLine(std::string &line, bool isDatabase,
                                std::string &separator) {
  std::string key;
  float value;
  size_t len;

  len = line.find(separator);
  if (len == std::string::npos)
    throw std::runtime_error("bad input => " + line);
  key = line.substr(0, len);
  key.erase(key.find_last_not_of("\t ") + 1);
  key.erase(0, key.find_first_not_of("\t "));
  validDate(key, line);
  value = strtod(line.substr(len + 1).c_str(), NULL);
  if (isDatabase)
    this->_database[key] = value;
  else {
    try {
      treatInput(key, value);
    } catch (std::exception &e) {
      throw;
    }
  }
}

void BitcoinExchange::validDate(std::string &date, std::string &line) {
  int year, month, day;

  if (date.size() != 10) throw std::runtime_error("bad input => " + line);
  for (int i = 0; i < 10; i++) {
    if (i != 4 && i != 7 && !isdigit(date[i]))
      throw std::runtime_error("bad input => " + line);
    else if ((i == 4 || i == 7) && date[i] != '-')
      throw std::runtime_error("bad input => " + line);
  }
  year = atoi(&date[0]);
  month = atoi(&date[5]);
  day = atoi(&date[8]);
  if (year < 2009 || year > 2023)
    throw std::runtime_error("bad input => " + line);
  if (month < 1 || month > 12) throw std::runtime_error("bad input =>" + line);
  if (day < 1 || (months31(month) && day > 31) ||
      (months30(month) && day > 30) ||
      (leapYear(year) && month == 2 && day > 29) ||
      (!leapYear(year) && month == 2 && day > 28))
    throw std::runtime_error("bad input => " + line);
}

void BitcoinExchange::treatInput(std::string &key, float value) {
  std::map<std::string, float>::iterator begin = this->_database.begin();

  if (value < 0)
    throw std::runtime_error("not a positive number");
  else if (value > 1000)
    throw std::runtime_error("too large number");
  for (; begin != this->_database.end(); begin++) {
    if (key == begin->first) break;
    if (key < begin->first) {
      begin--;
      break;
    }
  }
  if (begin == this->_database.begin() && key > begin->first)
    throw std::runtime_error("not found");
  std::cout << key << " => " << begin->second * value << std::endl;
}
