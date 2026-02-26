/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:48:41 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/26 21:28:37 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/Serializer.hpp>

int main()
{
	// Init
	Data item1("Banana", 1.99);
	
	std::cout	<< "=== Original ===\n"
				<< "Address: "	<< &item1 << "\n"
				<< "Name: "		<< item1.getName() << "\n"
				<< "Value: "	<< item1.getValue() << "\n\n";
	
	// Serializer
	uintptr_t serialized = Serializer::serialize(&item1);
	std::cout << "=== Serialized ===\n";
	std::cout << "Serialized value: " << serialized << "\n\n";
	
	// Deserialiser
	Data* deserialized = Serializer::deserialize(serialized);
	
	std::cout	<< "=== Deserialized ===\n"
				<< "Address: "	<< deserialized << "\n"
				<< "Name: "		<< deserialized->getName() << "\n"
				<< "Value: "	<< deserialized->getValue() << "\n\n";
	
	// Adress check
	if (deserialized == &item1)
		std::cout << "Success: Pointers match!\n";
	else
		std::cout << "Error: Pointers don't match!\n";
	
	return 0;
}
