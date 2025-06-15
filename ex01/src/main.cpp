/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:06:45 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/15 14:31:54 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main(void)
{
	Data real;
	uintptr_t uintptr = Serializer::serialize(&real);
	Data *Dptr = Serializer::deserialize(uintptr);

	std::cout <<"real addr :"<< &real << "\ndata ptr :" << Dptr << std::endl;

	return 0;
}
