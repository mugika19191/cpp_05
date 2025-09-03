#include "Bureaucrat.hpp"

int main ()
{
	Bureaucrat *b = new Bureaucrat("Man",10);
	try{
		b->setGrade(-1);
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << *b;
	delete b;

	Bureaucrat *a = new Bureaucrat("Man2",1);
	a->incrementGrade();
	delete a;


	Bureaucrat *c = new Bureaucrat("Man2",150);
	c->decrementGrade();
	delete c;

	Bureaucrat *d = new Bureaucrat();
	std::cout << *d;
	delete d;

	return 0;
}