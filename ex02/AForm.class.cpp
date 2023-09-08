/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:08:34 by elias             #+#    #+#             */
/*   Updated: 2023/09/07 18:06:12 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "AForm.class.hpp"

// Print
void AForm::print(std::string const &str, int color) const
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
		std::cout << colorsString << "[AForm " << this->_name << "] " << reset;
	else
		std::cout << colorsString << "[AForm " << this->_name << "] " << reset << str << std::endl;
}

// Constructors
AForm::AForm():
	_name("<default name>"),
	_isSigned(false),
	_signingGrade(50),
	_executeGrade(100)
{
	this->print("created", 2);
}

AForm::AForm(std::string const &name, int const signingGrade, int const executeGrade):
	_name(name),
	_isSigned(false),
	_signingGrade(signingGrade),
	_executeGrade(executeGrade)
{
	if (signingGrade > 150 || executeGrade > 150)
		throw (AForm::GradeTooLowException());
	if (signingGrade < 1 || executeGrade < 1)
		throw (AForm::GradeTooHighException());
	this->print("created", 2);
}

AForm::AForm(AForm const &copy):
	_name(copy.getName()),
	_isSigned(copy.getIsSigned()),
	_signingGrade(copy.getSigningGrade()),
	_executeGrade(copy.getExecuteGrade())
{
	this->print("created", 2);
}

AForm::~AForm()
{
	this->print("deleted", 1);
}

// Operators
AForm const	&AForm::operator=(AForm const &copy)
{
	this->_isSigned = copy.getIsSigned();
	this->print("created by assignment", 2);
	return (*this);
}

// Methods
void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signingGrade)
		throw (AForm::GradeTooLowException());
	else
	{
		this->_isSigned = true;
		this->print("Aform signed !", 3);
	}
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw (AForm::AFormNotSigned());
	else if (executor.getGrade() > this->_executeGrade)
		throw (AForm::GradeTooLowException());
	else
		this->beExecuted(executor);
}

// Getters and Setters
std::string const	&AForm::getName(void) const
{
    return (this->_name);
}

bool	AForm::getIsSigned(void) const
{
    return (this->_isSigned);
}

int const	&AForm::getSigningGrade(void) const
{
    return (this->_signingGrade);
}

int const	&AForm::getExecuteGrade(void) const
{
    return (this->_executeGrade);
}

// Exceptions
char const *AForm::GradeTooHighException::what(void) const throw()
{
    return ("\e[31m[ERROR]\e[0m Grade too high!");
}

char const *AForm::GradeTooLowException::what(void) const throw()
{
    return ("\e[31m[ERROR]\e[0m Grade too low!");
}

char const *AForm::AFormNotSigned::what(void) const throw()
{
    return ("\e[31m[ERROR]\e[0m AForm is not signed!");
}

std::ostream &operator<<(std::ostream &stream, AForm const &Aform)
{
	if (Aform.getIsSigned())
	{
        stream << "\e[33m[AForm " << Aform.getName() << "]\e[0m signed \e[32m:)\e[0m (signing grade=" << Aform.getSigningGrade();
		return (stream << ") (execute grade=" << Aform.getExecuteGrade() << ")" << std::flush);
	}
	stream << "\e[33m[AForm " << Aform.getName() << "]\e[0m not signed \e[31m:(\e[0m (signing grade=" << Aform.getSigningGrade();
	return (stream << ") (execute grade=" << Aform.getExecuteGrade() << ")" << std::flush);
}
