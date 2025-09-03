class Form;
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
	private:
		const  std::string name;
		int grade;
		
	public:
		Bureaucrat();
		Bureaucrat(std::string newName, int newGrade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &src);
		
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void setGrade(int newGrade);
		void signForm(Form &f);
		void executeForm(Form &f);
		class GradeTooHighException : public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};
		
		class GradeTooLowException : public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
#endif