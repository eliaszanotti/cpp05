/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 12:08:34 by elias             #+#    #+#             */
/*   Updated: 2023/06/12 12:15:53 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Form.class.hpp"

// Print
void Form::print(std::string const &str, int color) const
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
		std::cout << colorsString << "[Form " << this->_name << "] " << reset;
	else
		std::cout << colorsString << "[Form " << this->_name << "] " << reset << str << std::endl;
}

// Constructors
Form::Form():
	_name("<default name>"),
	_isSigned(false),
	_signingGrade(50),
	_executeGrade(100)
{
	this->print("created", 2);
}

Form::Form(std::string const &name, int const signingGrade, int const executeGrade):
	_name(name),
	_isSigned(false),
	_signingGrade(signingGrade),
	_executeGrade(executeGrade)
{
	if (signingGrade > 150)
		throw (Form::GradeTooLowException());
	if (signingGrade < 1)
		throw (Form::GradeTooHighException());
	if (executeGrade > 150)
		throw (Form::GradeTooLowException());
	if (executeGrade < 1)
		throw (Form::GradeTooHighException());
	this->print("created", 2);
}

Form::Form(Form const &copy):
	_name(copy.getName()),
	_isSigned(copy.getIsSigned()),
	_signingGrade(copy.getSigningGrade()),
	_executeGrade(copy.getExecuteGrade())
{
	this->print("created", 2);
}

Form::~Form()
{
	this->print("deleted", 1);
}

// Operators
Form const	&Form::operator=(Form const &copy)
{
	this->_isSigned = copy.getIsSigned();
	this->print("created by assignment", 2);
	return (*this);
}

// Methods
void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signingGrade)
		throw (Form::GradeTooLowException());
	else
	{
		this->_isSigned = true;
		this->print("form signed !", 3);
	}
}

void Form::execute(Bureaucrat const &executor) const
{
	if (!this->_isSigned)
		throw (Form::FormNotSigned());
	else if (executor.getGrade() > this->_executeGrade)
		throw (Form::GradeTooLowException());
	else
		this->beExecuted(executor);
}

// Getters and Setters
std::string const	&Form::getName(void) const
{
    return (this->_name);
}

bool	Form::getIsSigned(void) const
{
    return (this->_isSigned);
}

int const	&Form::getSigningGrade(void) const
{
    return (this->_signingGrade);
}

int const	&Form::getExecuteGrade(void) const
{
    return (this->_executeGrade);
}

// Exceptions
char const *Form::GradeTooHighException::what(void) const throw()
{
    return ("\e[31m[ERROR]\e[0m Grade too high!");
}

char const *Form::GradeTooLowException::what(void) const throw()
{
    return ("\e[31m[ERROR]\e[0m Grade too low!");
}

char const *Form::FormNotSigned::what(void) const throw()
{
    return ("\e[31m[ERROR]\e[0m Form is not signed!");
}

std::ostream &operator<<(std::ostream &stream, Form const &form)
{
	if (form.getIsSigned())
	{
        stream << "\e[33m[Form " << form.getName() << "]\e[0m signed \e[32m:)\e[0m (signing grade=" << form.getSigningGrade();
		return (stream << ") (execute grade=" << form.getExecuteGrade() << ")" << std::flush);
	}
	stream << "\e[33m[Form " << form.getName() << "]\e[0m not signed \e[31m:(\e[0m (signing grade=" << form.getSigningGrade();
	return (stream << ") (execute grade=" << form.getExecuteGrade() << ")" << std::flush);
}
