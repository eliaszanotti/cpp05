/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.class.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:17:55 by elias             #+#    #+#             */
/*   Updated: 2023/06/12 14:36:34 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "PresidentialPardonForm.class.hpp"

// Print
void PresidentialPardonForm::print(std::string const &str, int color) const
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
		std::cout << colorsString << "[PresidentialPardonForm " << this->_target << "] " << reset;
	else
		std::cout << colorsString << "[PresidentialPardonForm " << this->_target << "] " << reset << str << std::endl;
}

// Constructors
PresidentialPardonForm::PresidentialPardonForm(): 
	Form("PresidentialPardonForm", 25, 5)
{
	this->_target = "<default target>";
	this->print("created", 2);
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): 
	Form("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
	this->print("created", 2);
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy):
	Form(copy)
{
	this->_target = copy._target;
	this->print("created by copy", 2);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	this->print("deleted", 1);
}

// Operators
PresidentialPardonForm const	&PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	Form::operator=(copy);
	this->_target = copy._target;
	this->print("created by assignment", 2);
	return (*this);
}

// Methods
void PresidentialPardonForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	this->print("", 3);
	std::cout << " has been pardoned by Zafod Beeblebrox thanks to " << bureaucrat.getName() << std::endl;
}

std::ostream &operator<<(std::ostream &stream, PresidentialPardonForm const &form)
{
	if (form.getIsSigned())
	{
        stream << "\e[33m[Form " << form.getName() << "]\e[0m signed \e[32m:)\e[0m (signing grade=" << form.getSigningGrade();
		return (stream << ") (execute grade=" << form.getExecuteGrade() << ")" << std::flush);
	}
	stream << "\e[33m[Form " << form.getName() << "]\e[0m not signed \e[31m:(\e[0m (signing grade=" << form.getSigningGrade();
	return (stream << ") (execute grade=" << form.getExecuteGrade() << ")" << std::flush);
}
