/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:38:50 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/13 18:02:16 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void copyContent(std::fstream &inFile, std::fstream &outFile, const std::string &replace, const std::string &copy) {
    size_t position;
    std::string content;

    while (getline(inFile, content)) {
        position = 0;
        while (1) {
            position = content.find(replace, position);
            if (position == std::string::npos)
                break ;
            content.erase(position, replace.length());
            content.insert(position, copy);
            position += copy.length();
        }
        outFile << content << '\n';
    }
}

int error(std::string str) {
    std::cout << str << std::endl;
    return 1;
}

int main(int ac, char **av) {
    std::fstream inFile;
    std::fstream outFile;
    std::string outFileName;

    if (ac != 4)
        return error("Wrong number of arguments");
    if (!av[2][0] || !av[3][0])
        return error("Strings must not be empty");
    if (!((std::string)av[2]).compare(av[3]))
        return error("The strings must not be equal");
    inFile.open(av[1], std::ios::in);
    if (!inFile.is_open())
        return error("Error with open inFile");
    outFileName = av[1];
    outFileName += ".replace";
    outFile.open(outFileName.c_str(), std::ios::out | std::ios::trunc);
    if (!outFile.is_open()) {
        inFile.close();
        return error("Error with open outFile");
    }
    copyContent(inFile, outFile, (const std::string)av[2], (const std::string)av[3]);
    inFile.close();
    outFile.close();
}
