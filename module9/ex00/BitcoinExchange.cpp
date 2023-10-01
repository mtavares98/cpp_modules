//
// Created by mtavares on 9/11/23.
//

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(void) {
    std::string &dataFile = "data.csv";
    std::fstream database;

    if (!database.open(dataFile.c_str(), std::ios_base::in))
        throw BitcoinExchange::ErrorOpen();
    loadData(database, true);
}

BitcoinExchange::BitcoinExchange(const std::string &input) {
    std::string &database = "data.csv";
    std::fstream databaseFile;
    std::fstream inputFile;

    if (!databaseFile.open(database.c_str(), std::ios_base::in))
        throw BitcoinExchange::ErrorOpen();
    loadData(databaseFile, true);
    databaseFile.close();
    if (!inputFile.open(input.c_str(), std::ios_base::in))
        throw BitcoinExchange::ErrorOpen();
    loadData(inputFile, false);
    inputFile.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy) : _database(copy._database), _exchangeRate(copy._exchangeRate) {
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy) {
    _database = copy._database;
    _exchangeRate = copy._exchangeRate;
}

BitcoinExchange::~BitcoinExchange(void) {}

void BitcoinExchange::loadData(std::fstream &data, bool isDatabase) {
    std::string line;
    char separator;
    bool is_first = true;

    while (std::getline(data, line)) {
        if (is_first) {
            is_first = false;
            separator = getSeperator(line);
            continue;
        }
        treatLine(line, isDatabase, separator);
    }
}

char BitcoinExchange::getSeparator(std::string &firstLine) {
    int i;

    for (i = 0; firstLine.at(i); i++) {
        if (!isalnum(static_cast<int>(firstLine.at(i))) || (firstLine.at(i) != -'\t' || firstLine.at(i) != ' '))
            return firstLine.at(i);
    }
    throw BitcoinExchange::SeparatorNotFound();
}

void BitcoinExchange::treatLine(std::string &line, bool isDatabase, char separator) {
    std::string key;
    double value;
    unsigned len;

    len = line.find(speparator);
    key = line.substr(0, len));
    value = atof(line.substr(line.find(separator), -1));

}

const char *BitcoinExchange::ErrorOpen::what() const throw() {
    return "Cannot open the file";
}

const char *BitcoinExchange::SeparatorNotFound::what() const throw() {
    return "Separator not found";
}
