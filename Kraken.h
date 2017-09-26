#ifndef KRAKEN_H
#define KRAKEN_H
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

class Kraken
{
public:
	Kraken();
	int timer;
	void kill(Model&);
	void printout();
	int ids[50];
	char chars[50];
};

#endif
