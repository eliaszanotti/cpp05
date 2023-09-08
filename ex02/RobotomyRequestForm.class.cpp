/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/06/12 12:33:31 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include "RobotomyRequestForm.class.hpp"

// Print
void RobotomyRequestForm::print(std::string const &str, int color) const
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
		std::cout << colorsString << "[RobotomyRequestForm " << this->_target << "] " << reset;
	else
		std::cout << colorsString << "[RobotomyRequestForm " << this->_target << "] " << reset << str << std::endl;
}

// Constructors
RobotomyRequestForm::RobotomyRequestForm(): 
	AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "<default target>";
	this->print("created", 2);
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): 
	AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	this->print("created", 2);
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy):
	AForm(copy)
{
	this->_target = copy._target;
	this->print("created by copy", 2);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	this->print("deleted", 1);
}

// Operators
RobotomyRequestForm const	&RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	this->print("created by assignment", 2);
	return (*this);
}

// Methods
void RobotomyRequestForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	srand((unsigned) time(NULL));
	
	this->print("", 3);
	if (rand() % 2)
		std::cout << bureaucrat.getName() << " has successfully robotomized!" << std::endl;
	else
		std::cout << bureaucrat.getName() << " failed to robotomize..." << std::endl;
}

std::ostream &operator<<(std::ostream &stream, RobotomyRequestForm const &form)
{
	if (form.getIsSigned())
	{
        stream << "\e[33m[Form " << form.getName() << "]\e[0m signed \e[32m:)\e[0m (signing grade=" << form.getSigningGrade();
		return (stream << ") (execute grade=" << form.getExecuteGrade() << ")" << std::flush);
	}
	stream << "\e[33m[Form " << form.getName() << "]\e[0m not signed \e[31m:(\e[0m (signing grade=" << form.getSigningGrade();
	return (stream << ") (execute grade=" << form.getExecuteGrade() << ")" << std::flush);
}
