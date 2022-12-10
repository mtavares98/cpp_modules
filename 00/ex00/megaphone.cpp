/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 02:00:53 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/10 02:04:46 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string s;

	for(int i = 1; i < ac; i++) {
		s = av[i];
		for(int j = 0; j < s.length(); j++) {
			std::cout << (char)std::toupper(s[j]);
		}
	}
	std::cout << '\n';
}
