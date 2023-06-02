/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/06/02 15:13:46 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_H
# define FORM_CLASS_H

# include <iostream>
# include "Bureaucrat.class.hpp"

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
		Form(Form const &copy);
		~Form();

		// Operators
		Form const	&operator=(Form const &copy);

		// Methods
		void	beSigned(Bureaucrat const &bureaucrat) const;
		
		// Getters and Setters
		std::string	&getName(void) const;
		bool const	&getIsSigned(void) const;
		int const	&getSigningGrade(void) const;
		int const	&getExecuteGrade(void) const;

};

#endif