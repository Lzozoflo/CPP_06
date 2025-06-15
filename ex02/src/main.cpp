/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:06:45 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/15 16:22:05 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(time(NULL));
	switch (rand() % 4)
	{
		case 0:
			std::cout << "Create new A class" << std::endl;
			return (new A);
			break;
		case 1:
			std::cout << "Create new B class" << std::endl;
			return (new B);
			break;
		case 2:
			std::cout << "Create new C class" << std::endl;
			return (new C);
			break;
		default:
			std::cout << "Create new Base class" << std::endl;
			return (new Base);
			break;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Its A Class ptr" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Its B Class ptr" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Its C Class ptr" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Its A Class ref" << std::endl;
		(void)a;
		return ;
	}
	catch(const std::exception& e)
	{}

	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Its B Class ref" << std::endl;
		(void)b;
		return ;
	}
	catch(const std::exception& e)
	{}

	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "Its C Class ref" << std::endl;
		(void)c;
		return ;
	}
	catch(const std::exception& e)
	{}


	// try
	// {
	// 	A &a = dynamic_cast<A&>(p);
	// 	std::cout << "Its A Class ref" << std::endl;
	// 	(void)a;
	// }
	// catch(const std::exception& e)
	// {
	// 	try
	// 	{
	// 		B &b = dynamic_cast<B&>(p);
	// 		std::cout << "Its B Class ref" << std::endl;
	// 		(void)b;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		try
	// 		{
	// 			C &c = dynamic_cast<C&>(p);
	// 			std::cout << "Its C Class ref" << std::endl;
	// 			(void)c;
	// 		}
	// 		catch(const std::exception& e)
	// 		{
	// 		}
	// 	}
	// }

	(void)p;
}

int main(void)
{
	// Base *classs = new A;
	// Base *classs = new B;
	// Base *classs = new C;
	Base *classs = generate();
	identify(classs);
	identify(*classs);
	delete classs;
	return 0;
}
