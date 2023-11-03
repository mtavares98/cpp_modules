/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:03:33 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/02 16:14:54 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.hpp"

bool months31(int month) {
  int result[7] = {1, 3, 5, 7, 8, 10, 12};

  for (int i = 0; i < 7; i++) {
    if (month == result[i]) return true;
  }
  return false;
}

bool months30(int month) {
  int result[4] = {4, 6, 9, 11};

  for (int i = 0; i < 4; i++) {
    if (month == result[i]) return true;
  }
  return false;
}

bool leapYear(int year) {
  return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
