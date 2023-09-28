/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itopchu <itopchu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:06:16 by itopchu           #+#    #+#             */
/*   Updated: 2023/09/28 18:47:54 by itopchu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() :
	_x(0),
	_y(0)
{
	// std::cout << "Default Constructor of Point called" << std::endl;
}

Point::Point(const float& xInit, const float& yInit) :
	_x(xInit),
	_y(yInit)
{
	// std::cout << "Constructor of Point called" << std::endl;
}

Point::Point(const	Point& copy) :
	_x(copy.getX()),
	_y(copy.getY())
{
	// std::cout << "Copy Constructor of Point called" << std::endl;
	*this = copy;
}

Point&	Point::operator=(const Point& assign)
{
	// std::cout << "Assignation operator Point called" << std::endl;
    if (this == &assign)
        return *this;
    return *this;
}

Point::~Point()
{
	// std::cout << "Destructor of Point called" << std::endl;
}

const Fixed	&Point::getX(void)const
{
	return (this->_x);
}

const Fixed	&Point::getY(void)const
{
	return (this->_y);
}