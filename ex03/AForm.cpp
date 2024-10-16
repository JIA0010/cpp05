#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &Aform) 
    : _name(Aform._name), _signed(Aform._signed), _gradeToSign(Aform._gradeToSign), _gradeToExecute(Aform._gradeToExecute) {}

AForm &AForm::operator=(AForm const &Aform)
{
    if (this != &Aform) {
        _signed = Aform._signed;
        // _name, _gradeToSign, and _gradeToExecute are const, so they are not assignable
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }

bool AForm::isSigned() const { return _signed; }

int AForm::getGradeToSign() const { return _gradeToSign; }

int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

void	AForm::execute(const Bureaucrat& executor) const {
	if (!isSigned())
		throw ExecuteUnsignedException();
	if (_gradeToExecute < executor.getGrade())
		throw GradeTooLowException();
	executeConcrete();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::ExecuteUnsignedException::what() const throw()
{
    return "Form is not signed";
}

std::ostream &operator<<(std::ostream &out, AForm const &Aform)
{
    out << Aform.getName() << ", Aform sign grade " << Aform.getGradeToSign() << ", Aform exec grade " << Aform.getGradeToExecute() << ", Aform is ";
    if (Aform.isSigned())
        out << "signed";
    else
        out << "not signed";
    return out;
}
