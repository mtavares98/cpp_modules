/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 00:03:06 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/24 02:28:03 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	copying_content(std::ifstream &infile, std::ofstream &outfile, const std::string &search, const std::string &replace)
{
	size_t	pos;
	std::string	content;

	while (std::getline(infile, content))
	{
		pos = 0;
		while (1)
		{
			pos = content.find(search, pos);
			if (pos == std::string::npos)
				return ;
			content.erase(pos, search.length());
			content.insert(pos, replace);
		}
		outfile << content << '\n';
	}
}

int	error(std::string error, int code)
{
	if (code)
		std::cout << error;
	return (1);
}

int	main(int ac, char **av)
{
	std::string	inFileName;
	std::string	outFileName;
	std::ifstream	infile;
	std::ofstream	outfile;
	if (ac != 4)
		return (error("You should have ./sedIsForLosers fileName stringForReplace stringToReplace\n", 1));
	if (av[2][0] == '\0' || av[3][0] == '\0')
		return (error("Your strings must not be empty\n", 1));
	if (!((const std::string)av[2]).compare(av[3]))
		return (error("Your first string is the same as the second one\n", 1));
	inFileName = av[1];
	outFileName = inFileName + ".replace";
	infile.open(inFileName.c_str(), std::ios::in);
	if (!infile.is_open())
		return (error("Your infile doesn't exist\n", 1));
	outfile.open(outFileName.c_str(), std::ios::out | std::ios::trunc);
	if (!outfile.is_open())
		return (error("The outfile is not created", 1));
	copying_content(infile, outfile, (const std::string)av[2], (const std::string)av[3]);
	infile.close();
	outfile.close();
}
