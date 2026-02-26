/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:31:56 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/26 21:18:44 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

// The rest of the canonical form has been implemented directly on Data.hpp

Data& Data::operator=(const Data& cpy)
{
	if (this != &cpy)
	{
		_name = cpy._name;
		_value = cpy._value;
	}
	return (*this);
}
