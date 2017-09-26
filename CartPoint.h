#ifndef CARTPOINT_H
#define CARTPOINT_H
#include <iostream>
#include <cmath>
#include "CartVector.h"
using namespace std;


class CartPoint//cart point classs
{
public:
	double x;//x value
	double y;//y value
	CartPoint();//constructor for the initial values 
	CartPoint(double in_x, double in_y);//constructor for the entered values	
}; 

	double cart_distance(CartPoint p1, CartPoint p2);
	bool cart_compare(CartPoint p1, CartPoint p2);
	CartPoint operator + (const CartPoint &p1, const CartVector &v1);
	CartVector operator - (const CartPoint &p1, const CartPoint &p2);
	ostream &operator << (ostream &out, const CartPoint &p1);

#endif


