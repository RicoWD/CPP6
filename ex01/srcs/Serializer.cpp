/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 03:45:00 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/27 04:32:15 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

/* ************************************************************************** */
// 																			  //
// 						   	ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& cpy)
{
	(void)cpy;
}

Serializer& Serializer::operator=(const Serializer& cpy)
{
	(void)cpy;
	return (*this);
}

Serializer::~Serializer() {}


/* ************************************************************************** */
// 																			  //
// 						   		EXTERNAL FUNCTIONS							  //
//																	 		  //
/* ************************************************************************** */

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
