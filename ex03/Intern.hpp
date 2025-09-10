#include <iostream>
#include "AForm.hpp"

class Intern
{
	private:
	public:
		Intern();
		~Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &src);

		AForm* makeForm(std::string form, std::string target);
		class FormDoesNotExist : public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};
};