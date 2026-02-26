/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:57:27 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/26 21:16:55 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stdint.h>
# include "Data.hpp"

class Data;

class Serializer
{
	private:
		Serializer() {};
		Serializer(const Serializer& cpy) { (void)cpy; };
		Serializer& operator=(const Serializer& cpy) { (void)cpy; return (*this); };
		~Serializer() {};

	public:
		static uintptr_t serialize(Data* ptr) { return (reinterpret_cast<uintptr_t>(ptr)); };
		static Data* deserialize(uintptr_t raw) { return (reinterpret_cast<Data*>(raw)); };
};