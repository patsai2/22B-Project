//
//  CIS 22B Group 5 Final Project
//  Abhinav Anand, Simon Deng, Monica Metzger, and Philip Tsai
//  Professor Manish Goel
//
//  Pseudocode:
//      initialize modules
//
//      while "Exit" not selected
//          show main menu
//          prompt for user selection
//          run selected module

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Book.h"
#include "Inventory.h"
#include "Reports.h"
#include "Cashier.h"


using namespace std;

int main(int argc, const char * argv[])
{
	Inventory inventory("books.tsv");
	Reports reports(inventory);
    Cashier cashier(inventory);
    

	Module *module;
	//module = &reports;
	//module->run();

    int x;
    bool valid;
	string choice;
	int forever = 1;
	while (forever == 1)
	{
        system("cls");

        cout << "      Serendipity Booksellers      " << endl;     //35 spaces long
        cout << "             Main Menu             " << endl;
        cout << endl;
        cout << "     1. Cashier Module             " << endl;
        cout << "     2. Inventory Database Module  " << endl;
        cout << "     3. Report Module              " << endl;
        cout << "     4. Exit                       " << endl;
        cout << endl;
        do {
            cout<<"Enter Your Choice: ";
            getline(cin, choice);
            try
            {
                x=stoi(choice);
                if(x < 1 || x > 4)
                {
		    cout<<"Please enter a value between 1 and 4."<<endl;
                    valid=false;
                }
                else valid=true;
            }
            catch(exception e)
            {
                cout<<"Please enter a value between 1 and 4."<<endl;
                valid=false;
            }
        }while(!valid);
        
		switch (x)
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
