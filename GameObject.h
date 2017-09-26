#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "CartPoint.h"
using namespace std;

class GameObject
{
private:
	int id_num;
public:
	char display_code;
	char state;

	CartPoint location;
	GameObject(char in_code, int in_id);
	GameObject(char in_code, int in_id, CartPoint in_loc);
	CartPoint get_location();
	int get_id();
	virtual void show_status();
	virtual ~GameObject();
	virtual bool update() = 0;
	virtual bool is_alive();
};

#endif
