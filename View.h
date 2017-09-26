/*
View.h
PA3 "Pirates on the High C's"

Created by Ernst Oberortner on 10/23/14.
Modified by Douglas Densmore 10/31/15
Copyright (c) 2015 Boston University. All rights reserved.
*/

#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include "CartPoint.h"
class GameObject;
class CartVector;

const int view_maxsize=20;

class View
{
    int size;
    double scale;
    CartPoint origin;
    char grid[view_maxsize][view_maxsize][2];

    bool get_subscripts(int &ix, int &iy, CartPoint location);

public:
    View();
    void clear();
    void plot(GameObject* ptr);
    void draw();

	//destructor
	~View();
};

#endif 
