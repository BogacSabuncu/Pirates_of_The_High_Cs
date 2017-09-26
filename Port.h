#ifndef PORT_H
#define PORT_H
#include <iostream>
#include "CartPoint.h"
#include "GameObject.h"
using namespace std;

class Port: public GameObject
{
private:
	double inventory;
public:
	Port();
	Port(int in_id, CartPoint in_loc);
	bool is_empty();
	double provide_supplies(double amount_to_provide = 50.0);
	bool update();
	void show_status();
	~Port();
};
#endif
