#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm) : AForm(shrubberyCreationForm), _target(shrubberyCreationForm._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shrubberyCreationForm)
{
    if (this != &shrubberyCreationForm) {
        AForm::operator=(shrubberyCreationForm);
        _target = shrubberyCreationForm._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "Grade is too high";
}

// void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
// {
//     AForm::execute(executor);
//     std::string filename = _target + "_shrubbery";
//     std::ofstream file(filename.c_str());
//     if (!file.is_open())
//         throw ShrubberyCreationForm::FileOpenException();
//     file << TREE;
//     file.close();
// }

void	ShrubberyCreationForm::executeConcrete() const
{
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
        throw ShrubberyCreationForm::FileOpenException();
    file << TREE;
    file.close();
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &form)
{
    out << form.getName() << ", form sign grade " << form.getGradeToSign() << ", form exec grade " << form.getGradeToExecute() << ", form is ";
    if (form.isSigned())
        out << "signed";
    else
        out << "not signed";
    return out;
}