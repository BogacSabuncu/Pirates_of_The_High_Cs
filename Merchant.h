#ifndef MERCHANT_H
#define MERCHANT_H
#include <iostream>
#include <math.h>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Dock.h"
#include "Port.h"
#include "Sailor.h"
#include "Model.h"
using namespace std;

class Merchant: public Sailor
{
public:
	Merchant(Model*);
	Merchant(int, Dock*, Model*);
	double get_speed();
	bool start_recruiting(Sailor *sailor_mate);
	bool update();
	void show_status();
};

#endif
