/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:29:58 by mtavares          #+#    #+#             */
/*   Updated: 2023/10/05 16:33:48 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void) {
    Data d1 = { "This string is for testing", 26 };
    Data *d2;
    uintptr_t ptr;

    std::cout << "d1: " << d1.data << ", len: " << d1.len << std::endl;
    ptr = Serializer::serialize(&d1);
    d2 = Serializer::deserialize(ptr);
    std::cout << "d2: " << d2->data << ", len: " << d2->len << std::endl;
}
