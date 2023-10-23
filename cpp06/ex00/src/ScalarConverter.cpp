/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/21 19:27:36 by itopchu       #+#    #+#                 */
/*   Updated: 2023/10/21 19:27:36 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int ScalarConverter::__type = 0;
std::string ScalarConverter::__input;
int ScalarConverter::__int = 0;
float ScalarConverter::__float = 0.0f;
char ScalarConverter::__char = '\0';
double ScalarConverter::__double = 0.0;

void ScalarConverter::putDouble(void)
{
	if (ScalarConverter::__type != NAN_INF)
	{
		std::cout << "double: " << ScalarConverter::__double;
		if (ScalarConverter::__double > std::numeric_limits<int>::min() ||
			ScalarConverter::__double < std::numeric_limits<int>::max() ||
			(std::fmod(ScalarConverter::__double, 1.0)))
		{
			std::cout << ".0" << std::endl;
		}
		else
			std::cout << std::endl;
	}
	else
	{
		if (ScalarConverter::__input == "nan" || ScalarConverter::__input == "nanf")
			std::cout << "double: nan" << std::endl;
		else if (ScalarConverter::__input[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::putFloat(void)
{
	if (ScalarConverter::__type != NAN_INF)
	{
		std::cout << "float: " << ScalarConverter::__double;
		if (std::fmod(ScalarConverter::__float, 1.0f))
			std::cout << "f" << std::endl;
		else
			std::cout << ".0f" << std::endl;
	}
	else
	{
		if (ScalarConverter::__input == "nan" || ScalarConverter::__input == "nanf")
			std::cout << "float: nanf" << std::endl;
		else if (ScalarConverter::__input[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}
}

void ScalarConverter::putInt(void)
{
	if (ScalarConverter::__type != NAN_INF &&
		ScalarConverter::__double >= std::numeric_limits<int>::min() &&
		ScalarConverter::__double <= std::numeric_limits<int>::max())
	{
		std::cout << "int: " << ScalarConverter::__int << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::putChar(void)
{
	if (ScalarConverter::__type != NAN_INF &&
		ScalarConverter::__double <= UCHAR_MAX &&
		ScalarConverter::__double >= 0)
	{
		if (isprint(ScalarConverter::__char))
			std::cout << "char: '" << ScalarConverter::__char << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
}

void ScalarConverter::fillValues(void)
{
	switch (ScalarConverter::__type)
	{
		case INT:
			ScalarConverter::__int = std::atoi(ScalarConverter::__input.c_str());
			ScalarConverter::__float = static_cast<float>(ScalarConverter::__int);
			ScalarConverter::__double = static_cast<double>(ScalarConverter::__int);
			ScalarConverter::__char = static_cast<unsigned char>(ScalarConverter::__int);
			break;
		case FLOAT:
			ScalarConverter::__float = std::strtof(ScalarConverter::__input.c_str(), NULL);
			ScalarConverter::__int = static_cast<int>(ScalarConverter::__float);
			ScalarConverter::__double = static_cast<double>(ScalarConverter::__float);
			ScalarConverter::__char = static_cast<unsigned char>(ScalarConverter::__float);
			break;
		case DOUBLE:
			ScalarConverter::__double = std::strtod(ScalarConverter::__input.c_str(), NULL);
			ScalarConverter::__int = static_cast<int>(ScalarConverter::__double);
			ScalarConverter::__float = static_cast<float>(ScalarConverter::__double);
			ScalarConverter::__char = static_cast<unsigned char>(ScalarConverter::__double);
			break;
		case CHAR:
			ScalarConverter::__char = static_cast<unsigned char>(ScalarConverter::__input[ScalarConverter::__input.size() - 1]);
			ScalarConverter::__int = static_cast<int>(ScalarConverter::__char);
			ScalarConverter::__float = static_cast<float>(ScalarConverter::__char);
			ScalarConverter::__double = static_cast<double>(ScalarConverter::__char);
			break;
		default:
			break;
	}
}

void ScalarConverter::findType(void)
{
	std::string*	tmp = &ScalarConverter::__input;

	if (tmp->compare("nan") == 0 || tmp->compare("+inf") == 0 ||
		tmp->compare("-inf") == 0 || tmp->compare("+inff") == 0 ||
		tmp->compare("-inff") == 0 || tmp->compare("nanf") == 0)
	{
		ScalarConverter::__type = NAN_INF;
	}
	else if (tmp->length() == 1 && !(tmp->c_str()[0] >= '0' && tmp->c_str()[0] <= '9'))
	{
		ScalarConverter::__type = CHAR;
	}
	else if (tmp->find_first_of("+-") != tmp->find_last_of("+-"))
	{
		ScalarConverter::__type = ERROR;
	}
	else if (tmp->find_first_not_of("+-0123456789") == std::string::npos)
	{
		ScalarConverter::__type = INT;
	}
	else if (tmp->find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (tmp->find_first_of(".") != tmp->find_last_of(".") ||
			tmp->find_first_of(".") == 0 ||
			tmp->find_first_of(".") == tmp->length() - 1)
			ScalarConverter::__type = ERROR;
		else
			ScalarConverter::__type = DOUBLE;
	}
	else if (tmp->find_first_not_of("+-01234567890.f") == std::string::npos)
	{
		if (tmp->find_first_of("f") != tmp->find_last_of("f") ||
			tmp->find_first_of(".") != tmp->find_last_of(".") ||
			ScalarConverter::__input[tmp->size() - 1] != 'f' ||
			!std::isdigit(tmp->c_str()[tmp->find_first_of("f") - 1]) ||
			tmp->find_first_of(".") == 0)
			ScalarConverter::__type = ERROR;
		else
			ScalarConverter::__type = FLOAT;
	}
	else
	{
		ScalarConverter::__type = ERROR;
	}
	std::cout << ScalarConverter::__type << std::endl;
}

void ScalarConverter::convert(const std::string& input)
{
	ScalarConverter::__input = input;
	findType();
	if (ScalarConverter::__type == ERROR)
	{
		std::cerr << C_RED "Invalid input to convert" C_RESET << std::endl;
		return ;
	}
	fillValues();
	putChar();
	putInt();
	putFloat();
	putDouble();
}
