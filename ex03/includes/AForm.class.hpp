/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/08 13:31:07 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_CLASS_H
# define AFORM_CLASS_H

# include <iostream>
# include "Bureaucrat.class.hpp"

class Bureaucrat;

class AForm
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
		AForm();
		AForm(std::string const &name, int const signingGrade, int const executeGrade);
		AForm(AForm const &copy);
		virtual ~AForm();

		// Operators
		AForm const	&operator=(AForm const &copy);

		// Methods
		void	beSigned(Bureaucrat const &bureaucrat);
		void	execute(Bureaucrat const &executor) const;
		virtual void	beExecuted(Bureaucrat const &bureaucrat) const = 0;
		
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
		class AFormNotSigned: public std::exception
		{
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &stream, AForm const &Aform);

#endif