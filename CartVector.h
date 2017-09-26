#ifndef CARTVECTOR_H
#define CARTVECTOR_H
#include <iostream>
using namespace std;

class CartVector
{
public:
	double x;
	double y;
	CartVector();
	CartVector(double in_x, double in_y);

};

	CartVector operator *(const CartVector &v1, double d);
	CartVector operator /(const CartVector &v1, double d);
	ostream &operator <<(ostream &out, const CartVector &v1);

#endif
