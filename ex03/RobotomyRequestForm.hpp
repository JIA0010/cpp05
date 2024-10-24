#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
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
        virtual ~RobotomyRequestForm();
        std::string getTarget() const;

};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif