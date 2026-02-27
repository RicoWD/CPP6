/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:29:00 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/27 13:40:37 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

/* ************************************************************************** */
// 																			  //
// 						   	ORTHODOX CANONICAL FORM							  //
//																	 		  //
/* ************************************************************************** */


ScalarConverter::ScalarConverter() 
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)cpy;
	return *this;
}

ScalarConverter::~ScalarConverter() 
{
}

/* ************************************************************************** */
// 																			  //
// 						   			CONVERT									  //
//																	 		  //
/* ************************************************************************** */

void ScalarConverter::convert(std::string input)
{
	if (input.empty())
	{
		printImpossible();
		return ;
	}

	if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || input == "-inf" || input == "-inff")
	{
		// std::cout << BOLDYELLOW << "isSpecial: " << input << "\n" << RESET;
		printSpecial(input);
		return ;
	}
	
	if (isChar(input))
	{
		// std::cout << BOLDYELLOW << "isChar: " << input << "\n" << RESET;
		printChar(input[0]);
		return ;
	}

	if (isInt(input))
	{
		// std::cout << BOLDYELLOW << "isInt: " << input << "\n" << RESET;
		long value;
		std::istringstream ss(input);
		ss >> value;
		if (ss.fail())
		{
			std::cerr << "Error: Overflow detected for: " << input << "\n";
			printImpossible();
			return ;
		}
		char extra;
		if (ss >> extra || value < INT_MIN || value > INT_MAX)
		{
			std::cerr << "Error: Overflow detected for: " << input << "\n";
			printImpossible();
			return ;
		}
		printInt(static_cast<int>(value));
		return ;
	}

	if (isFloat(input))
	{
		// std::cout << BOLDYELLOW << "isFloat: " << input << "\n" << RESET;
		std::string withoutSuffix = input.substr(0, input.length() - 1);
		float f;
		std::istringstream ss(withoutSuffix);
		ss >> f;
		if (ss.fail())
		{
			std::cerr << "Error: Overflow detected for: " << input << "\n";
			printImpossible();
			return ;
		}
		char extra;
		if (ss >> extra)
		{
			std::cerr << "Error: Overflow detected for: " << input << "\n";
			printImpossible();
			return ;
		}
		printFloat(f);
		return ;
	}

	if (isDouble(input))
	{
		// std::cout << BOLDYELLOW << "isDouble: " << input << "\n" << RESET;
		double d;
		std::istringstream ss(input);
		ss >> d;
		if (ss.fail())
		{
			std::cerr << "Error: Overflow detected for: " << input << "\n";
			printImpossible();
			return ;
		}
		char extra;
		if (ss >> extra)
		{
			std::cerr << "Error: Overflow detected for: " << input << "\n";
			printImpossible();
			return ;
		}
		printDouble(d);
		return ;
	}

	printImpossible();
}

/* ************************************************************************** */
// 																			  //
// 						   			TYPE DETECTOR							  //
//																	 		  //
/* ************************************************************************** */

int isChar(std::string input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])
		&& input[0] != '+' && input[0] != '-' && input[0] != '.')
		return 1;
	return 0;
}

int isInt(std::string input)
{
	size_t i = 0;
	
	if (input[i] == '-' || input[i] == '+')
		i++;
	size_t start = i;
	while (i < input.length() && std::isdigit(input[i]))
		i++;
	if (i == input.length() && i > start)
		return 1;
	return 0;
}

int isFloat(std::string input)
{
	size_t i = 0;
	
	if (input[i] == '-' || input[i] == '+')
		i++;
	while (i < input.length() - 1 && std::isdigit(input[i]))
		i++;
	if (i < input.length() - 1 && input[i] == '.')
		i++;
	while (i < input.length() && std::isdigit(input[i]))
		i++;
	if (i < input.length() && input[i] == 'f' && i == input.length() - 1)
		return 1;
	return 0;
}

