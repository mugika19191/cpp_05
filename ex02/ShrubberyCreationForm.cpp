#include "ShrubberyCreationForm.hpp"
#include <fstream>

void ShrubberyCreationForm::beExecuted(Bureaucrat &b)
{
	const std::string ascii_tree =
	"       _-_\n"
	"    /~~   ~~\\\n"
	" /~~         ~~\\\n"
	"{               }\n"
	" \\  _-     -_  /\n"
	"   ~  \\\\ //  ~\n"
	"_- -   | | _- _\n"
	"  _ -  | |   -_\n"
	"      // \\\\ \n";
	
	if(this->getEGrade() <= 0)
		throw AForm::GradeTooHighException();
	if (!(this->getEGrade() >= b.getGrade()))
		throw AForm::GradeTooLowException();
	if (this->getSign())
	{
		std::ofstream file(this->target + "_shrubbery");
		file << ascii_tree;
		return;
	}
	else  
		throw AForm::NotSignedException();
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145,137), target("none")
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget): AForm("ShrubberyCreationForm",145,137), target(newTarget)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src) {
		AForm::operator=(src);    
        this->target = src.target;
    }
    return *this;
}
