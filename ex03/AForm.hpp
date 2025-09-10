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
		virtual ~AForm();
		AForm(const AForm &copy);
		AForm &operator=(const AForm &src);

		std::string getName();
		bool getSign();
		int getSGrade();
		int getEGrade();
		void beSigned(Bureaucrat &b);
		virtual void beExecuted(Bureaucrat &b) = 0;

		class GradeTooHighException : public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};

		class NotSignedException : public std::exception{
			public:
				virtual char const	*what(void) const throw();
		};
};
#endif