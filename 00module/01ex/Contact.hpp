#ifndef CONTATC_HPP
# define CONTACT_HPP

class Contact
{

	public:

	Contact(void);
	~Contact(void);
	
	void		set_contact(void);
	std::string	get_param(int opt);
	int			status(void);

	private:

	int			_Status;
	std::string	name;
	std::string	last;
	std::string	nick;
	std::string	pnbr;
	std::string	dark;

	void		_set_contact(std::string str, const std::string param);
};

#endif