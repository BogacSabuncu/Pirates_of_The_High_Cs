#include "Pirate.h"

Pirate::Pirate(Model* world) : Sailor('R', world)//default constructer
{
	attack_strength = 2;
	range = 1;
	target = NULL;	
}

Pirate::Pirate(int in_id,Model* world) : Sailor('R', in_id, CartPoint(rand() % 20, rand() % 20), world)
{
	attack_strength = 2;
	range = 1;
	target = NULL;
	
}

double Pirate::get_speed()//gets the speed
{
	return 0;
}

void Pirate::start_plunder(Sailor* sailor)
{
	//checks the distance (totaly forgot about CArtpoint distance function)
	double x = (location.x - (*sailor).location.x);
	double y = (location.y - (*sailor).location.y);
	double pwr_x = pow(x, 2.0);
	double pwr_y = pow(y, 2.0);
	double distance = sqrt((pwr_x)+(pwr_y));


	if(distance <= range)//if the distance is smaller than the range
	{
		cout << display_code << Sailor::get_id() << ": Arghhhh!" << endl;
		target = sailor;
		state = 'p';
	}
	else//if the distance is more than the range
	{
		cout << display_code << Sailor::get_id() << ": I will be back for you!" << endl;
	}
	
}

bool Pirate::update()
{
	if(state == 'x')//dead
	{
		return false;
	}
	else if(state == 'a')//anchored
	{
		 return false;
	}
	else if(state == 'p')//plundering
	{
		//checks the distance again
		double x = (location.x - (*target).location.x);
		double y = (location.y - (*target).location.y);
		double pwr_x = pow(x, 2.0);
		double pwr_y = pow(y, 2.0);
		double distance = sqrt((pwr_x)+(pwr_y));
		
		if(distance > 1)//if its bigger than 1
		{
		cout<< display_code << Sailor::get_id() << "Darn! It escaped." << endl;
		}
		else
		{
			if((*target).state == 'x')//if target dies
			{
				cout<< display_code << Sailor::get_id() << "I triumph!" << endl;
				state = 'a';
				health = health + 5;//gains health
				return true;
			}
			else//attacks
			{
				cout<< display_code << Sailor::get_id() << "Arrghh matey!" << endl;
				(*target).get_plundered(attack_strength);
				return false;
			}
		}
	}
}
void Pirate::show_status()
{
	cout << "Pirate ";
	
	Sailor::show_status();
}
















