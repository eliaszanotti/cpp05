/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/07 18:03:59 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "Intern.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"

// Print
void Intern::print(std::string const &str, int color) const
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
		std::cout << colorsString << "[Intern] " << reset;
	else
		std::cout << colorsString << "[Intern] " << reset << str << std::endl;
}

// Constructors
Intern::Intern()
{
	this->print("created", 2);
}

Intern::Intern(Intern const &copy)
{
	*this = copy;
	this->print("created by copy", 2);
}

Intern::~Intern()
{
	this->print("deleted", 1);
}

// Operators
Intern const	&Intern::operator=(Intern const &copy)
{
	(void)copy;
	this->print("created by assignment", 2);
	return (*this);
}

// Methods
Form *Intern::makeForm(std::string const &formName, std::string const &formTarget) const
{
	int	formIndex = -1;

	std::string	formNames[] = {
        "presidential pardon",
		"robotomy request",
        "shrubbery creation"
    };
	Form	*forms[] = {
		new	PresidentialPardonForm(formTarget),
		new RobotomyRequestForm(formTarget),
		new ShrubberyCreationForm(formTarget)
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			this->print("create form: " + formName, 3);
			formIndex = i;
		}
		else
			delete (forms[i]);
	}
	if (formIndex != -1)
		return (forms[formIndex]);
	this->print("cannot create form: " + formName, 3);
	return (NULL);
}