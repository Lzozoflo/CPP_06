/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:27:31 by fcretin           #+#    #+#             */
/*   Updated: 2025/04/26 14:36:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdint.h>


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN  "\033[32m"
#define BLUE  "\033[34m"
#define YELLOW "\033[33m"

struct Data
{
	int i;
};

class Serializer
{
	private:
	// {
		Serializer( void );										//Canonical
		Serializer( const Serializer &other );						//Canonical
		Serializer &operator=( const Serializer &other );			//Canonical
		~Serializer( void );									//Canonical
	// }
	public:
	// {

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	// }
};


#endif
