/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:01:52 by elias             #+#    #+#             */
/*   Updated: 2023/06/02 14:01:20 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.class.hpp"

int main(void)
{
    Bureaucrat  cadre("cadre", 10);

    cadre.incrementGrade();
    cadre.incrementGrade();
    cadre.incrementGrade();
    cadre.incrementGrade();
    cadre.decrementGrade(10);
    cadre.decrementGrade();
    cadre.decrementGrade();
    cadre.incrementGrade();



    return (0);
}