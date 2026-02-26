/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erpascua <erpascua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 02:27:39 by erpascua          #+#    #+#             */
/*   Updated: 2026/02/26 17:03:09 by erpascua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// int main(int argc, char **argv)
// {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./convert <input>\n";
// 		return 1;
// 	}

// 	std::string input = argv[1];
// 	ScalarConverter::convert(input);

// 	return 0;
// }

int main()
{
    //Char
    std::cout << "\n\nCHAR\n";
    ScalarConverter::convert("");
    std::cout << "--------\n";
    ScalarConverter::convert(" ");
    std::cout << "--------\n";
    ScalarConverter::convert("	");
    std::cout << "--------\n";
    ScalarConverter::convert("\n");
    std::cout << "--------\n";
    ScalarConverter::convert("0");
    std::cout << "--------\n";
    ScalarConverter::convert("a");
    std::cout << "--------\n";
    ScalarConverter::convert("~");
    std::cout << "--------\n";
    ScalarConverter::convert("è");
    std::cout << "--------\n";
    ScalarConverter::convert("hello world");
    std::cout << "--------\n";
    ScalarConverter::convert("            b");
    std::cout << "--------\n";
    
    //Int
    std::cout << "\n\nINT\n";
    ScalarConverter::convert("00");
    std::cout << "--------\n";
    ScalarConverter::convert("01");
    std::cout << "--------\n";
    ScalarConverter::convert("32");
    std::cout << "--------\n";
    ScalarConverter::convert("42");
    std::cout << "--------\n";
    ScalarConverter::convert("+42");
    std::cout << "--------\n";
    ScalarConverter::convert("-42");
    std::cout << "--------\n";
    
    //Max Int
    ScalarConverter::convert("2147483647");
    std::cout << "--------\n";
    ScalarConverter::convert("2147483648");
    std::cout << "--------\n";
    ScalarConverter::convert("-2147483648");
    std::cout << "--------\n";
    ScalarConverter::convert("-2147483649");
    std::cout << "--------\n";

    
    //Float
    std::cout << "\n\nFLOAT\n";
    ScalarConverter::convert("3.15149265355f");
    std::cout << "--------\n";
    ScalarConverter::convert(".42f");
    std::cout << "--------\n";
    ScalarConverter::convert("4.f");
    std::cout << "--------\n";
    ScalarConverter::convert(".f");
    std::cout << "--------\n";
    ScalarConverter::convert(".0f");
    std::cout << "--------\n";
    ScalarConverter::convert("0.f");
    std::cout << "--------\n";
    ScalarConverter::convert("56.37f");
    std::cout << "--------\n";
    ScalarConverter::convert("-14.41f");
    std::cout << "--------\n";

    //Special Case
    ScalarConverter::convert("nanf");
    std::cout << "--------\n";
    ScalarConverter::convert("+nanf");
    std::cout << "--------\n";
    ScalarConverter::convert("-nanf");
    std::cout << "--------\n";
    ScalarConverter::convert("inff");
    std::cout << "--------\n";
    ScalarConverter::convert("+inff");
    std::cout << "--------\n";
    ScalarConverter::convert("-inff");
    std::cout << "--------\n";

    ScalarConverter::convert("3.ff");
    std::cout << "--------\n";
    ScalarConverter::convert("3.g");
    std::cout << "--------\n";
    
    //Max Float
    ScalarConverter::convert("340282346638528859811704183484516925440.f");
    std::cout << "--------\n";
    ScalarConverter::convert("340282366638528859811704183484516925440.f");
    std::cout << "--------\n";
    
    ScalarConverter::convert("-340282346638528859811704183484516925440.f");
    std::cout << "--------\n";
    ScalarConverter::convert("-340282366638528859811704183484516925440.f");
    std::cout << "--------\n";
    
    ScalarConverter::convert("0.00000000000000000000000000000000000001175494351f");
    std::cout << "--------\n";
    ScalarConverter::convert("0.00000000000000000000000000000000000000000000000001f");
    std::cout << "--------\n";


    //Float
    std::cout << "\n\nDOUBLE\n";
    ScalarConverter::convert("3.15149265355");
    std::cout << "--------\n";
    ScalarConverter::convert(".42");
    std::cout << "--------\n";
    ScalarConverter::convert("4.");
    std::cout << "--------\n";
    ScalarConverter::convert(".");
    std::cout << "--------\n";
    ScalarConverter::convert(".0");
    std::cout << "--------\n";
    ScalarConverter::convert("0.");
    std::cout << "--------\n";
    ScalarConverter::convert("56.37");
    std::cout << "--------\n";
    ScalarConverter::convert("-14.41");
    std::cout << "--------\n";

    //Special Case
    ScalarConverter::convert("nan");
    std::cout << "--------\n";
    ScalarConverter::convert("+nan");
    std::cout << "--------\n";
    ScalarConverter::convert("-nan");
    std::cout << "--------\n";
    ScalarConverter::convert("inf");
    std::cout << "--------\n";
    ScalarConverter::convert("+inf");
    std::cout << "--------\n";
    ScalarConverter::convert("-inf");
    std::cout << "--------\n";

    //Max Float
    ScalarConverter::convert("340282346638528859811704183484516925440.");
    std::cout << "--------\n";
    ScalarConverter::convert("340282366638528859811704183484516925440.");
    std::cout << "--------\n";

    ScalarConverter::convert("-340282346638528859811704183484516925440.");
    std::cout << "--------\n";
    ScalarConverter::convert("-340282366638528859811704183484516925440.");
    std::cout << "--------\n";
    
    ScalarConverter::convert("0.00000000000000000000000000000000000001175494351");
    std::cout << "--------\n";
    ScalarConverter::convert("0.00000000000000000000000000000000000000000000000001");
    std::cout << "--------\n";

    ScalarConverter::convert("179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.");
    std::cout << "--------\n";
    ScalarConverter::convert("179769313486235570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.");
    std::cout << "--------\n";

    ScalarConverter::convert("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.");
    std::cout << "--------\n";
    ScalarConverter::convert("-179769313486235570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.");
    std::cout << "--------\n";
    
    ScalarConverter::convert("0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000022250738585072014");
    std::cout << "--------\n";
    ScalarConverter::convert("0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001");
    std::cout << "--------\n";
}
