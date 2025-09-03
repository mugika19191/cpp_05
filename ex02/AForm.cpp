#include "Form.hpp"

Form::Form() : s_grade(0), e_grade(0), name("none") , sign(0) 
{
}

Form::Form(std::string newName, int s_g, int e_g): s_grade(s_g), e_grade(e_g), name(newName) , sign(0) 
{
}

Form::~Form()
{
}

Form::Form(const Form &copy) : name(copy.name), sign(copy.sign), s_grade(copy.s_grade), e_grade(copy.e_grade)
{
}

Form &Form::operator=(const Form &src)
{
	if (this != &src) {
        this->sign = src.sign;
    }
    return *this;
}

std::string Form::getName()
{
	return (this->name);
}

bool Form::getSign()
{
	return this->sign;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() < this->s_grade && b.getGrade() > 0)
		this->sign = true;
	else if (b.getGrade() < 0) 
		throw GradeTooHighException();
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high for signing!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low for signing!";
}
