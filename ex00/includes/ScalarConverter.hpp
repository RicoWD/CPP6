/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:44:18 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/27 04:22:00 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <climits>
# include <iomanip>
# include <iostream>
# include <limits>
# include <stdexcept>
# include <string>
# include <cmath>
# include <sstream>

# define RESET		"\033[0m"
# define GREEN		"\033[32m"
# define RED		"\033[31m"
# define GREY		"\033[90m"
# define BOLDGREEN	"\033[1m\033[32m"
# define BOLDRED	"\033[1m\033[31m"
# define BOLDYELLOW	"\033[1m\033[33m"

class ScalarConverter
{
	private:
		// OCF (non instantiable)
		ScalarConverter();
		ScalarConverter(const ScalarConverter &cpy);
		ScalarConverter &operator=(const ScalarConverter &cpy);
		~ScalarConverter();
	
	public:
		static void convert(std::string input);
};

// Idenification functions
int isChar(std::string input);
int isInt(std::string input);
int isFloat(std::string input);
int isDouble(std::string input);

// Print functions
void printImpossible();
void printSpecial(std::string input);
void printChar(char c);
void printInt(int n);
void printFloat(float f);
void printDouble(double d);
