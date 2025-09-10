#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &copy)
{
}

Intern &Intern::operator=(const Intern &src)
{
	if (this != &src) {
        *this = src;
    }
    return *this;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	int i;
	AForm *myForm;
	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for(i = 0;i<3;i++)
	{
		if (formTypes[i] == form)
			break;
	}
	switch (i)
	{
		case 0:
			myForm = new ShrubberyCreationForm(target);
			break;
		case 1:
			myForm = new RobotomyRequestForm(target);
			break;
		case 2:
			myForm = new PresidentialPardonForm(target);
			break;
		default:
			throw FormDoesNotExist();
	}
	std::cout << "Intern creates " << myForm->getName() << "." << std::endl;
	return myForm;
}

const char* Intern::FormDoesNotExist::what() const throw() {
    return "Form does not exist!";
}
