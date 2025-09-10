#include "AForm.hpp"

AForm::AForm() : s_grade(0), e_grade(0), name("none") , sign(0) 
{
}

AForm::AForm(std::string newName, int s_g, int e_g): s_grade(s_g), e_grade(e_g), name(newName) , sign(0) 
{
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &copy) : name(copy.name), sign(copy.sign), s_grade(copy.s_grade), e_grade(copy.e_grade)
{
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src) {
        this->sign = src.sign;
    }
    return *this;
}

std::string AForm::getName()
{
	return (this->name);
}

bool AForm::getSign()
{
	return this->sign;
}

int AForm::getSGrade()
{
	return this->s_grade;
}

int AForm::getEGrade()
{
	return this->e_grade;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() < this->s_grade && b.getGrade() > 0)
		this->sign = true;
	else if (b.getGrade() < 0) 
		throw GradeTooHighException();
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char* AForm::NotSignedException::what() const throw() {
    return "It is not signed!";
}
