#ifndef MODEL_H
#define MODEL_H
#include <list>
#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Dock.h"
#include "Port.h"
#include "Sailor.h"
#include "Merchant.h"
#include "Pirate.h"
#include <stdlib.h>
using namespace std;

class Merchant;
class Pirate;

class Model
{
private:

public:
	Model();
	~Model();
	Sailor* get_Sailor_ptr(int id_num);
	Port* get_Port_ptr(int id_num);
	Dock* get_Dock_ptr(int id_num);
	bool update();
	//void display(View& view);
	void show_status();
	bool dock_check(Merchant*);
	double get_num_sailors();
	int time;
	int num_ports;
	int num_docks;
	int num_sailors;
	int num_objects;
	std::list<Merchant*> merchant_points;
	std::list<Sailor*> sailor_points;
	std::list<GameObject*> object_points;
	std::list<Dock*> dock_points;
	std::list<Port*> port_points;
	std::list<GameObject*> update_points;
	std::list<GameObject*>::iterator itObj;
	std::list<Sailor*>::iterator itSailor;
	std::list<Dock*>::iterator itDock;
	std::list<Port*>::iterator itPort;
	void add_new_merchant(Merchant*);
	void add_new_pirate(Pirate*);
	void add_new_port(Port*);
	void add_new_dock(Dock*);
};
#endif