int isDouble(std::string input)
{
	size_t i = 0;
	
	if (input[i] == '-' || input[i] == '+')
		i++;
	size_t start = i;
	while (i < input.length() - 1 && std::isdigit(input[i]))
		i++;
	if (i < input.length() - 1 && input[i] == '.')
		i++;
	while (i < input.length() && std::isdigit(input[i]))
		i++;
	if (i == input.length() && i > start)
		return 1;
	return 0;
}

/* ************************************************************************** */
// 																			  //
// 						   			PRINTS									  //
//																	 		  //
/* ************************************************************************** */

void printImpossible()
{
	std::cout	<< BOLDRED		<< "Input: not convertible\n" << RESET
				<< GREY			<< "char: impossible\n" << RESET
				<< GREY			<< "int: impossible\n" << RESET
				<< GREY			<< "float: impossible\n" << RESET
				<< GREY			<< "double: impossible\n" << RESET;
	return ;
}

void printSpecial(std::string input)
{
	std::cout << BOLDGREEN << "Input: " << input << "\n" << RESET;
	std::cout << GREY << "char: impossible\n" << RESET;
	std::cout << GREY << "int: impossible\n" << RESET;
	if (input == "nan" || input == "nanf")
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else
	{
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}

void printChar(char c)
{
	// std::cout	<< BOLDGREEN << "Input: " << c << "\n" << RESET;
	std::cout	<< "char: '" << c << "'\n"
				<< "int: " << static_cast<int>(c) << "\n"
				<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f\n"
				<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\n";
	return ;
}

void printInt(int n)
{
	// std::cout << BOLDGREEN << "Input: " << n << "\n" << RESET;
	if (n >= 0 && n <= 127 && std::isprint(n))
		std::cout << "char: '" << static_cast<char>(n) << "'\n";
	else if (n >= 0 && n <= 127)
		std::cout << GREY << "char: Non displayable\n" << RESET;
	else
		std::cout << GREY << "char: impossible\n" << RESET;
	std::cout	<< "int: " << n << "\n"
			 	<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f\n"
				<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << "\n";
	return ;
}

void printFloat(float f)
{
	// std::cout << BOLDGREEN << "Input: " << f << "f\n" << RESET;
	if (std::isnan(f) || std::isinf(f))
		std::cout << GREY << "char: impossible\n" << RESET
				  << GREY << "int: impossible\n" << RESET;
	else
	{
		if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		{
			std::cout	<< GREY << "char: impossible\n" << RESET
						<< GREY << "int: impossible\n" << RESET;
		}
		else
		{
			int n = static_cast<int>(f);
			if (n >= 0 && n <= 127 && std::isprint(n))
				std::cout << "char: '" << static_cast<char>(n) << "'\n";
			else if (n >= 0 && n <= 127)
				std::cout << GREY << "char: Non displayable\n" << RESET;
			else
				std::cout << GREY << "char: impossible\n" << RESET;
			std::cout << "int: " << n << "\n";
		}
	}
	std::cout	<< "float: " << std::fixed << std::setprecision(1) << f << "f\n"
				<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << "\n";
	return ;
}

void printDouble(double d)
{
	// std::cout << BOLDGREEN << "Input: " << d << "\n" << RESET;
	if (std::isnan(d) || std::isinf(d))
		std::cout << GREY << "char: impossible\n" << RESET
				  << GREY << "int: impossible\n" << RESET
				  << GREY << "float: impossible\n" << RESET;
	else
	{
		if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		{
			std::cout	<< GREY << "char: impossible\n" << RESET
						<< GREY << "int: impossible\n" << RESET;
		}
		else
		{
			int n = static_cast<int>(d);
			if (n >= 0 && n <= 127 && std::isprint(n))
				std::cout << "char: '" << static_cast<char>(n) << "'\n";
			else if (n >= 0 && n <= 127)
				std::cout << GREY << "char: Non displayable\n" << RESET;
			else
				std::cout << GREY << "char: impossible\n" << RESET;
			std::cout << "int: " << n << "\n";
		}
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
	}
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
	return ;
}
