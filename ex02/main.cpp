#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat john("John", 50);
		Bureaucrat alice("Alice", 10);
		Form taxForm("Tax Form", 20, 100); // Requires grade <= 20 to sign

		std::cout << "Trying to sign form with John:\n";
		john.signForm(taxForm); // Should fail

		std::cout << "\nTrying to sign form with Alice:\n";
		alice.signForm(taxForm); // Should succeed

		std::cout << "\nForm \"" << taxForm.getName()
		          << "\" is " << (taxForm.getSign() ? "signed" : "not signed") << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
