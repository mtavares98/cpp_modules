/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:07:12 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/19 22:25:25 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string	s = "HI THIS IS BRAIN";
	std::string	*pS = &s;
	std::string	&rS	= s;

	(void)rS;
	std::cout << "Address of memory\n";
	std::cout << "Pointer:   " << pS << '\n';
	std::cout << "Reference: "<< &pS << '\n';
	std::cout << "String:    " << &s << "\n";
	std::cout << "Value of string\n";
	std::cout << "pointer:   " << *pS << '\n';
	std::cout << "Reference: " << rS << '\n';
	std::cout << "String:    " << s << "\n";

}
