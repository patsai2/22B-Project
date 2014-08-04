#ifndef REPORTSMODULE_H
#define REPORTSMODULE_H

#include <string>
#include <vector>

#include "Module.h"
#include "Inventory.h"


class ReportsModule : public Module
{
	Inventory *inventory;

public:
	ReportsModule(Inventory& inventory);
	void selection_sort_int(int quant[], int size);
	void run();
};

#endif
