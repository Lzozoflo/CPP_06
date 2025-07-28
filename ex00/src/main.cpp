/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:06:45 by fcretin           #+#    #+#             */
/*   Updated: 2025/07/28 14:26:53 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>


#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	std::string str = av[1];
	ScalarConverter::convert(str);

	return 0;
}

// int main(void)
// {
// 	std::string str = "a";
// 	std::stringstream iss(str.c_str());

// 	int nb;

// 	iss >> nb;
// 	if (!iss.fail() && iss.eof())
// 	{
// 		std::cout << "ok !\n";
// 	}
// 	else
// 		std::cout << "not an int\n";


// }
