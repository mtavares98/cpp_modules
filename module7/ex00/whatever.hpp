/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:00:09 by mtavares          #+#    #+#             */
/*   Updated: 2023/08/27 20:03:00 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &a, T &b) {
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
const T &min(const T a, const T b) {
    return (a < b) ? a : b;
}

template <typename T>
const T &max(const T a, const T b) {
    return (a > b) ? a : b;
}

#endif
