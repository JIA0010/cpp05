#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm) : AForm(presidentialPardonForm), _target(presidentialPardonForm._target) {}

void    PresidentialPardonForm::executeConcrete() const
{
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &presidentialPardonForm)
{
    if (this != &presidentialPardonForm) {
        AForm::operator=(presidentialPardonForm);
        _target = presidentialPardonForm._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::ostream& operator<<(std::ostream &out, PresidentialPardonForm const &form)
{
    out << form.getName() << ", form sign grade " << form.getGradeToSign() << ", form exec grade " << form.getGradeToExecute() << ", form is ";
    if (form.isSigned())
        out << "signed";
    else
        out << "not signed";
    return out;
}