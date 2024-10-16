#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &intern) { *this = intern; }

Intern &Intern::operator=(Intern const &intern)
{
    (void)intern;
    return *this;
}

Intern::~Intern() {}

AForm* createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
    const t_arraymap arraymap[] = {
        {"presidential pardon", createPresidentialPardonForm},
        {"robotomy request", createRobotomyRequestForm},
        {"shrubbery creation", createShrubberyCreationForm}
    };

    for (int i = 0; i < 3; i++)
    {
        if (arraymap[i].name == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return arraymap[i].func(target);
        }
    }
    throw Intern::InvalidFormNameException();
    return NULL;
}

const char *Intern::InvalidFormNameException::what() const throw()
{
    return "Invalid form name";
}