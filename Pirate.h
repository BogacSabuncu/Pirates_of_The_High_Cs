#ifndef PIRATE_H
#define PIRATE_H
#include <iostream>
#include <math.h>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Dock.h"
#include "Port.h"
#include "Sailor.h"
#include "Model.h"
#include <stdlib.h>
using namespace std;

class Pirate: public Sailor
{
private:
	int attack_strength;
	double range;
	Sailor* target;
public:
	Pirate(Model*);
	Pirate(int, Model*);
	double get_speed();
	void start_plunder(Sailor*);
	bool update();
	void show_status();
};

#endif
