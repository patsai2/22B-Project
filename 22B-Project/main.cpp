//
//  main.cpp
//  ClassProjectCIS22B
//
//  Created by Monica Metzger on 7/23/14.
//  Copyright (c) 2014 Monica Metzger. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
	int choice;
	int forever = 1;

	cout << "      Serendipity Booksellers      " << endl;     //35 spaces wide
	cout << "             Main Menu             " << endl;
	cout << endl;
	cout << "     1. Cashier Module             " << endl;
	cout << "     2. Inventory Database Module  " << endl;
	cout << "     3. Report Module              " << endl;
	cout << "     4. Exit                       " << endl;
	cout << endl;
	cout << "     Enter Your Choice:            " << endl;
	cin >> choice;
	while (forever == 1)
	{
		switch (choice)
		{
		case 1:
			cout << "Serendipity Booksellers            " << endl;
			cout << endl;
			cout << "Date:                              " << endl;

		case 2:

		case 3:

		case 4: break;

		default:;

		}                                           //end of switch statement
	}                                               //end of infinite loop
	return 0;
}