/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:57:27 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/26 18:12:24 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iomanip>
# include <string>
# include <cstdint>
# include <iostream>

struct Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& cpy);
		Serializer& operator=(const Serializer& cpy);
		~Serializer();

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};