

#ifndef CASHIER_H
#define CASHIER_H


#include "Module.h"
#include "Inventory.h"


class Cashier: public Module
{
    Inventory *inventory;
public:
	Cashier(Inventory &inventory);
	void run();
};

#endif
