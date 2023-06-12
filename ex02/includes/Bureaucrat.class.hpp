/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/06/12 12:09:19 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

# include <iostream>
# include "Form.class.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string	const	&_name;
		int	_grade;
		// Print
		void	print(std::string const &str, int color) const;

	public:
		// Constructors
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();

		// Operators
		Bureaucrat const	&operator=(Bureaucrat const &copy);

		// Methods
		void	incrementGrade(void);
		void	incrementGrade(int value);
		void	decrementGrade(void);
		void	decrementGrade(int value);
		void	signForm(Form &form);
		void	executeForm(Form const &form);

		// Getters and Setters 
		std::string	const	&getName(void) const;
		int	getGrade(void) const;

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

std::ostream	&operator<<(std::ostream &stream, Bureaucrat const &bureaucrat);

#endif