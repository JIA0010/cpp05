#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        virtual void	executeConcrete() const;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &presidentialPardonForm);
        virtual ~PresidentialPardonForm();
        // void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm const &form);

#endif