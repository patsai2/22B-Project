#ifndef REPORTSMODULE_H
#define REPORTSMODULE_H

#include <string>
#include <vector>

#include "Module.h"
#include "Inventory.h"


class ReportsModule : public Inventory
{

public:
	ReportsModule(Inventory *inventory);
	void run();
};

#endif
