class Bureaucrat;
#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const  std::string name;
		bool sign;
		const int s_grade;
		const int e_grade;
	public:
		Form();
		Form(std::string newName, int s_g, int e_g);
		~Form();
		Form(const Form &copy);
		Form &operator=(const Form &src);

		std::string getName();
		bool getSign();
		void beSigned(Bureaucrat &b);

		class GradeTooHighException : public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};
};
#endif