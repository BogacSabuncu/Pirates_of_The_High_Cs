#include "Merchant.h"

Merchant::Merchant(Model* world) : Sailor('M', world)
{
	size = 10;
}

Merchant::Merchant(int id, Dock* home, Model* world) : Sailor('M', id, home, world)
{
	size = 10;
}

double Merchant::get_speed()//speed of the merchant
{
	double speed = (1/size)*health*4;
	return speed;
}

bool Merchant::start_recruiting(Sailor* sailor_mate)//recruiting
{
	double berths = (*dock).get_berths();
	bool dock_check = world->dock_check(this);

	if(this->is_hidden() && (*sailor_mate).is_hidden() && dock == (*sailor_mate).dock && health >= 40 && (*sailor_mate).health >= 40 && berths >= 15 && dock_check)
	{
		this->state = 'r';
		(*sailor_mate).state = 'm';
		
		return true;
	}
	else
	{
		return false;
	}
}

bool Merchant::update()
{
	
	if (state == 'a')//if the sate is a
	{
		Sailor* sailor_mate;
		int num_sailors = world->get_num_sailors();
		for(int i = 0; i < num_sailors; i++)//to find the sailor mate
		{
			Sailor* temp = world->get_Sailor_ptr(i);//gets the pointers of sailors

			if(dock == (*temp).dock && temp != this)//if they have the same dock and the pointer is 
			{
				sailor_mate = temp;//assigns the sailor mate
			}
		}

		if(start_recruiting(sailor_mate))//checks if they can recruit
		{
			static int timer = 0;//sets a timer

			if(timer == 2)//if two time clicks have past
			{
				cout << display_code << this->get_id() << ": I found a new recruit!" << endl;
				Merchant* recruit = new Merchant(world);//creates a new merch
				timer = 0;
				return true;
			}
			else
			{
				timer++;//increases the timer by one
				return false;
			}
		}
	}
	else
	{
		Sailor::update();
	}
}

void Merchant::show_status()
{
	cout << "Merchant "; 
	Sailor::show_status();
}
