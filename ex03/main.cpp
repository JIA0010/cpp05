#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    RobotomyRequestForm* rrf = (RobotomyRequestForm *)someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << rrf << std::endl;
    delete rrf;
}

// __attribute__((destructor)) static void destructor() {
//   system("leaks -q a.out");
// }