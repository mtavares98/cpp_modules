/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:09:00 by mtavares          #+#    #+#             */
/*   Updated: 2023/11/06 15:38:52 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <utility>
#include <vector>

class PmergeMe {
 private:
  std::vector<unsigned> _arr;
  std::deque<unsigned> _list;
  long double _arrTime;
  long double _listTime;
  PmergeMe(void);
  void executor(std::vector<std::pair<unsigned, unsigned> > contV,
                std::deque<std::pair<unsigned, unsigned> > contL, unsigned last,
                bool isOdd);
  void mergeInsertSortVector(std::vector<std::pair<unsigned, unsigned> > &contV,
                             unsigned last, bool isOdd);
  std::vector<unsigned> mergeSortVector(std::vector<unsigned> vector);
  std::vector<unsigned> mergeVector(std::vector<unsigned> half1,
                                    std::vector<unsigned> half2);
  std::vector<unsigned>::iterator binarySearchVector(
      std::vector<unsigned>::iterator begin, unsigned &value, int low,
      int high);
  void mergeInsertSortList(std::deque<std::pair<unsigned, unsigned> > &contL,
                           unsigned last, bool isOdd);
  std::deque<unsigned> mergeSortList(std::deque<unsigned> list);
  std::deque<unsigned> mergeList(std::deque<unsigned> half1,
                                 std::deque<unsigned> half2);
  std::deque<unsigned>::iterator binarySearchList(
      std::deque<unsigned>::iterator begin, unsigned &value, int low, int high);

 public:
  PmergeMe(int ac, char **av);
  PmergeMe(PmergeMe const &copy);
  PmergeMe &operator=(PmergeMe const &copy);
  ~PmergeMe(void);
};
#endif
