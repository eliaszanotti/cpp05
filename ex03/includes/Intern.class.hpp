/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/07 17:18:01 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_H
# define INTERN_CLASS_H

# include <iostream>
# include "Form.class.hpp"

class Intern
{
	private:
		// Print
		void	print(std::string const &str, int color) const;

	public:
		// Constructors
		Intern();
		Intern(Intern const &copy);
		~Intern();

		// Operators
		Intern const	&operator=(Intern const &copy);

		// Methods
		Form	*makeForm(std::string const &formName, std::string const &formTarget) const;
};

#endif