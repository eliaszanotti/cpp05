/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/06/05 17:01:58 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_H
# define FORM_CLASS_H

# include <iostream>
# include "Bureaucrat.class.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	const	_name;
		bool	_isSigned;
		int const	_signingGrade;
		int const	_executeGrade;
		// Print
		void	print(std::string const &str, int color) const;

	public:
		// Constructors
		Form();
		Form(std::string const &name, int const signingGrade, int const executeGrade);
		Form(Form const &copy);
		~Form();

		// Operators
		Form const	&operator=(Form const &copy);

		// Methods
		void	beSigned(Bureaucrat const &bureaucrat);
		
		// Getters and Setters
		std::string	const	&getName(void) const;
		bool	getIsSigned(void) const;
		int const	&getSigningGrade(void) const;
		int const	&getExecuteGrade(void) const;

		// Exceptions
		class GradeTooHighException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, Form const &form);

#endif