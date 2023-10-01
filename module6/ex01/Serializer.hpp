/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:36:14 by mtavares          #+#    #+#             */
/*   Updated: 2023/08/26 15:43:57 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

#include "Data.hpp"

class Serializer
{
    private:
        Serializer(void);
        Serializer(const Serializer &copy);
    public:
        static uintptr_t  serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
        Serializer &operator=(const Serializer &copy);
        ~Serializer();
};
#endif
