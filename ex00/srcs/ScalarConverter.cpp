/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:29:00 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/25 05:41:33 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

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
	
	if (isChar(input))
	{
		// std::cout << BOLDYELLOW << "isChar: " << input << "\n" << RESET;
		printChar(input[0]);
		return ;
	}

	if (isInt(input))
	{
		// std::cout << BOLDYELLOW << "isInt: " << input << "\n" << RESET;
		try 
		{
			int n = std::stoi(input);
			printInt(n);
			return ;
		}
		catch (std::out_of_range &) {
			double d = std::stod(input);
			printDouble(d);
		}
	}

	if (isFloat(input))
	{
		// std::cout << BOLDYELLOW << "isFloat: " << input << "\n" << RESET;
		float f = std::stof(input);
		printFloat(f);
		return ;
	}

	if (isDouble(input))
	{
		// std::cout << BOLDYELLOW << "isDouble: " << input << "\n" << RESET;
		double d = std::stod(input);
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

static void	printFormat(float f)
{
	if (f == static_cast<float>(static_cast<long long>(f)))
		std::cout << std::fixed << std::setprecision(1) << f << std::defaultfloat;
	else
		std::cout << std::defaultfloat << f;
}

static void	printFormat(double d)
{
	if (d == static_cast<double>(static_cast<long long>(d)))
		std::cout << std::fixed << std::setprecision(1) << d << std::defaultfloat;
	else
		std::cout << std::defaultfloat << d;
}

void printChar(char c)
{
	std::cout << BOLDGREEN << "Input: " << c << "\n" << RESET;
	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: "; printFormat(static_cast<float>(c)); std::cout << "f\n";
	std::cout << "double: "; printFormat(static_cast<double>(c)); std::cout << "\n";
	return ;
}

void printInt(int n)
{
	std::cout << BOLDGREEN << "Input: " << n << "\n" << RESET;
	if (n >= 0 && n <= 127 && std::isprint(n))
		std::cout << "char: '" << static_cast<char>(n) << "'\n";
	else if (n >= 0 && n <= 127)
		std::cout << GREY << "char: non displayable\n" << RESET;
	else
		std::cout << GREY << "char: impossible\n" << RESET;
	std::cout << "int: " << n << "\n";
	std::cout << "float: "; printFormat(static_cast<float>(n)); std::cout << "f\n";
	std::cout << "double: "; printFormat(static_cast<double>(n)); std::cout << "\n";
	return ;
}

void printFloat(float f)
{
	std::cout << BOLDGREEN << "Input: "; printFormat(f); std::cout << "f\n" << RESET;
	if (std::isnan(f) || std::isinf(f))
		std::cout << GREY << "char: impossible\n" << RESET
				  << GREY << "int: impossible\n" << RESET;
	else
	{
		if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
		{
			std::cout << GREY << "char: impossible\n" << RESET;
			std::cout << GREY << "int: impossible\n" << RESET;
		}
		else
		{
			int n = static_cast<int>(f);
			if (n >= 0 && n <= 127 && std::isprint(n))
				std::cout << "char: '" << static_cast<char>(n) << "'\n";
			else if (n >= 0 && n <= 127)
				std::cout << GREY << "char: non displayable\n" << RESET;
			else
				std::cout << GREY << "char: impossible\n" << RESET;
			std::cout << "int: " << n << "\n";
		}
	}
	std::cout << "float: "; printFormat(f); std::cout << "f\n";
	std::cout << "double: "; printFormat(static_cast<double>(f)); std::cout << "\n";
	return ;
}

void printDouble(double d)
{
	std::cout << BOLDGREEN << "Input: "; printFormat(d); std::cout << "\n" << RESET;
	if (std::isnan(d) || std::isinf(d))
		std::cout << GREY << "char: impossible\n" << RESET
				  << GREY << "int: impossible\n" << RESET
				  << GREY << "float: impossible\n" << RESET;
	else
	{
		if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		{
			std::cout << GREY << "char: impossible\n" << RESET;
			std::cout << GREY << "int: impossible\n" << RESET;
		}
		else
		{
			int n = static_cast<int>(d);
			if (n >= 0 && n <= 127 && std::isprint(n))
				std::cout << "char: '" << static_cast<char>(n) << "'\n";
			else if (n >= 0 && n <= 127)
				std::cout << GREY << "char: non displayable\n" << RESET;
			else
				std::cout << GREY << "char: impossible\n" << RESET;
			std::cout << "int: " << n << "\n";
		}
		std::cout << "float: "; printFormat(static_cast<float>(d)); std::cout << "f\n";
	}
	std::cout << "double: "; printFormat(d); std::cout << "\n";
	return ;
}