/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/08 13:36:00 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <fstream>
#include "ShrubberyCreationForm.class.hpp"

// Print
void ShrubberyCreationForm::print(std::string const &str, int color) const
{
	std::string colorsString = "";
	std::string reset = "\e[0m";
	
	if (color > 0 && color <= 9)
	{
		std::ostringstream oss;
		oss << "\e[3" << color << "m";
		colorsString = oss.str();
	}
	if (str.empty())
		std::cout << colorsString << "[ShrubberyCreationForm " << this->_target << "] " << reset;
	else
		std::cout << colorsString << "[ShrubberyCreationForm " << this->_target << "] " << reset << str << std::endl;
}

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(): 
	AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "<default target>";
	this->print("created", 2);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): 
	AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
	this->print("created", 2);
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy):
	AForm(copy)
{
	this->_target = copy._target;
	this->print("created by copy", 2);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	this->print("deleted", 1);
}

// Operators
ShrubberyCreationForm const	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	this->print("created by assignment", 2);
	return (*this);
}

// Methods
void ShrubberyCreationForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	std::ofstream	file;	

	file.open((this->_target + "_shrubbery").c_str());

	if (file.is_open())
	{
		file << "    ###\n   #o###\n #####o###\n#o#\\#|#/###\n ###\\|/#o#\n  # }|{  #\n    }|{";
		file.close();
		this->print("", 3);
		std::cout << bureaucrat.getName() << " plant a shrubbery!" << std::endl;
	}
	else
		this->print("unable to plant shrubbery", 3);
}

std::ostream &operator<<(std::ostream &stream, ShrubberyCreationForm const &form)
{
	if (form.getIsSigned())
	{
        stream << "\e[33m[Form " << form.getName() << "]\e[0m signed \e[32m:)\e[0m (signing grade=" << form.getSigningGrade();
		return (stream << ") (execute grade=" << form.getExecuteGrade() << ")" << std::flush);
	}
	stream << "\e[33m[Form " << form.getName() << "]\e[0m not signed \e[31m:(\e[0m (signing grade=" << form.getSigningGrade();
	return (stream << ") (execute grade=" << form.getExecuteGrade() << ")" << std::flush);
}
