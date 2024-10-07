/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:50:15 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/15 12:52:47 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <limits>

bool	isValidInteger(const char* str);
int		parseInput(int argc, char **argv, std::vector<int> &array, std::list<int> &list);
double	getTimeVector(std::vector<int> &array);
double	getTimeList(std::list<int> &list);
void	displayOutput(std::vector<int> &array, std::list<int> &list, double durationVector, double durationList);
