/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.class.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/06/12 14:36:18 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_CLASS_H
# define SHRUBBERYCREATIONFORM_CLASS_H

# include <iostream>
# include "Bureaucrat.class.hpp"
# include "Form.class.hpp"

class ShrubberyCreationForm: public Form
{
	private:
		std::string	_target;
		// Print
		void	print(std::string const &str, int color) const;

	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm();

		// Operators
		ShrubberyCreationForm const	&operator=(ShrubberyCreationForm const &copy);

		// Methods
		void	beExecuted(Bureaucrat const &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &stream, ShrubberyCreationForm const &form);

#endif