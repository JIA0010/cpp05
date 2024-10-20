#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm) : AForm(robotomyRequestForm), _target(robotomyRequestForm._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &robotomyRequestForm)
{
    if (this != &robotomyRequestForm) {
        AForm::operator=(robotomyRequestForm);
        _target = robotomyRequestForm._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget(void) const { return _target; }

void	RobotomyRequestForm::executeConcrete() const
{
    std::cout << "*drilling noises* ";
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form)
{
    out << form.getName() << ", form sign grade " << form.getGradeToSign() << ", form exec grade " << form.getGradeToExecute() << ", form is ";
    if (form.isSigned())
        out << "signed";
    else
        out << "not signed";
    return out;
}