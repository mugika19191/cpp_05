#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <ctime>

void RobotomyRequestForm::beExecuted(Bureaucrat &b)
{
	if(this->getEGrade() <= 0)
		throw AForm::GradeTooHighException();
	if (!(this->getEGrade() >= b.getGrade()))
		throw AForm::GradeTooLowException();
	if (this->getSign())
	{
		std::srand(std::time(NULL));
		int i = std::rand() % 2;
		std::cout << "BRRRRRRRRRRRBRBRBRBBRBRBRBRBRBR" << std::endl;
		if (i == 1)
			std::cout << this->target << " has been robotomized successfully! "<<std::endl;
		else
			std::cout << this->target << " is dead." << std::endl;
		return;
	}
	else  
		throw AForm::NotSignedException();
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",72,45), target("none")
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget): AForm("RobotomyRequestForm",72,45), target(newTarget)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src) {
		AForm::operator=(src);    
        this->target = src.target;
    }
    return *this;
}
