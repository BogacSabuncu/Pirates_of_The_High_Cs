#include "Kraken.h"

Kraken::Kraken()
{

}

void Kraken::kill(Model& world)
{
	int i = 0;
	timer = world.time;
	
	if (timer%15  == 10)//early Kraken WArning
		cout<< "Early Kraken Warning!" << endl;
	
	if(timer%15 == 0 && timer != 0)//Kraken appears
	{
		std::list<Sailor*>::iterator itSailor = world.sailor_points.begin();//iterator for sailor
		for(itSailor; itSailor != world.sailor_points.end(); ++itSailor)//it goes through all the sailors
		{
			char temp = (**itSailor).state;
			if (temp != 'h')//if the state is not hidding
			{
				ids[i] = (**itSailor).get_id();//gets the id
				chars[i] = (**itSailor).display_code;//gets the displaycode
				cout << "Kraken killed " << (**itSailor).display_code <<(**itSailor).get_id() <<  endl;
			
				world.sailor_points.erase(itSailor);//erases the pointer
			
				i++;
			}
		}
	}	
			
}

void Kraken::printout()//prints out the arrays
{
	for(int i = 0; i < 50; i++)
	{
		cout << "Killed by Kraken" << ids[i] << chars[i] <<endl;
	}
	
}
