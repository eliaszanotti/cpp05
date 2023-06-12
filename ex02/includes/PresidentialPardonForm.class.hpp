/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/06/12 13:56:20 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_CLASS_H
# define PRESIDENTIALPARDONFORM_CLASS_H

# include <iostream>
# include "Bureaucrat.class.hpp"
# include "Form.class.hpp"

class PresidentialPardonForm: public Form
{
	private:
		std::string	_target;
		// Print
		void	print(std::string const &str, int color) const;

	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm();

		// Operators
		PresidentialPardonForm const	&operator=(PresidentialPardonForm const &copy);

		// Methods
		void	beExecuted(Bureaucrat const &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &stream, PresidentialPardonForm const &form);

#endif