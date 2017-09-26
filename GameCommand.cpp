#include "GameCommand.h"

void do_sail_command(Model& model)
{
	CartPoint dest;
	int ID;

	cin >> ID >> dest.x >> dest.y;//gets users adress
	
	if(!(cin>> ID))
		throw InvalidInput("Was expecting an integer");
		
	Sailor* sailor = model.get_Sailor_ptr(ID);//assigns the right sailor ptr
	if(sailor == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");
	if(ID == (*sailor).get_id());//if id is equal to a sailor
	{
		(*sailor).start_sailing(dest);//sailor starts sailing to destination.
	}
}
void do_go_command(Model& model)
{
	model.update();//updates 1 time
	model.show_status();
}
void do_run_command(Model& model)
{
	cout << "Advancing to next event or 5 ticks" << endl;
	int i = 0;
	while(i < 5)
	{
		if(model.update())
			break;
	i++;
	}
	 

}
void do_port_command(Model& model)
{
	int IDs;
	int IDp;

	cin >> IDs >> IDp;

	if(!(cin>> IDs)|| !(cin>>IDp))
		throw InvalidInput("Was expecting an integer");
	
	Sailor *sailor = model.get_Sailor_ptr(IDs);//sets the pointer to the sailor ptr
	if(sailor == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");
	Port *port = model.get_Port_ptr(IDp);//sets the pointer to port pointer.
	if(port == (Port*)NULL)
		throw InvalidInput("Invalid Port ID");
	(*sailor).start_supplying(port);//invokes the start supplying command of the sailor on port location
	
}
void do_hide_command(Model& model)
{
	int ID;
	cin >> ID;
	if(!(cin>> ID))
		throw InvalidInput("Was expecting an integer");

	Sailor *sailor = model.get_Sailor_ptr(ID);//sets the pointer to the right sailor ptr
	if(sailor == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");
	(*sailor).start_hiding();//lets the sailor hide

}
void do_anchor_command(Model& model)
{
	int ID;
	cin >> ID;

	if(!(cin>> ID))
		throw InvalidInput("Was expecting an integer");
	
	Sailor *sailor = model.get_Sailor_ptr(ID);
	if(sailor == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");
	(*sailor).anchor();//anchors the sailor

}
/*void do_list_command(Model& model)	
{
	model->show_status();
}*/
void do_dock_command(Model& model)
{
	int IDs;
	int IDd;

	cin >> IDs >> IDd;

	if(!(cin>> IDs)|| !(cin>>IDd))
		throw InvalidInput("Was expecting an integer");
		
	Sailor *sailor = model.get_Sailor_ptr(IDs);//sets the pointer to the sailor ptr
	if(sailor == (Sailor*)NULL)
		throw InvalidInput("Invalid Sailor ID");
	Dock *dock = model.get_Dock_ptr(IDd);//sets the pointer to dock pointer.
	if(dock == (Dock*)NULL)
		throw InvalidInput("Invalid Dock ID");
	(*sailor).start_docking(dock);
}
void do_plunder_command(Model& model)
{
	int IDs;
	int IDd;
	
	cin >> IDs >> IDd;

	if(!(cin>> IDs)|| !(cin>>IDd))
		throw InvalidInput("Was expecting an integer");


	
	Sailor *sailorA = model.get_Sailor_ptr(IDs);
	if(sailorA == (Sailor*)NULL)
		throw InvalidInput("Invalid SailorA ID");
	Sailor *sailorB = model.get_Sailor_ptr(IDd);
	if(sailorB == (Sailor*)NULL)
		throw InvalidInput("Invalid SailorB ID");	
	(*sailorA).start_plunder(sailorB);
}
