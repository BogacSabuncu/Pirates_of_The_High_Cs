#include "Dock.h"

Dock::Dock():GameObject('d', 0)//constructs Dock GameObject with 'd' and id 0
{
	berths = 30;//number of initial berths
	state = 'u';//initial state
	cout << "Dock default constructed"<< endl;
}

Dock::Dock(int in_id, CartPoint in_loc):GameObject('d', in_id, in_loc)//constructs dock object by given values
{
	berths = 30;//number of initial berths
	state = 'u';//initial state
	cout << "Dock constructed" << endl;
}

bool Dock::dock_boat(Sailor* sailor_to_dock)//creates a sailor pointer called sailor_to_dock
{
	if(berths >= (*sailor_to_dock).get_size())//derefrances the pointer and uses get_size func
	{
		berths = berths - (*sailor_to_dock).get_size();//decreases berths by sailor size
		return true;
	}
	else//if there is no space for the sailor
	{
		return false;
	}
}

bool Dock::set_sail(Sailor* sailor_to_sail)//creates a sailor pointer called sailor_to_sail
{
	if((*sailor_to_sail).get_cargo() == 0)//checks if the cargo is zero
	{
		berths = berths + (*sailor_to_sail).get_size() - 5;//inreases the size of the berths
		return true;
	}
	else
	{
		return false;
	}
}

bool Dock::update()
{
	if(berths == 0 && state == 'u')//if the dock is packed but the state is still u
	{
		state = 'p';//changes the state to p
		display_code = 'D';//changes the display code to D
		cout << "Dock " << Dock::get_id() << " is packed" << endl;
		return true;
	}
	else if(berths != 0 && state == 'p')//if the dock is unpacked but the sate is still p
	{
		display_code = 'u';//changes the state to u
		return true;//returns true
	}
	else
	{
		return false;
	}
}

void Dock::show_status()//shows the docks status
{
	cout << "Dock status: ";
	GameObject::show_status();
	cout << " has " << berths << " berths " <<endl;
}

Dock::~Dock()
{
	cout << "Dock destructed" << endl;
}

double Dock::get_berths()
{
	return berths;
}
