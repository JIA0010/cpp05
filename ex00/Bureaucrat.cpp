#include "Bureaucrat.hpp"

//セッターを加える。今の状態だと各項目ごとにテストケースで確認するのが面倒
void Bureaucrat::SetGradeSafely(int grade) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}


Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    SetGradeSafely(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureaucrat)
{
    SetGradeSafely(bureaucrat._grade);
    return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
    SetGradeSafely(_grade - 1);
}

void Bureaucrat::decrementGrade()
{
    SetGradeSafely(_grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return out;
}
