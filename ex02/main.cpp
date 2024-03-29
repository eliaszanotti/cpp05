/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:01:52 by elias             #+#    #+#             */
/*   Updated: 2023/09/08 13:32:45 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.class.hpp"
#include "AForm.class.hpp"
#include "ShrubberyCreationForm.class.hpp"
#include "RobotomyRequestForm.class.hpp"
#include "PresidentialPardonForm.class.hpp"

int main(void)
{
    std::cout << "--- Test with too high grade ---" << std::endl;
    {
        try
        {
            Bureaucrat  cadre("cadre", 10);
            std::cout << cadre << std::endl;
            cadre.incrementGrade();
            std::cout << cadre << std::endl;
            cadre.decrementGrade(10);
            cadre.decrementGrade();
            cadre.incrementGrade(20);
            cadre.decrementGrade();
            cadre.incrementGrade();
        }
        catch (std::exception &error)
        {
            std::cerr << error.what() << std::endl;
        }
    }
    std::cout << "\n--- Test with too low grade ---" << std::endl;
    {
        try
        {
            Bureaucrat  cadre("cadre", 140);
            cadre.incrementGrade();
            cadre.decrementGrade(15);
            cadre.decrementGrade();
            cadre.incrementGrade(20);
            cadre.decrementGrade();
            cadre.incrementGrade();
        }
        catch (std::exception &error)
        {
            std::cerr << error.what() << std::endl;
        }
    }
    std::cout << "\n--- Test with new form ---" << std::endl;
    {
        try
        {
    	    ShrubberyCreationForm tree("amazonia");
            RobotomyRequestForm robot("terminator");
            PresidentialPardonForm president("sarko");
            Bureaucrat mike("Mike", 30);
        
			std::cout << mike << std::endl;
			std::cout << tree << std::endl;
            mike.signForm(tree);
            mike.signForm(robot);
            mike.signForm(president);
			mike.executeForm(tree);
            mike.executeForm(robot);
            mike.executeForm(president);
        }
        catch (std::exception &error)
        {
            std::cerr << error.what() << std::endl;   
        }
    }
    return (0);
}