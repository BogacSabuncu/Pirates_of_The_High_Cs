#include "GameObject.h"

GameObject::GameObject(char in_code, int in_id)
{
	location = CartPoint(0,0);//initializes the location to (0,0)
	display_code = in_code;//initializes display code
	id_num = in_id;//initializes id num

	cout << "GameObject default constructed" << endl;
}

GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
	location = in_loc;//sets the location to the given location
	display_code = in_code;//initializes display code
	id_num = in_id;//initializes id num

	cout << "GameObject constructed" << endl;
}

CartPoint GameObject::get_location()//to get the location
{
	return location;
}

int GameObject::get_id()//to get the id number
{
	return id_num;
}

void GameObject::show_status()// shows the status 
{
	cout << display_code << " with ID " << id_num << " at location " << location << " ";
}

GameObject::~GameObject()
{
	cout << "GameObject destructed" << endl;
}

bool GameObject::is_alive()
{
	return true;
}

