/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/06/05 16:26:49 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Bureaucrat.class.hpp"

// Print
void Bureaucrat::print(std::string const &str, int color) const
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
		std::cout << colorsString << "[Bureaucrat " << this->_name << "] " << reset;
	else
		std::cout << colorsString << "[Bureaucrat " << this->_name << "] " << reset << str << std::endl;
}

// Constructors
Bureaucrat::Bureaucrat(std::string const &name, int grade): _name(name)
{
	this->_grade = grade;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->print("created", 2);
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy._name)
{
	*this = copy;
	this->print("created by copy", 2);
}

Bureaucrat::~Bureaucrat()
{
	this->print("deleted", 1);
}

// Operators
Bureaucrat const	&Bureaucrat::operator=(Bureaucrat const &copy)
{
	this->_grade = copy.getGrade();
	this->print("created by assignment", 2);
	return (*this);
}

// Methods
void Bureaucrat::incrementGrade(void)
{
	this->_grade--;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->print("", 3);
	std::cout << "[+1] new grade : " << this->_grade << std::endl;
}

void Bureaucrat::incrementGrade(int value)
{
	this->_grade -= value;
	if (this->_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->print("", 3);
	std::cout << "[+" << value << "] new grade : " << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade(void)
{
	this->_grade++;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());;
	this->print("", 3);
	std::cout << "[-1] new grade : " << this->_grade << std::endl;
}

void Bureaucrat::decrementGrade(int value)
{
	this->_grade += value;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooLowException());;
	this->print("", 3);
	std::cout << "[-" << value << "] new grade : " << this->_grade << std::endl;
}

// Getters and Setters
std::string const &Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// Exceptions
char const *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("\e[31m[ERROR]\e[0m Grade too high!");
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("\e[31m[ERROR]\e[0m Grade too low!");
}

std::ostream &operator<<(std::ostream &stream, Bureaucrat const &bureaucrat)
{
	return (stream << "\e[033m[Bureaucrat " << bureaucrat.getName() << "]\e[0m (grade=" << bureaucrat.getGrade() << ")");
}
