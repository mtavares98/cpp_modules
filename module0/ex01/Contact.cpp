#include "Contact.hpp"

Contact::Contact() {
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->phoneNumber = "";
    this->darkestSecret = "";
    std::cout << "Called Contact default constructor" << std::endl;
}

Contact::~Contact() {
    std::cout << "Called Contact default destructor" << std::endl;
}

void Contact::setFirstName(std::string newName) {
    this->firstName = newName;
}

std::string Contact::getFirstName(void) {
    return this->firstName;
}

void Contact::setLastName(std::string newLastName) {
    this->lastName = newLastName;
}

std::string Contact::getLastName(void) {
    return this->lastName;
}

void Contact::setNickname(std::string newNickname) {
    this->nickname = newNickname;
}

std::string Contact::getNickname(void) {
    return this->nickname;
}

void Contact::setPhoneNumber(std::string newPhoneNumber) {
    this->phoneNumber = newPhoneNumber;
}

std::string Contact::getPhoneNumber(void) {
    return this->phoneNumber;
}

void Contact::setDarkestSecret(std::string newDarkestSecret) {
    this->darkestSecret = newDarkestSecret;
}

std::string Contact::getDarkestSecret(void) {
    return this->darkestSecret;
}
