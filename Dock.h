#ifndef DOCK_H
#define DOCK_H
#include <iostream>
#include "CartPoint.h"
#include "GameObject.h"
#include "Sailor.h"
using namespace std;

class Sailor;

class Dock: public GameObject
{
private:
	double berths;
public:
	Dock();
	Dock(int in_id, CartPoint in_loc);
	bool dock_boat(Sailor* sailor_to_dock);
	bool set_sail(Sailor* sailor_to_sail);
	bool update();
	void show_status();
	~Dock();
	virtual double get_berths();
};

#endif
