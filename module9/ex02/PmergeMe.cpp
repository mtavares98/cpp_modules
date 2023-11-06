/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 01:09:26 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/06 15:38:51 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <sched.h>
#include <sys/time.h>

#include <algorithm>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <stdexcept>
#include <utility>
#include <vector>

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(int ac, char **av) {
  int last;
  bool isOdd = false;
  char *endptr = NULL;
  std::vector<std::pair<unsigned, unsigned> > contV;
  std::deque<std::pair<unsigned, unsigned> > contL;

  if (ac % 2 == 0) {
    last = strtol(av[ac - 2], &endptr, 10);
    if (errno || *endptr || last < 0 || last > INT_MAX)
      throw std::runtime_error("Error");
    ac -= 1;
    isOdd = true;
  }
  // Printar Before
  std::cout << "Before:";
  // Create a vector and linked list to sort with pair
  for (int i = 1; i < ac; i++) {
    int tmp1, tmp2;

    tmp1 = strtol(av[i++], &endptr, 10);
    if (errno || *endptr || tmp1 < 0 || tmp1 > INT_MAX)
      throw std::runtime_error("Error");
    tmp2 = strtol(av[i], &endptr, 10);
    if (errno || *endptr || tmp2 < 0 || tmp2 > INT_MAX)
      throw std::runtime_error("Error");
    contV.push_back(std::make_pair(tmp1, tmp2));
    contL.push_back(std::make_pair(tmp1, tmp2));
    std::cout << " " << tmp1 << " " << tmp2;
  }
  if (isOdd) std::cout << " " << av[ac];
  std::cout << std::endl;
  // Algoritmo
  executor(contV, contL, last, isOdd);
  // Printar Ordenado
  std::cout << "After:";
  for (std::deque<unsigned>::iterator begin = this->_list.begin();
       begin != this->_list.end(); begin++) {
    std::cout << " " << *begin;
  }
  std::cout << std::endl;
  std::cout << "Time to process a range of " << this->_arr.size()
            << " elements with std::vector : " << this->_arrTime << " us"
            << std::endl;
  std::cout << "Time to process a range of " << this->_arr.size()
            << " elements with std::deque : " << this->_listTime << " us"
            << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &copy) : _arr(copy._arr), _list(copy._list) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &copy) {
  this->_arr = copy._arr;
  this->_list = copy._list;
  return *this;
}

PmergeMe::~PmergeMe(void) {}

void PmergeMe::executor(std::vector<std::pair<unsigned, unsigned> > contV,
                        std::deque<std::pair<unsigned, unsigned> > contL,
                        unsigned last, bool isOdd) {
  timeval time;
  long double start = 0, end = 0;

  // This is vector ordenation
  gettimeofday(&time, NULL);
  start += static_cast<long double>(time.tv_sec) * 1000;
  start += static_cast<long double>(time.tv_usec) / 1000;
  mergeInsertSortVector(contV, last, isOdd);
  gettimeofday(&time, NULL);
  end += static_cast<long double>(time.tv_sec) * 1000;
  end += static_cast<long double>(time.tv_usec) / 1000;
  this->_arrTime = end - start;
  // This is for linked list
  gettimeofday(&time, NULL);
  start += static_cast<long double>(time.tv_sec) * 1000;
  start += static_cast<long double>(time.tv_usec) / 1000;
  mergeInsertSortList(contL, last, isOdd);
  gettimeofday(&time, NULL);
  end += static_cast<long double>(time.tv_sec) * 1000;
  end += static_cast<long double>(time.tv_usec) / 1000;
  this->_listTime = end - start;
}

void PmergeMe::mergeInsertSortVector(
    std::vector<std::pair<unsigned, unsigned> > &contV, unsigned last,
    bool isOdd) {
  std::vector<unsigned> tmp;

  // Organize pairs and insert into the vector
  for (std::vector<std::pair<unsigned, unsigned> >::iterator begin =
           contV.begin();
       begin != contV.end(); begin++) {
    if (begin->first > begin->second) std::swap(begin->first, begin->second);
    tmp.push_back(begin->second);
  }
  // Merge sort
  this->_arr = mergeSortVector(tmp);
  // Insertion Sort com os que faltam
  for (; contV.size() > 0;) {
    std::vector<unsigned>::iterator index = this->_arr.begin();
    index = binarySearchVector(index, contV.back().first, 0, this->_arr.size());
    this->_arr.insert(index, contV.back().first);
    contV.pop_back();
  }
  // Insert the last element of the container in the right place
  if (isOdd)
    this->_arr.insert(
        std::lower_bound(this->_arr.begin(), this->_arr.end(), last), last);
}
std::vector<unsigned> PmergeMe::mergeSortVector(std::vector<unsigned> vector) {
  std::vector<unsigned> half1, half2;
  std::vector<unsigned>::iterator begin;
  int start = 0, end = vector.size(), half = (start + end) / 2, i = 0;

  if (vector.size() <= 1) return vector;
  begin = vector.begin();
  for (; i < half; i++) {
    half1.push_back(*begin);
    begin++;
  }
  for (; i < static_cast<int>(vector.size()); i++) {
    half2.push_back(*begin);
    begin++;
  }
  half1 = mergeSortVector(half1);
  half2 = mergeSortVector(half2);
  return mergeVector(half1, half2);
}

