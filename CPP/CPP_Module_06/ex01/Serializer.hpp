/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:53:59 by jdenis            #+#    #+#             */
/*   Updated: 2024/05/14 13:54:03 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <stdint.h>

#include "Data.hpp"

class Serializer
{

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
		

	private:
		Serializer();
		Serializer(Serializer const & src);
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );
};
