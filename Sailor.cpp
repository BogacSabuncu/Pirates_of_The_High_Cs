#include "Sailor.h"

Sailor::Sailor(char display_code, Model* world):GameObject(display_code, 0)//default sailor
{
	health = 60;
	size = 15;
	hold = 100;
	cargo = 0;
	CartPoint destination(0.0, 0.0);
	port = NULL;
	dock = NULL;
	hideout = NULL;
	state = 'a';
	this->world = world;
	cout << "Sailor default constructed" << endl;
}

Sailor::Sailor(char display_code, int in_id, Dock* hideout, Model* world):GameObject(display_code, in_id, (*hideout).get_location())//constructer
{
	health = 60;
	size = 15;
	hold = 100;
	cargo = 0;
	destination = (*hideout).get_location();//location of the hideout
	port = NULL;
	dock = hideout;
	this->hideout = hideout;
	state = 'h';
	this->world = world;
	
	cout << "Sailor constructed" << endl;
}

Sailor::Sailor(char display_code, int in_id, CartPoint place, Model* world):GameObject(display_code, in_id, place )//constructer
{
	health = 60;
	size = 15;
	hold = 100;
	cargo = 0;
	destination =place;//location of the hideout
	port = NULL;
	dock = hideout;
	this->hideout = hideout;
	state = 'a';
	this->world = world;
	
	cout << "Sailor constructed" << endl;
}
double Sailor::get_speed()//finds the speed
{
	double speed = (size - (cargo * 0.1) );//finds the speed of the sailor
	return speed;
}

double Sailor::get_size()//gets the size
{
	return size;
}

double Sailor::get_cargo()//gets the cargo
{
	return cargo;
}

void Sailor::setup_destination(CartPoint dest)//finds the delta value
{
	destination = dest;//sets up destiontaion
	delta = (destination - location) * (Sailor::get_speed()/cart_distance(destination, location));
}

bool Sailor::update_location()
{
	CartVector Fabs;//creates a fabs vector
	Fabs.x = fabs(destination.x - location.x);//x member of the vector
	Fabs.y = fabs(destination.y - location.y);//y member of the vector


	if(Fabs.x <= fabs(delta.x) && Fabs.y <= fabs(delta.y))//if the x and y values are close enough
	{
		location = destination;//destination is reached
		cout <<display_code << Sailor::get_id() << ": I am there!" << endl;
		return true;
	}
	else//if not
	{
		cout <<display_code << Sailor::get_id() << ": Just keep sailing..." << endl;
		location = location + delta;//delta is added to destinations
		return false;
	}
}

void Sailor::start_sailing(CartPoint dest)
{
	setup_destination(dest);//sets up the destination

	if(state == 'd')//if sailor is docked
	{
		(*dock).set_sail(this);//calls the set sail func in dock
	}

	state = 's';

	cout << "Sailing " << Sailor::get_id() << " to " << destination << endl;
	cout << display_code << Sailor::get_id() << ": On my way" << endl;
}

void Sailor::start_supplying(Port* destPort)
{
	port = destPort;//sets the pointer to destPort
	setup_destination((*port).get_location());//sets the destination to port location
	state = 'o';//sets the state to port

	cout << "Sailor " << Sailor::get_id() << ": supplying at Port " << (*port).get_id() << " and going to Port " << (*port).get_id() << endl;
	cout << display_code << Sailor::get_id() << ": Supplies here I come" << endl;
}

void Sailor::start_hiding()
{
	setup_destination((*hideout).get_location());//sets the destination to hideout
	state = 'h';//sets the state to h

	cout << "Sailor " << Sailor::get_id() << " hiding " << Sailor::get_id() << endl;
	cout << display_code << Sailor::get_id() << ": Off to hide" << endl;
}

bool Sailor::is_hidden()
{
	if(hideout != NULL && cart_compare(location, (*hideout).get_location()))//checks if the location is equal to hideout location
		return true;
	else
		return false;
}

void Sailor::start_docking(Dock* destDock)
{
	dock = destDock;//sets the dock pointer to destDock
	setup_destination((*dock).get_location());//calls the setup destionation function
	state = 'i';//changes the state to i

	cout << "Sailor " << Sailor::get_id() << " sailing to Dock " << (*dock).get_id() << endl;
	cout << display_code << Sailor::get_id() << ": Off to dock" << endl;
}

void Sailor::anchor()
{
	state = 'a';//changes the state to anchored

	cout << "Stoping " << Sailor::get_id() << endl;
	cout << display_code << Sailor::get_id() << ": Off to dock" << endl; 
}

