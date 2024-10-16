#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

#define TREE "                                                         .\n" \
"                                              .         ;  \n" \
"                 .              .              ;%     ;;   \n" \
"                   ,           ,                :;%  %;   \n" \
"                    :         ;                   :;%;'     .,  \n" \
"           ,.        %;     %;            ;        %;'    ,;\n" \
"             ;       ;%;  %%;        ,     %;    ;%;    ,'%\n" \
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n" \
"               ;%;      %;        ;%;        % ;%;  ,%;'\n" \
"                `%;.     ;%;     %;'         `;%%;.%;'\n" \
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n" \
"                    `:%;.  :;bd%;          %;@%;'\n" \
"                      `@%:.  :;%.         ;@@%;'   \n" \
"                        `@%.  `;@%.      ;@@%;         \n" \
"                          `@%%. `@%%    ;@@%;        \n" \
"                            ;@%. :@%%  %@@%;       \n" \
"                              %@bd%%%bd%%:;     \n" \
"                                #@%%%%%:;;\n" \
"                                %@@%%%::;\n" \
"                                %@@@%(o);  . '         \n" \
"                                %@@@o%;:(.,'         \n" \
"                            `.. %@@@o%::;         \n" \
"                               `)@@@o%::;         \n" \
"                                %@@(o)::;        \n" \
"                               .%@@@@%::;         \n" \
"                               ;%@@@@%::;.          \n" \
"                              ;%@@@@%%:;;;.\n" \
"                          ...;%@@@@@%%:;;;;,..    "


class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
        virtual void	executeConcrete() const;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &shrubberyCreationForm);
        ~ShrubberyCreationForm();
        // void execute(Bureaucrat const &executor) const;
        class FileOpenException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &form);


#endif