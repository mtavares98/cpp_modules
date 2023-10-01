//
// Created by mtavares on 9/11/23.
//

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <exception>

class BitcoinExchange
{
private:
    std::map<std::string, float> _database;
    std::map<std::string, float> _exchangeRate;
    void checkLine();
    void loadData(std::fstream &data, bool isDatabase);
    char getSeparator(std::string &firstLine);
    void treatLine(std::string &line, bool isDatabase, char separator);
public:
    BitcoinExchange(void);
    BitcoinExchange(std::string &input);
    BitcoinExchange(BitcoinExchange const &copy);
    BitcoinExchange &operator=(BitcoinExchange const &copy);
    ~BitcoinExchange(void);
    class ErrorOpen : public std::exception {
        const char * what() const throw();
    };
    class SeparatorNotFound : public std::exception {
        const char * what() const throw();
    };
};
#endif
