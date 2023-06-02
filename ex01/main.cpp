/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:01:52 by elias             #+#    #+#             */
/*   Updated: 2023/06/02 15:52:25 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.class.hpp"
#include "Form.class.hpp"

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
            std::cout << error.what() << std::endl;
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
            std::cout << error.what() << std::endl;
        }
    }
    std::cout << "\n--- Test with wrong value ---" << std::endl;
    {
        try
        {
            Bureaucrat  cadre("cadre", 160);
            cadre.incrementGrade();
        }
        catch (std::exception &error)
        {
            std::cout << error.what() << std::endl;
        }
    }
    return (0);
}