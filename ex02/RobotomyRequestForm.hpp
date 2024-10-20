#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        virtual void	executeConcrete() const;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm);
        RobotomyRequestForm &operator=(RobotomyRequestForm const &robotomyRequestForm);
        ~RobotomyRequestForm();
        std::string getTarget(void) const;

};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif