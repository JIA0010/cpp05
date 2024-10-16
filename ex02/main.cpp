#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat asan("Asan", 20);
        ShrubberyCreationForm contract("home");

        asan.signForm(contract);
        std::cout << contract << std::endl;
        asan.executeForm(contract);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bsan("Bsan", 1);
        RobotomyRequestForm topSecret("home");

        bsan.signForm(topSecret);
        std::cout << topSecret << std::endl;
        bsan.executeForm(topSecret);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat csan("Csan", 100);
        PresidentialPardonForm report("home");

        csan.signForm(report);
        std::cout << report << std::endl;
        csan.executeForm(report);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
