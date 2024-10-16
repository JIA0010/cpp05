#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm* makePresidentialPardonForm(const std::string& target);

AForm* makeRobotomyRequestForm(const std::string& target);

AForm* makeShrubberyCreationForm(const std::string& target);

typedef struct s_arraymap
{
    std::string name;
    AForm *(*func)(const std::string&);
} t_arraymap;

class Intern
{
    public:
        Intern();
        Intern(Intern const &intern);
        Intern &operator=(Intern const &intern);
        ~Intern();
        AForm *makeForm(std::string name, std::string target);
        class InvalidFormNameException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif