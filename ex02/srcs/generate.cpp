/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 02:30:08 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/27 04:15:36 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
	int random = rand() % 3;
	
	switch (random)
	{
		case 0:
			std::cout << "Generating instance of A\n";
			return new A();
		case 1:
			std::cout << "Generating instance of B\n";
			return new B();
		case 2:
			std::cout << "Generating instance of C\n";
			return new C();
		default:
			return NULL;			
	}
}