std::vector<unsigned> PmergeMe::mergeVector(std::vector<unsigned> half1,
                                            std::vector<unsigned> half2) {
  std::vector<unsigned> res;

  for (; half1.size() > 0 || half2.size() > 0;) {
    if (half1.size() <= 0) {
      res.push_back(half2[0]);
      half2.erase(half2.begin());
    } else if (half2.size() <= 0) {
      res.push_back(half1[0]);
      half1.erase(half1.begin());
    } else if (half1.back() > half2[0]) {
      res.push_back(half2[0]);
      half2.erase(half2.begin());
    } else {
      res.push_back(half1[0]);
      half1.erase(half1.begin());
    }
  }
  return res;
}

std::vector<unsigned>::iterator PmergeMe::binarySearchVector(
    std::vector<unsigned>::iterator begin, unsigned &value, int low, int high) {
  if (low > high) return begin += low;

  int mid = low + (high - low) / 2;

  if (this->_arr[mid] >= value)
    return binarySearchVector(begin, value, low, mid - 1);
  return binarySearchVector(begin, value, mid + 1, high);
}

void PmergeMe::mergeInsertSortList(
    std::deque<std::pair<unsigned, unsigned> > &contL, unsigned last,
    bool isOdd) {
  std::deque<unsigned> tmp;

  for (std::deque<std::pair<unsigned, unsigned> >::iterator begin =
           contL.begin();
       begin != contL.end(); begin++) {
    if (begin->first > begin->second) std::swap(begin->first, begin->second);
    tmp.push_front(begin->second);
  }
  this->_list = mergeSortList(tmp);
  for (; contL.size() > 0;) {
    this->_list.insert(std::lower_bound(this->_list.begin(), this->_list.end(),
                                        contL[0].first),
                       contL[0].first);
    contL.pop_front();
  }
  if (isOdd)
    this->_list.insert(
        std::lower_bound(this->_list.begin(), this->_list.end(), last), last);
}

std::deque<unsigned> PmergeMe::mergeSortList(std::deque<unsigned> list) {
  std::deque<unsigned> half1, half2;
  std::deque<unsigned>::iterator begin;
  int start = 0, end = list.size(), half = (end + start) / 2, i = 0;

  if (list.size() <= 1) return list;
  // Copy the used items in the array
  begin = list.begin();
  for (; i < half; i++) {
    half1.push_back(*begin);
    begin++;
  }
  for (; i < static_cast<int>(list.size()); i++) {
    half2.push_back(*begin);
    begin++;
  }
  half1 = mergeSortList(half1);
  half2 = mergeSortList(half2);
  return mergeList(half1, half2);
}

std::deque<unsigned> PmergeMe::mergeList(std::deque<unsigned> half1,
                                         std::deque<unsigned> half2) {
  std::deque<unsigned> res;

  for (; half1.size() > 0 || half2.size() > 0;) {
    if (half1.size() <= 0) {
      res.push_back(half2.front());
      half2.pop_front();
    } else if (half2.size() <= 0) {
      res.push_back(half1.front());
      half1.pop_front();
    } else if (half1.front() > half2.front()) {
      res.push_back(half2.front());
      half2.pop_front();
    } else {
      res.push_back(half1.front());
      half1.pop_front();
    }
  }
  return res;
}

std::deque<unsigned>::iterator PmergeMe::binarySearchList(
    std::deque<unsigned>::iterator begin, unsigned &value, int low, int high) {
  if (low > high) return begin += low;

  int mid = low + (high - low) / 2;

  if (this->_arr[mid] >= value)
    return binarySearchList(begin, value, low, mid - 1);
  return binarySearchList(begin, value, mid + 1, high);
}
