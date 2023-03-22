#include "main.hpp"

Contact::Contact(void)
{
	std::cout << "Bob the builder was called" << std::endl;
	this->_Status = 0;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Demolishor was called" << std::endl;
	return ;
}

std::string	Contact::get_param(int opt)
{
	if (opt == 1)
		return (this->name);
	if (opt == 2)
		return (this->last);
	if (opt == 3)
		return (this->nick);
	if (opt == 4)
		return (this->pnbr);
	if (opt == 5)
		return (this->dark);
	return ("100N/A001");
}

int	Contact::status(void)
{
	return (this->_Status);
}

void	Contact::set_contact(void)
{
	this->_Status = 1;
	Contact::_set_contact("Type the name of your contact:", "name");
	Contact::_set_contact("Type the last name of your contact:", "last");
	Contact::_set_contact("Type the nickname of your contact:", "nick");
	Contact::_set_contact("Type the phone number of your contact:", "pnbr");
	Contact::_set_contact("Type the darkest secret of your contact:", "dark");
}

void	Contact::_set_contact(std::string str, const std::string param)
{
	std::string	prompt;

	std::cout << str << std::endl;
	std::getline(std::cin, prompt);
	if (!std::cin)
		return ;
	if (param == "name")	
		this->name = prompt;
	if (param == "last")
		this->last = prompt;
	if (param == "nick")
		this->nick = prompt;
	if (param == "pnbr")
		this->pnbr = prompt;
	if (param == "dark")
		this->dark = prompt;
}