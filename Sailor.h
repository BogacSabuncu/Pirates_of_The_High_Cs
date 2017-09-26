#ifndef SAILOR_H
#define SAILOR_H
#include <iostream>
#include <math.h>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Dock.h"
#include "Port.h"
using namespace std;

class Dock;
class Port;
class Model;

class Sailor: public GameObject
{
protected:
	Model* world;
private:
	double hold;
	double cargo;
	Port* port;
	Dock* hideout;
	bool update_location();
	void setup_destination(CartPoint dest);
public:
	Sailor(char, Model*);
	Sailor(char, int in_id, Dock* hideout, Model*);
	Sailor(char, int in_id, CartPoint , Model*);
	virtual bool update();
	double get_size();
	double get_cargo();
	void start_sailing(CartPoint dest);
	void start_supplying(Port* destPort);
	void start_hiding();
	bool is_hidden();
	void start_docking(Dock* destDock);
	void anchor();
	void show_status();
	virtual double get_speed() = 0;
	CartPoint destination;
	CartVector delta;
	~Sailor();
	virtual void start_plunder(Sailor*);
	virtual bool start_recruiting(Sailor*);
	void get_plundered(int attack_strength);
	bool is_alive();

	Dock* dock;
	double size;
	double health;
};

#endif
