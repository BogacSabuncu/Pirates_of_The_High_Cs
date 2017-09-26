#include "Port.h"

Port::Port():GameObject('P',0)//Constructs a port gameobject with P and 0 
{
	inventory = 500;//initializes inv to 500
	state = 'f';//initialized state to f
	cout << "Port default constructed" << endl;
}

Port::Port(int in_id, CartPoint in_loc):GameObject('P', in_id, in_loc)//Constructs gameobject with given id and loc
{
	inventory = 500;//initialized the inv to 500
	state = 'f';//initialized state to f
	cout << "Port constructed"<<endl;
}

bool Port::is_empty()
{
	if(inventory == 0)//checks if the inv is zero
		return true;
	else
		return false;
}

double Port::provide_supplies(double amount_to_provide)
{
	if(inventory >= amount_to_provide)//checks if the there is enough inv
	{
		inventory = inventory - amount_to_provide;//sets a new inventory

		return amount_to_provide;
	}
	else//sets the inv to zero and return the amount left in the port
	{
		double currentInventory = inventory;
		inventory = 0;
		return currentInventory;
	}
}

bool Port::update()
{
	if(inventory == 0 && state != 'e') //checks if the inv is zero and the state is not "e" yet
	{
		state = 'e';//changes state to "e"
		display_code = 'p';//changes the display code to 'p'
		cout << "Port " << Port::get_id() << " has been depleted of supplies"<< endl;
		return true;
	}
	else//if its not empty or if the state is already e returns false
	{
		return false;
	}
}
void Port::show_status()
{
	cout << "Port Status: ";
	GameObject::show_status();
	cout << "containing supplies " << inventory << endl ;
	//shows the status of port by invoking the showstatus function from GameObject class
}

Port::~Port()//destructer
{
	cout<< "Port destructed" << endl;
}
