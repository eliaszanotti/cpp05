/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.class.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/08 13:32:25 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_CLASS_H
# define ROBOTOMYREQUESTFORM_CLASS_H

# include <iostream>
# include "Bureaucrat.class.hpp"
# include "AForm.class.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;
		// Print
		void	print(std::string const &str, int color) const;

	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm();

		// Operators
		RobotomyRequestForm const	&operator=(RobotomyRequestForm const &copy);

		// Methods
		void	beExecuted(Bureaucrat const &bureaucrat) const;
};

std::ostream	&operator<<(std::ostream &stream, RobotomyRequestForm const &form);

#endif