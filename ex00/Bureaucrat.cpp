#include "Bureaucrat.hpp"

void Bureaucrat::setGrade(int newGrade)
{
	if (newGrade < 1)
		throw GradeTooHighException();
	else if(newGrade > 150)
		throw GradeTooLowException();
	this->grade = newGrade;
}

Bureaucrat::Bureaucrat() : name("none"), grade(0)
{
}

Bureaucrat::Bureaucrat(std::string newName,int newGrade) : name(newName)
{
	setGrade(newGrade);
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade)
{
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	try{
		setGrade(this->grade - 1);
	}
	catch (GradeTooHighException& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try{
		setGrade(this->grade + 1);
	}
	catch (GradeTooLowException& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src) {
        this->grade = src.grade;
    }
    return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}

