/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/06/02 13:06:46 by elias            ###   ########.fr       */
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
Bureaucrat::Bureaucrat()
{
	this->print("created", 2);
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	this->print("created by copy", 2);
}

Bureaucrat::~Bureaucrat()
{
	this->print("deleted", 1);
}

// Operators
Bureaucrat const	&Bureaucrat::operator=(Bureaucrat const &copy)
{
	this->print("created by assignment", 2);
}

// Methods

// Getters and Setters
std::string const &Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}
