/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:01:52 by elias             #+#    #+#             */
/*   Updated: 2023/09/07 18:03:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"
#include "Intern.class.hpp"

int main(void)
{
    std::cout << "--- Test with Interns (don't work) ---" << std::endl;
    {
        Intern  newIntern;
        Form    *robotomyForm;

        robotomyForm = newIntern.makeForm("robotomy", "Elias");
        delete (robotomyForm);
    }
    std::cout << "\n--- Test with Interns (work) ---" << std::endl;
    {
        Intern  newIntern;
        Form    *robotomyForm;

        robotomyForm = newIntern.makeForm("robotomy request", "Elias");
        delete (robotomyForm);
    }
    return (0);
}