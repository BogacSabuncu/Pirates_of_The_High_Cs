#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Dock.h"
#include "Port.h"
#include "Sailor.h"
#include "Model.h"
#include "GameCommand.h"
#include "Merchant.h"
#include "Pirate.h"
#include "Kraken.h"
using namespace std;
class Kraken;
class Model;

int main()
{
    	cout << "EC327: Introduction to Software Engineering" << endl;
	cout << "Fall 2015" << endl;
	cout << "Programming Assignment 4" << endl;
	
	Model model;//creates the class model
	Kraken kraken;
	char inputCommand;

	while(true)//keeps the program running
	{
		model.show_status();
		cout << "Enter a command: ";
		
		cin >> inputCommand;//gets the command
		try{
			if(cin.fail())
			{
				throw inputCommand;
			}
		
		

			switch(inputCommand)//cases
			{
				case 's':
				{
					do_sail_command(model);
					break;
				}
				case 'p':
				{
					do_port_command(model);
					break;
				}
				case 'a':
				{
					do_anchor_command(model);
					break;
				}
				case 'd':
				{
					do_dock_command(model);
					break;
				}
				case 'h':
				{
					do_hide_command(model);
					break;
				}
				case 'g':
				{
					do_go_command(model);
					break;
				}
				case 'r':
				{
					do_run_command(model);
					break;
				}
				case 'q':
				{
					kraken.printout();
					return 0;
				}
				case 'u':
				{
					do_plunder_command(model);
					break;
				}
				default:
				{
					cout << "Not a valid comment " << endl;
				}
			
			}
		}
		catch(InvalidInput& except){
		cout << "Invalid input - " << except.msg_ptr << endl;
		}
	}
}
