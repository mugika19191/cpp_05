#include <iostream>
#include "AForm.hpp"


class  ShrubberyCreationForm: public AForm
{
	private:
		std::string target;
	public:
		void beExecuted(Bureaucrat &b);
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string newTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
};