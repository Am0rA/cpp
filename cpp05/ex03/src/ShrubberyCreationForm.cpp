/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/19 17:23:50 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/19 17:23:50 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <filesystem>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm(NULL, NULL, 145, 37)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	AForm("ShrubberyCreationForm", target, 145, 37)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) :
	AForm(copy.getName(), copy.getTarget(), 145, 37)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& assign) 
{
	setSign(assign.getSign());
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const 
{
	if (!this->getSign())
		throw(NotSignedException());
	if (executor.getGrade() > this->getExecute())
		throw(GradeTooLowException());
	std::string file = this->getTarget() + "_shrubbery";
	std::fstream fd;
	fd.open(file.c_str(), std::fstream::out | std::fstream::trunc);
    if (fd.bad())
	{
        std::cout << "Failed to open the output file." << std::endl;
        return;
    }

	fd <<
	"ASCII tree is too difficult with c++98 here you go with a normal tree\n"
	"                                              .\n"
	"                                   .         ;  \n"
	"      .              .              ;%     ;;   \n"
	"        ,           ,                :;%  %;   \n"
	"         :         ;                   :;%;'     .,\n"
	",.        %;     %;            ;        %;'    ,;\n"
	"  ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
	"   %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
	"    ;%;      %;        ;%;        % ;%;  ,%;'\n"
	"     `%;.     ;%;     %;'         `;%%;.%;'\n"
	"      `:;%.    ;%%. %@;        %; ;@%;%'\n"
	"         `:%;.  :;bd%;          %;@%;'\n"
	"           `@%:.  :;%.         ;@@%;'\n"
	"             `@%.  `;@%.      ;@@%;\n"
	"               `@%%. `@%%    ;@@%;\n"
	"                 ;@%. :@%%  %@@%;\n"
	"                   %@bd%%%bd%%:;\n"
	"                     #@%%%%%:;;\n"
	"                     %@@%%%::;\n"
	"                     %@@@%(o);  . '\n"
	"                     %@@@o%;:(.,'\n"
	"                 `.. %@@@o%::;\n"
	"                    `)@@@o%::;\n"
	"                     %@@(o)::;\n"
	"                    .%@@@@%::;\n"
	"                    ;%@@@@%::;.\n"
	"                   ;%@@@@%%:;;;. \n"
	"               ...;%@@@@@%%:;;;;,..\n";
    fd.close();
}
