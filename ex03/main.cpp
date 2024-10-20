#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    RobotomyRequestForm* rrf = (RobotomyRequestForm *)someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
    delete rrf;

    ShrubberyCreationForm* scf = (ShrubberyCreationForm *)someRandomIntern.makeForm("shrubbery creation", "Bender");
    std::cout << *scf << std::endl;
    delete scf;

    PresidentialPardonForm* ppf = (PresidentialPardonForm *)someRandomIntern.makeForm("presidential pardon", "Bender");
    std::cout << *ppf << std::endl;
    delete ppf;
}

// __attribute__((destructor)) static void destructor() {
//   system("leaks -q a.out");
// }