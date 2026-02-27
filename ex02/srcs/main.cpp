/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 02:39:47 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/27 02:42:57 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	Base* test = generate();
	
	std::cout << "Identifying with pointer:\n";
	identify(test);
	
	std::cout << "Identifying with reference:\n";
	identify(*test);
	
	delete test;
	return 0;
}
