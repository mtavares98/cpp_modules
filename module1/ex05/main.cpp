/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:25:40 by mtavares          #+#    #+#             */
/*   Updated: 2023/02/13 18:30:37 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
    Harl comp;

    comp.complain("DEBUG");
    comp.complain("INFO");
    comp.complain("WARNING");
    comp.complain("ERROR");
    comp.complain("A toa");
}
