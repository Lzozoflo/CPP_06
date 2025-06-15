/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:27:31 by fcretin           #+#    #+#             */
/*   Updated: 2025/04/26 14:36:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <iomanip>
#include <iostream>
#include <sstream>

#include <cstdlib>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN  "\033[32m"
#define BLUE  "\033[34m"
#define YELLOW "\033[33m"


class ScalarConverter
{
	private:
	// {
		ScalarConverter( void );									//Canonical
		ScalarConverter( const ScalarConverter &e );				//Canonical
		ScalarConverter &operator=( const ScalarConverter &e );		//Canonical
		~ScalarConverter( void );									//Canonical
	// }
	public:
	// {


		static void convert(std::string &toConvert);

	// }
};


#endif
