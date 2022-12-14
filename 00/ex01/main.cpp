/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:47:46 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/14 02:17:20 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook pb = PhoneBook();
	std::string s;

	while (1)
	{
		std::cout << "Commands available: add, search or exit\n";
		std::cin >> s;
		if (s == "add")
			pb.ADD();
		else if (s == "search")
			pb.SEARCH();
		else if (s == "exit")
			return (0);
		else
			std::cout << "Enter add or search or exit\n";
	}
}
