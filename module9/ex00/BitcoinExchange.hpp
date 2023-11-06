/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:04:12 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/03 11:35:55 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange(const std::string &filePath);
  BitcoinExchange(const BitcoinExchange &copy);
  BitcoinExchange &operator=(const BitcoinExchange &copy);
  ~BitcoinExchange();

 private:
  std::map<std::string, float> _database;
  BitcoinExchange();
  void loadData(std::fstream &file, bool isDatabase);
  void treatLine(std::string &line, bool isDatabase, std::string &separator);
  void validDate(std::string &date, std::string &line);
  void treatInput(std::string &key, float value);
};

#endif  // BITCOINEXCHANGE_HPP
