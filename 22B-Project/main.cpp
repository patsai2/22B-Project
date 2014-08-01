//
//  main.cpp
//  ClassProjectCIS22B
//
//  Created by Monica Metzger on 7/23/14.
//  Copyright (c) 2014 Monica Metzger. All rights reserved.
//

#include <iostream>

#include "Book.h"
#include "Inventory.h"
#include "ReportsModule.h"
#include "Cashier.h"

using namespace std;

int main(int argc, const char * argv[])
{
	Inventory inventory("books.tsv");
	ReportsModule reports(inventory);

	Module *module;
	//module = &reports;
	//module->run();

	int choice;
	int forever = 1;
	while (forever == 1)
	{
        cout << "      Serendipity Booksellers      " << endl;     //35 spaces long
        cout << "             Main Menu             " << endl;
        cout << endl;
        cout << "     1. Cashier Module             " << endl;
        cout << "     2. Inventory Database Module  " << endl;
        cout << "     3. Report Module              " << endl;
        cout << "     4. Exit                       " << endl;
        cout << endl;
        cout << "     Enter Your Choice: ";
        cin >> choice;

		switch (choice)
		{
            case 1:
                
                module= &cashier;

                module->run();
                break;
            case 2:
                module = &inventory;
                module->run();

                break;
            case 3:
                module = &reports;
                module->run();
                break;
            case 4: 
                return 0;

            default:
                cout << "You didn't enter a valid choice" << endl;
			

		}                                           //end of switch statement
	}                                               //end of infinite loop
	return 0;
}