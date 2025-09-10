#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1); // Highest rank
        Bureaucrat jim("Jim", 140);
        Bureaucrat tim("Tim", 50);

        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Marvin");
        PresidentialPardonForm pardon("Arthur");

        std::cout << "\n--- Signing Forms ---" << std::endl;
        bob.signForm(shrub);   // Bob can sign everything
        bob.signForm(robot);
        bob.signForm(pardon);

        std::cout << "\n--- Executing ShrubberyCreationForm ---" << std::endl;
        jim.executeForm(shrub);  // Should work (Jim has grade 140, exec required is 137, too low!)
        bob.executeForm(shrub);  // Should succeed

        std::cout << "\n--- Executing RobotomyRequestForm ---" << std::endl;
        tim.executeForm(robot);  // Should fail (needs 45)
        bob.executeForm(robot);  // Should succeed (50% chance success/failure)

        std::cout << "\n--- Executing PresidentialPardonForm ---" << std::endl;
        tim.executeForm(pardon); // Should fail
        bob.executeForm(pardon); // Should succeed

    } catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    try {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << rrf->getName() << std::endl;
        delete rrf;
    }
    catch (std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

