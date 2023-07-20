/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:05:39 by mtavares          #+#    #+#             */
/*   Updated: 2023/06/12 20:28:14 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
   // GRADE TOO HIGH ON CONSTRUCTOR ===========================================
    try
    {
        Bureaucrat Francisco("Francisco", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    // GRADE TOO LOW ON CONSTRUCTOR ============================================
    try
    {
        Bureaucrat Lourenco("Lourenco", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    // Incrementing when at max grade ==========================================
    try
    {
        Bureaucrat Eugene("Eugene", 1);
        std::cout << Eugene;
        Eugene.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    // Decrementing when at min grade ==========================================
    try
    {
        Bureaucrat Antonio("Antonio", 150);
        std::cout << Antonio;
        Antonio.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    // Normal behavior =========================================================
    try
    {
        Bureaucrat Eu("Eu", 9);
        std::cout << Eu;
        Eu.incrementGrade();
        std::cout << Eu;
        Eu.decrementGrade();
        std::cout << Eu;
        for (int i = 0; i < 9; i++) {
            Eu.incrementGrade();
            std::cout << Eu;
        }
        Eu.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}
