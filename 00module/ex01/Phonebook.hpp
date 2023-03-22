#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	public:
	
	PhoneBook(void);
	~PhoneBook(void);

	Contact	cont[8];
	void	Search(void);

	private:

	void	pparam(int i, int i2);
	void	printH(void);
	int		indexsearch(void);

};

#endif