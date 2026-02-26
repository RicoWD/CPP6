/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:19:30 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/26 21:07:34 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>

class Data
{
	private:
		std::string	_name;
		double		_value;
	
	public:
		// OCF
		Data(): _name("Unkmow item"), _value(0) {}
		Data(std::string name, double value): _name(name), _value(value) {}
		Data(const Data& cpy): _name(cpy._name), _value(cpy._value) {};
		Data& operator=(const Data& cpy);
		~Data() {};

		// Getters
		std::string getName() const { return (_name); };
		double		getValue() const { return (_value); };
};
