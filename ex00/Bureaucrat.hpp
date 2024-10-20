#ifndef BUREAUCRAT_HPP 
 #define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#define DEFAULT_NAME "default"
#define DEFAULT_GRADE 150
#define HIGHEST_POSSIBLE_GRADE 1
#define LOWEST_POSSIBLE_GRADE 150
class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &bureaucrat);
        Bureaucrat &operator=(Bureaucrat const &bureaucrat);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);


#endif