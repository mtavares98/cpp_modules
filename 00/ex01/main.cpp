/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 03:47:46 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/10 22:09:51 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main(int ac, char **av)
{
	PhoneBook pb = PhoneBook();
	std::string s;

	while (1)
	{
		std::cin >> s;
		std::cout << s << '\n';
		if (s == "add")
			pb.ADD();
		else if (s == "search")
			pb.SEARCH();
		else if (s == "exit")
			pb.EXIT();
	}
}
