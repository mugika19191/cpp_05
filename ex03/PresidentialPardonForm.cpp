#include "PresidentialPardonForm.hpp"
#include <stdlib.h>

void PresidentialPardonForm::beExecuted(Bureaucrat &b)
{
	if(this->getEGrade() <= 0)
		throw AForm::GradeTooHighException();
	if (!(this->getEGrade() >= b.getGrade()))
		throw AForm::GradeTooLowException();
	if (this->getSign())
	{
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox."<< std::endl;
		return;
	}
	else  
		throw AForm::NotSignedException();
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm",25,5), target("none")
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget): AForm("PresidentialPardonForm",25,5), target(newTarget)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src) {
		AForm::operator=(src);    
        this->target = src.target;
    }
    return *this;
}
