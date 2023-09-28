/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/31 13:07:02 by itopchu       #+#    #+#                 */
/*   Updated: 2023/08/31 13:07:02 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

const double EPSILON = 1e-9;

// Used formula: A=1/2​∣x1(y2−y3)+x2(y3−y1)+x3(y1−y2)∣
static float area(const Point p1, const Point p2, const Point p3)
{
	float	area;

	area =	(( p1.getX().toFloat() * ( p2.getY().toFloat() - p3.getY().toFloat() ) )
			+ ( p2.getX().toFloat() * ( p3.getY().toFloat() - p1.getY().toFloat() ) )
			+ ( p3.getX().toFloat() * ( p1.getY().toFloat() - p2.getY().toFloat() ) ))
			/ 2;
	return (area >= 0 ? area : -1);
}

static bool bsp(const Point a, const Point b, const Point c, const Point point)
{
	float base, baseC, baseA, baseB;
	double	abs;

	base = area(a, b, c);
	baseC = area(point, a, b);
	baseA = area(point, b, c);
	baseB = area(point, a, c);

	abs = base - (baseA + baseB + baseC);
	abs = abs < 0 ? abs * -1 : abs;
	if (baseC > 0 && baseA > 0 && baseB > 0 &&
		abs < EPSILON)
		return true;
	return (false);
}

static void	checkCollision(const Point& a, const Point& b, const Point& c, const Point& point)
{
	if (bsp(a, b, c, point))
		std::cout << "(" << point.getX() << "," << point.getY() << ") " << "Point is inside of the triangle." << std::endl;
	else
		std::cout << "(" << point.getX() << "," << point.getY() << ") " << "Point is outside of the triangle." << std::endl;
}


int main()
{
	Point A(0.0, 0.0);
	Point B(8.0, 0.0);
	Point C(4.0, 10.0);
	Point outside(0.0, 5.0);
	Point edge(2.0, 0.0);
	Point inside(4, 1.5);
	checkCollision(A, B, C, outside);
	checkCollision(A, B, C, edge);
	checkCollision(A, B, C, inside);
	return 0;
}
