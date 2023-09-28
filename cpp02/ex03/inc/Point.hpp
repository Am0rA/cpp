/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itopchu <itopchu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:06:16 by itopchu           #+#    #+#             */
/*   Updated: 2023/09/28 17:04:16 by itopchu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const float& xInit, const float& yInit);
		Point(const	Point& copy);
		Point&	operator=(const Point& assign);
		~Point();
		const	Fixed& getX(void) const;
		const	Fixed& getY(void) const;
};

#endif
