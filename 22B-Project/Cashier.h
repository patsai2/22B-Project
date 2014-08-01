//
//  Cashier.h
//  ClassProjectCIS22B
//
//  Created by Monica Metzger on 7/29/14.
//  Copyright (c) 2014 Monica Metzger. All rights reserved.
//


#ifndef Cashier_H
#define Cashier_H


#include <string>
#include <vector>

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