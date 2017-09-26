#include "CartPoint.h"

CartPoint::CartPoint()//initialize the x and y coordinates of the CartPoint
{
	x = 0.0;
	y = 0.0;
}

CartPoint::CartPoint(double in_x, double in_y)//change the x and y points
{
	x = in_x;
	y = in_y;
}

double cart_distance(CartPoint p1, CartPoint p2)//find the cart distance
{
	double xSub = (p2.x - p1.x);//subtracts the x values
	double ySub = (p2.y - p1.y);//subtracts the y values
	double xSqr = pow((xSub), 2);//finds the square of x
	double ySqr = pow((ySub), 2);//finds the square of y
	double distance = sqrt((xSqr + ySqr ));//finds the distance
	return distance;
}

bool cart_compare(CartPoint p1, CartPoint p2)//compares the cart points
{
	if(p1.x == p2.x && p1.y == p2.y)//checks if the x and y values are same
		return true;
	else
		return false;
}

CartPoint operator + (const CartPoint &p1, const CartVector &v1)//overloads the operator
{
	double xAdd = (p1.x + v1.x);//adds the x values
	double yAdd = (p1.y + v1.y);//adds the y values
	return CartPoint(xAdd, yAdd);//returns the new object as CartPoint
}

CartVector operator - (const CartPoint &p1, const CartPoint &p2)//overloads the operator
{
	double xSub = (p1.x - p2.x);//subtracts the x values
	double ySub = (p1.y - p2.y);//subtracts the y values
	return CartVector(xSub, ySub);//returns the new object as CartVector
}

ostream &operator << (ostream &out, const CartPoint &p1)//overloads the output operator
{
	out << "(" << p1.x << ", " << p1.y << ")";
	return out;
}
