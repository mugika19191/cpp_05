#include <iostream>
#include "AForm.hpp"


class  RobotomyRequestForm: public AForm
{
	private:
		std::string target;
	public:
		void beExecuted(Bureaucrat &b);
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string newTarget);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
};