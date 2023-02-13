#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
    std::cout << "Called PhoneBook default constructor" << std::endl;
    this->size = 0;
    this->index = 0;
}

PhoneBook::~PhoneBook(void) {
    std::cout << "Called PhoneBook default destructor" << std::endl;
}

void PhoneBook::setElement(std::string element, int i) {
    std::string input;

    if (std::cin.eof())
        return ;
    std::cout << element << '\n';
    getline(std::cin, this->data[i].value);
}

void PhoneBook::setContact(void) {
    this->contact[this->index].setFirstName(this->data[0].value);
    this->contact[this->index].setLastName(this->data[1].value);
    this->contact[this->index].setNickname(this->data[2].value);
    this->contact[this->index].setPhoneNumber(this->data[3].value);
    this->contact[this->index].setDarkestSecret(this->data[4].value);
}

void PhoneBook::ADD() {
    this->setElement("Enter the first name: ", 0);
    this->setElement("Enter the last yame: ", 1);
    this->setElement("Enter the nickname: ", 2);
    this->setElement("Enter the phone number: ", 3);
    this->setElement("Enter the darkest secret: ", 4);
    for (int i = 0; i < 5; i++) {
        if (this->data->value.empty()) {
            std::cout << "Cannot create a contact" << std::endl;
            return ;
        }
    }
    this->setContact();
    this->index++;
    if (this->index > 7)
        this->index = 0;
    if (this->size != 8)
        this->size++;
}

void PhoneBook::SEARCH() {
    int choice;

    if (this->contact[0].getFirstName().empty()) {
        std::cout << "There's no contacts" << std::endl;
        return ;
    }
    printTableHeader();
    std::cout << "Enter an index of your choice\n";
    std::cin >> choice;
    if (std::cin.fail()) {
        std::cout << "The string enter must be a number" << std::endl;
        return ;
    }
    if (choice < 0 || choice > 7)
	{
		std::cout << "Your index is out of bounds\n";
		return ;
	}
	if (this->contact[choice].getFirstName().empty()) {
		std::cout << "Your contact don't exist\n";
		return ;
	}
	std::cout << this->contact[choice].getFirstName() << '\n';
	std::cout << this->contact[choice].getLastName() << '\n';
	std::cout << this->contact[choice].getNickname() << '\n';
	std::cout << this->contact[choice].getPhoneNumber() << '\n';
	std::cout << this->contact[choice].getDarkestSecret() << '\n';
}

void PhoneBook::printParameter(std::string str)
{
	if (str.length() <= 10) {
		std::cout << std::setw(10) << str;
		return ;
	}
	std::cout << std::setw(9) << str.substr(0, 9);
	std::cout << std::setw(1) << '.';
	return ;
}

void PhoneBook::printTableContent(int index)
{
	std::cout << "|         ";
	std::cout << index;
	std::cout << '|';
	printParameter(this->contact[index].getFirstName());
	std::cout << '|';
	printParameter(this->contact[index].getLastName());
	std::cout << '|';
	printParameter(this->contact[index].getNickname());
	std::cout << '|';
	std::cout << '\n';
}

void PhoneBook::printTableHeader(void)
{
	std::cout << "|     index|First Name| Last Name|  Nickname|" << '\n';
	std::cout << "|----------|----------|----------|----------|" << '\n';
	for(int i = 0; i < 8; i++) {
		if (this->contact[i].getFirstName().empty())
			return ;
		printTableContent(i);
		std::cout << "|----------|----------|----------|----------|" << '\n';
	}
}

int PhoneBook::EXIT() {
    return 0;
}
