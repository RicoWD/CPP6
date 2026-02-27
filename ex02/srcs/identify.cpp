/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 02:23:24 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/27 02:37:18 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify(Base* p)
{	
	if (dynamic_cast<A*>(p))
		std::cout << "A is identified\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B is identified\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C is identified\n";
	else
		std::cout << "Unknown type\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A is identified\n";
		return;
	}
	catch (const std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B is identified\n";
		return;
	}
	catch (const std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C is identified\n";
		return;
	}
	catch (const std::bad_cast&) {}

	std::cout << "Unknown type\n";
}
