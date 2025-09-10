#include <iostream>
#include "AForm.hpp"


class  PresidentialPardonForm: public AForm
{
	private:
		std::string target;
	public:
		void beExecuted(Bureaucrat &b);
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string newTarget);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
};