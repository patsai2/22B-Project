//
//  Cashier.h
//  ClassProjectCIS22B
//
//  Created by Monica Metzger on 7/29/14.
//  Copyright (c) 2014 Monica Metzger. All rights reserved.
//


#ifndef __ClassProjectCIS22B__Cashier__
#define __ClassProjectCIS22B__Cashier__


#include <string>
#include <vector>

#include "Module.h"
#include "Inventory.h"




class Cashier: public Module
{
    Inventory inventory;
public:
	Cashier(Inventory &inventory);
	void run();
};

#endif
