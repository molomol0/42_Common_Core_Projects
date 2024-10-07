/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:25:22 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/17 18:05:04 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) 
{
    std::vector<int> array;
    std::list<int> list;

    if (argc < 2) 
    {
        std::cout << "Usage : ./PmergeMe <numbers>" << std::endl;
        return 1;
    }

    if (parseInput(argc, argv, array, list) == -1)
    {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    std::cout << "Before: ";
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) 
        std::cout << *it << " ";
    std::cout << std::endl;

    double durationVector = getTimeVector(array);
    double durationList = getTimeList(list);

    displayOutput(array, list, durationVector, durationList);

    return 0;
}
