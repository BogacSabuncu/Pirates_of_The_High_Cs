#include "Model.h"

Model::Model()
{
	time = 0;//sets the time to zero

	Dock* dockA = new Dock(1,CartPoint(5,1));
	Dock* dockB = new Dock(2,CartPoint(6,2));
	Dock* dockC = new Dock(3,CartPoint(1,8));
	dock_points.push_front(dockA);
	dock_points.push_back(dockB);
	dock_points.push_back(dockC);

//////////////////////////////////////////////////////////////////

    	Merchant* merchantA = new Merchant(1, dock_points.front(), this);
	Merchant* merchantB = new Merchant(2, dock_points.back(), this);
	Merchant* merchantC = new Merchant(3, dock_points.back(), this);
	merchant_points.push_front(merchantA);
	merchant_points.push_back(merchantB);
	merchant_points.push_back(merchantC);

	Pirate* pirateA = new Pirate(4, this);	
    	Pirate* pirateB = new Pirate(5, this);
    	
 	
 	sailor_points.push_front(merchantA);
	sailor_points.push_back(merchantB);
	sailor_points.push_back(merchantC);
	sailor_points.push_back(pirateA);
	sailor_points.push_back(pirateB);
	this-> num_sailors = 5;
////////////////////////////////////////////////////////////////////   	
    	
    	Port* portA = new Port(1,CartPoint(1, 20));
    	Port* portB = new Port(2,CartPoint(20,1));
    	Port* portC = new Port(3,CartPoint(20,20));
    	Port* portD = new Port(4,CartPoint(7, 2));
	port_points.push_front(portA);
	port_points.push_back(portB);
	port_points.push_back(portC);
	port_points.push_back(portD);

//////////////////////////////////////////////////////////////////

	object_points.push_front(dockA);
	object_points.push_back(dockB);
	object_points.push_back(dockC);
	object_points.push_back(merchantA);
	object_points.push_back(merchantB);
	object_points.push_back(merchantC);
	object_points.push_back(pirateA);
	object_points.push_back(pirateB);
	object_points.push_back(portA);
	object_points.push_back(portB);
	object_points.push_back(portC);
	object_points.push_back(portD);	

	update_points =(object_points);
	
	srand(time);
}

Model::~Model()
{
	object_points.clear();
}

Sailor* Model::get_Sailor_ptr(int id_num)
{
	for(itSailor = sailor_points.begin(); itSailor != sailor_points.end(); ++itSailor)
	{
		int idN = (**itSailor).get_id(); //finds the right sailor ptr
		if (idN == id_num)
			return *itSailor;
	}
	return NULL;
}

Port* Model::get_Port_ptr(int id_num)
{
	for(itPort = port_points.begin(); itPort != port_points.end(); ++itPort)
	{
		int idN = (**itPort).get_id(); //finds the right sailor ptr
		if (idN == id_num)
			return *itPort;
	}
	return NULL;
}

Dock* Model::get_Dock_ptr(int id_num)
{
{
	for(itDock = dock_points.begin(); itDock != dock_points.end(); ++itDock)
	{
		int idN = (**itDock).get_id(); //finds the right sailor ptr
		if (idN == id_num)
			return *itDock;
	}
	return NULL;
}
}

bool Model::update()
{
	time = time + 1;//inreases time by one
	bool done = false;
	srand(time);
	for(itObj = update_points.begin(); itObj != update_points.end(); ++itObj)
	{
		if((**itObj).is_alive() == false)
			itObj = update_points.erase(itObj);
	}
	for(itObj = update_points.begin(); itObj != update_points.end(); ++itObj)
	{
		if((**itObj).update())
		{
			for(itObj++; itObj != update_points.end(); ++itObj)
			{
				(**itObj).update();
			}
		return true;
		}
	}
	return false;
}


/*void Model::display(View& view)
{
	cout << "Time: " << time << endl;
}*/

void Model::show_status()
{
	
	for(itObj = update_points.begin(); itObj != update_points.end(); ++itObj)
	{
		(**itObj).show_status();//shows status of every object
	}
	cout << "Time: " << time << endl;
}

bool Model::dock_check(Merchant* merch)//to check if there are more than 2 merch at a dock
{
	int x = 0;
	for(itSailor = sailor_points.begin(); itSailor != sailor_points.end(); ++itSailor)
	{
		if(cart_compare((*merch).get_location(), (**itObj).get_location()))//compares the locations of the merchs
		{
			x++;
		}
	}
	if(x > 2)//if there are more than 2 merch at a dock
		return false;
	else
		return true;
}

double Model::get_num_sailors()//get the number of sailors
{
	return num_sailors;
}

void Model::add_new_merchant(Merchant* m)
{
	sailor_points.push_back(m);
	merchant_points.push_back(m);
	object_points.push_back(m);
	
}

void Model::add_new_pirate(Pirate* p)
{
	sailor_points.push_back(p);
	//pirate_points.push_back(p);
	object_points.push_back(p);
	
}

void Model::add_new_port(Port* p)
{
	port_points.push_back(p);
	object_points.push_back(p);
	
}

void Model::add_new_dock(Dock* d)
{
	dock_points.push_back(d);
	object_points.push_back(d);
	
}


