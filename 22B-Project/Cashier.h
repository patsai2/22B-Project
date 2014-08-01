

#ifndef CASHIER_H
#define CASHIER_H


#include <string>
#include <vector>
#include "Book.h"
#include "Module.h"
#include "Inventory.h"
#include <ctime>

class Cashier: public Module
{
    Inventory *inventory;
public:
	Cashier(Inventory &inventory);
	void run();
};

#endif