void Sailor::show_status()
{
	cout << " status: ";
	GameObject::show_status();
	
	switch(state)
	{
		case 'a'://when the state is anchoned
		{
			if(Sailor::is_hidden())//if the sailor is hiding
				cout << "is anchored (and hiding). Has a size of: "<< size << ", cargo of: " << cargo << ", hold of: " << hold << ", and health of: " << health << endl;
			else
				cout << "is anchored. Has a size of: "<< size << ", cargo of: " << cargo << ", hold of: " << hold << ", and health of: " << health << endl;
			break;
		}
		case 's': // state is sailing
		{
			cout << "has a speed of: " << Sailor::get_speed() << " and is heading to: " << destination << endl;
			break;
		}
		case 'o': //state is outbound
		{
			cout << "is outbound to Port: " << (*port).get_id() << " with a speed of " << Sailor::get_speed()<< endl;
			break;
		}
		case 'i'://state is inbound
		{
			cout << "is inbound to Dock: " << (*dock).get_id() << " with a speed of " << Sailor::get_speed()<< endl;
			break;
		}
		case 'l'://state is loading
		{
			cout << "is supplying at Port " << (*port).get_id()<< endl;
			break;
		}
		case 'u'://state is unloading
		{
			cout << "is unloading at Dock " << (*dock).get_id() << endl;
			break;
		}
		case 'd'://state is docked
		{
		        cout << "is docked at Dock " << (*dock).get_id() << endl;
			break;
		}
		case 't'://state is trouble
		{
			cout << "is in touble " << Sailor::get_id() << endl;
			break;
		}
		case 'h'://if hidden
		{
			cout << "is going to hide at Dock " << (*dock).get_id() << endl;
		}
	}
}

bool Sailor::update()
{
	switch(state)
	{
		case 's'://state is sailing
		{
			if(Sailor::update_location())//if arrived
			{
				state = 'a';
				return true;
			}
			break;
		}
		case 'o'://state is outbound
		{
			if(Sailor::update_location())//if arrived
			{
				state = 'l';
				return true;
			}
			break;
		}
		case 'i'://state is inbound
		{
			if(Sailor::update_location())//if arrived
			{
				state = 'u';
				return true;
			}
			break;
		}
		case 'l'://state is loading
		{
			if(cargo == hold)//if the boat is full
			{
				state = 'a';
				cout << display_code << Sailor::get_id() << ": My boat is filled up. Send me to a Dock to unload. Dropping anchor" << endl;
			}
			else//if the boat is not full
			{
			  if(!(this->port->is_empty()))//and the port is not empty
				{
					if((hold - cargo) >= 50)//if there is enough space for a ful provide
					{
						cargo = cargo + (*port).provide_supplies();//port provides supplies
					}
					else if ((hold - cargo) < 50 && hold != cargo)//if there is not enough space for a full supply
					{
						double placeLeft = hold - cargo;
						cargo = cargo + (*port).provide_supplies(placeLeft);//supplies the amount needed
					}
					cout << display_code << Sailor::get_id() << ": My new cargo is " << cargo << endl;
				}
				else//if the port is empty
				{
					state = 'a';//changes the state to a
					cout << display_code << Sailor::get_id() << ": This Port has no more supplies for me. Dropping anchor"<<endl;
				}
				return true;
			}
			break;
		}
		case 'u'://case is unloading
		{
			if((*dock).dock_boat(this))//if the dock is not full and you dock
			{
				cout << display_code << Sailor::get_id() << ": I am unloading at the dock" << endl;
				if(cargo > 0)//if you have  cargo
				{
					hold = hold + 20;
					size = size + 5;
					cargo = 0;
				}
			}
			else//if the dock is full
			{
				cout << display_code << Sailor::get_id() << ": Help! My dock is full" << endl;
			}
			return true;
			break;
		}
		case 'h'://case is hidding
		{
			if(Sailor::update_location())
			{
				if(Sailor::is_hidden())//if the sailor is hidden
				{	
					state = 'a';
					cout << display_code << get_id()<< ": Is going to hide at Dock" << (*dock).get_id() << endl;

				return false;
				}
			}
			break;
		}
		case 'a':
		{
			if(is_hidden())
			{
				health = health - 5;// decreases health by five points
				if (health <= 5)// health is lower than 5 
				{
					state = 'x';//sailor dies
				}
			}			
			return false;
			break;
		}
		case 'x':
		{
			return false;
			break;
		}
		
	}
}

Sailor::~Sailor()
{
	cout << "Sailor destructed" << endl;
}

void  Sailor::start_plunder(Sailor*)
{
	cout << "I cannot plunder." << endl;
}

bool Sailor::start_recruiting(Sailor*) 
{
	cout << "I cannot recruit." << endl;
}

void Sailor::get_plundered(int attack_strength)
{
	health = health - attack_strength;//decreases the health by the attack strenght.

	if(health <= 0)//if the health is less than or equal to zero
	{
		cout << "Oh no, now I'm in Davy Jones' Locker!" << endl;//prints
		
		state = 'x';//sets the state
	}
	else
	{
		cout << "Ouch!" << endl;
	}
}
bool Sailor::is_alive()
{
	if(health > 0 || state != 'x')
		return true;
	else
		return false;
}
