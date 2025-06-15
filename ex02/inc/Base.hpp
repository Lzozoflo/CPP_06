/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:27:31 by fcretin           #+#    #+#             */
/*   Updated: 2025/06/15 16:13:12 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <time.h>
#include <stdlib.h>


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN  "\033[32m"
#define BLUE  "\033[34m"
#define YELLOW "\033[33m"

class Base
{
	public:
	// {

		virtual ~Base( void );

		static Base * generate(void);
		static void identify(Base* p);
		static void identify(Base& p);
	// }
};


#endif
