/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 20:05:39 by mtavares          #+#    #+#             */
/*   Updated: 2023/06/27 20:05:42 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void) {
   std::cout << "\033[0;36m>>>>> Testing Bureaucrats <<<<<\033[0m" << std::endl;
    std::cout << "\033[0;32m>>> Testing initialization <<<\033[0m" << std::endl;
    try { Bureaucrat b("John", 4); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Bureaucrat b("Jack", 150); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Bureaucrat b("James", 1); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Bureaucrat b("Jeremy", 0); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Bureaucrat b("Jonas", 4); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Bureaucrat b("Clint", -1); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Bureaucrat b("Mary", 151); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    std::cout << "\033[0;32m>>> Testing promotion/demotion <<<\033[0m" << std::endl;

    Bureaucrat a("Subject A", 1);
    std::cout << a << std::endl;
    a.decrementGrade();
    std::cout << a << std::endl;
    a.decrementGrade();
    std::cout << a << std::endl;
    a.incrementGrade();
    a.incrementGrade();
    std::cout << a << std::endl;
    try { a.incrementGrade(); }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    std::cout << a << std::endl;

    std::cout << std::endl;

    Bureaucrat b("Subject B", 150);
    std::cout << b << std::endl;
    b.incrementGrade();
    std::cout << b << std::endl;
    b.incrementGrade();
    std::cout << b << std::endl;
    b.decrementGrade();
    b.decrementGrade();
    std::cout << b << std::endl;
    try { b.decrementGrade(); }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    std::cout << b << std::endl;

    std::cout << "\033[0;32m>>> Testing using copy constructor <<<\033[0m" << std::endl;
    Bureaucrat c(a);
    std::cout << c << std::endl;
    c.decrementGrade();
    std::cout << a << "; " << c << std::endl;
    Bureaucrat d(b);
    std::cout << d << std::endl;
    d.incrementGrade();
    std::cout << b << "; " << d << std::endl;

    std::cout << "\033[0;36m>>>>> Testing Forms <<<<<\033[0m" << std::endl;
    std::cout << "\033[0;32m>>> Testing initialization <<<\033[0m" << std::endl;
    try { Form b("Forestry", 4, 6); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Form b("Baseball", 150, 5); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Form b("Impersonation", 0, 4); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Form b("Car insurance", 1, 3); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Form b("Medical", 151, 2); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Form b("Building", -1, 1); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Form b("Building", 1, -5); std::cout << b << std::endl; }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    {
        Form a("Building", 1, 5);
        Form b(a);
        std::cout << b << std::endl;
    }
    std::cout << "\033[0;32m>>> Testing signing <<<\033[0m" << std::endl;
    Bureaucrat johnny("Johnny", 75);
    try { Form f("test1", 80, 20); johnny.signForm(f); }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Form f("test2", 75, 20); johnny.signForm(f); }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Form f("test3", 54, 20); johnny.signForm(f); }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
    try { Form f("test4", 20, 20); johnny.signForm(f); }
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
}
