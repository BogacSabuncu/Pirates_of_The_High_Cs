#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H
#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "Dock.h"
#include "Port.h"
#include "Sailor.h"
#include "Model.h"
#include "InputHandling.h"
using namespace std;

class Model;

	void do_sail_command(Model& model);
	void do_go_command(Model& model);
	void do_run_command(Model& model);
	void do_port_command(Model& model);
	void do_hide_command(Model& model);
	void do_anchor_command(Model& model);
	void do_list_command(Model& model);
	void do_dock_command(Model& model);
	void do_plunder_command(Model& model);

#endif
