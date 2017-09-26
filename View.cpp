/*
View.cpp
PA3 "Pirates on the High C's"

Created by Ernst Oberortner on 10/23/14.
Modified by Douglas Densmore 10/31/15
Copyright (c) 2015 Boston University. All rights reserved.
*/

#include "View.h"
#include "CartVector.h"
#include "GameObject.h"
// default no-args constructor

View::View()
{
    this->size = 11;
    this->scale = 2;
    this->origin = CartPoint(0,0);
}

// TODO:
// document this!
bool View::get_subscripts(int &ix, int &iy, CartPoint location) {

    CartVector cv;
    cv = (location - this->origin) / this->scale;
    ix = cv.x;
    iy = cv.y;

    if (ix >= 0 && ix <= this->size-1 &&
        iy >= 0 && iy <= this->size-1)
    {
        return true;
    }

    cout << "An object is outside the display" << endl;
    return false;
}

// the clear() method clears the View's grid. It re-initializes
// the grid with '.' in the first dimension and ' ' in the
// second dimension
void View::clear() {
    for (int i = 0; i < view_maxsize; i++)
    {
        for (int j = 0; j < view_maxsize; j++)
        {
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

void View::plot(GameObject* ptr) {
    int ix, iy;
    bool valid;
    valid = get_subscripts(ix, iy, ptr->get_location());

    // if there is no object on this position, then
    // we let the object plot itself in the grid
    if (valid && grid[ix][iy][0] == '.') {
 //       ptr->drawself(grid[ix][iy]);

    // if there is already an object on this position, then
    // we plot a '*' at this position
    } else if (valid) {
        grid[ix][iy][0] = '*';
        grid[ix][iy][1] = ' ';
    }
}

// Visualization of the View's grid.
void View::draw() {
    for (int j = size-1; j >= -1; j--) {
        for (int i = -1; i <= size-1; i++) {
            //grid axis
            if (i == -1 && j%2 == 0) {
                cout << j*2;
                if (j/5 == 0) {
                    cout << " ";
                }
            }
            else if (i == -1 && j%2 != 0) {
                cout << "  ";
            }
            else if (j == -1 && i%2 == 0) {
                cout << i*2;
                if (i/5 == 0) {
                    cout << " ";
                }
                cout << "  ";
            }

            //draw objects
            if (i >= 0 && j >=0) {
                cout << grid[i][j][0] << grid[i][j][1];
            }
        }
        cout << endl;
    }
}

View::~View()
{
	cout << "View destructed." << endl;
}
