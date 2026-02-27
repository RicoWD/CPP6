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
		Data();
		Data(std::string name, double value);
		Data(const Data& cpy);
		Data& operator=(const Data& cpy);
		~Data();

		// Getters
		std::string getName() const;
		double		getValue() const;
};
