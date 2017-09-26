#include "CartVector.h"

CartVector::CartVector()
{
	x = 0.0;
	y = 0.0;
}

CartVector::CartVector(double in_x, double in_y)
{
	x = in_x;
	y = in_y;
}

CartVector operator *(const CartVector &v1, double d)
{
	double xMulti = (v1.x * d);
	double yMulti = (v1.y * d);
	return CartVector(xMulti, yMulti);
}

CartVector operator /(const CartVector &v1, double d)
{
	if(d == 0)
	{
		return CartVector(v1.x, v1.y);
	}
	else
	{
		double xDvd = (v1.x / d);
		double yDvd = (v1.y / d);
		return CartVector(xDvd, yDvd);
	}
}

ostream &operator << (ostream &out, const CartVector &v1)
{
	out << " <" << v1.x << ", " << v1.y << "> ";
	return out;
}
