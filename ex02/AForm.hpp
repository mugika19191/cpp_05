class Bureaucrat;
#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const  std::string name;
		bool sign;
		const int s_grade;
		const int e_grade;
	public:
		AForm();
		AForm(std::string newName, int s_g, int e_g);
		~AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &src);

		std::string getName();
		bool getSign();
		void beSigned(Bureaucrat &b);
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