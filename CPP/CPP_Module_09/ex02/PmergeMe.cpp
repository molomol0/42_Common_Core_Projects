/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:50:17 by jdenis            #+#    #+#             */
/*   Updated: 2024/06/18 16:12:15 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
void insert(Container& sorted, typename Container::value_type value) 
{
    typename Container::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

template <typename Container>
void fordJohnsonSort(Container& container) 
{
    size_t n = container.size();
    //si le container est vide ou contient un seul élément, on ne fait rien
    if (n <= 1) 
        return;

    typedef typename Container::value_type T;

    std::vector<std::pair<T, T> > pairs;
    typename Container::iterator it = container.begin();
    // //on crée des paires de valeurs
    while (it != container.end()) 
    {
        T first = *it;
        ++it;
        //si on a une deuxième valeur, on crée une paire
        if (it != container.end())
        {
            T second = *it;
            ++it;
            //on met la plus petite valeur en premier
            pairs.push_back(std::make_pair(std::min(first, second), std::max(first, second)));
        } 
        //sinon on met la même valeur deux fois
        else 
            pairs.push_back(std::make_pair(first, first));
    }

    //initialisation du container trié
    Container sorted;
    sorted.push_back(pairs[0].first);
    sorted.push_back(pairs[0].second);

    for (size_t i = 1; i < pairs.size(); ++i) 
    {
        T a = pairs[i].first;
        T b = pairs[i].second;

        //on insère les valeurs dans le container trié
        insert(sorted, a);
        //on insère la deuxième valeur si elle est différente de la première
        if (a != b)
            insert(sorted, b);
    }

    //on copie les valeurs triées dans le container initial
    std::copy(sorted.begin(), sorted.end(), container.begin());
}

bool isValidInteger(const char* str) 
{
    if (*str == '+') 
        ++str;
    if (!*str) 
        return false;

    while (*str) 
    {
        if (!std::isdigit(*str)) return false;
        ++str;
    }
    
    return true;
}

int    parseInput(int argc, char **argv, std::vector<int> &array, std::list<int> &list)
{
    int input;

    for (int i = 1; i < argc; i++)
    {
        if (isValidInteger(argv[i]) == false)
            return -1;
        else
        {
            input = std::atoi(argv[i]);
            if (find(array.begin(), array.end(), input) != array.end())
                return -1;
            array.push_back(input);
            list.push_back(input);
        }
    }
    return 0;
}

double getTimeVector(std::vector<int> &array)
{
    clock_t start = clock();
    fordJohnsonSort(array);
    clock_t end = clock();
    return (double(end - start) / CLOCKS_PER_SEC) * 1000000;
}

double getTimeList(std::list<int> &list)
{
    clock_t start = clock();
    fordJohnsonSort(list);
    clock_t end = clock();
    return (double(end - start) / CLOCKS_PER_SEC) * 1000000;
}

void displayOutput(std::vector<int> &array, std::list<int> &list, double durationVector, double durationList)
{
    std::cout << "After: ";
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) 
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << array.size() << " elements with std::vector : "<< durationVector << " microseconds" << std::endl;
    std::cout << "Time to process a range of " << list.size() << " elements with std::list : "<< durationList << " microseconds" << std::endl;
}
