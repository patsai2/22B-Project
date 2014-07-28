#include<iostream>
#include<string>
#include<vector>
#include "Inventory.h"
using namespace std;

int main(int argc, const char * argv[])
{
	int choice;
	int forever = 1;

	cout << "      Serendipity Booksellers      " << endl;     //35 spaces wide
	cout << "              Reports              " << endl;
	cout << endl;
	cout << "     1. Inventory Listing          " << endl;
	cout << "     2. Inventory Wholesale Value  " << endl;
	cout << "     3. Inventory Retail Value     " << endl;
	cout << "     4. Listing by Quantity        " << endl;
	cout << "     5. Listing by Cost            " << endl;
	cout << "     6. Listing by Age             " << endl;
	cout << "     7. Return to Main Menu        " << endl;

	cout << endl;
	cout << "     Enter Your Choice:            " << endl;
	cin >> choice;
	Inventory inventory;
	while (forever == 1)
	{
		switch (choice)
		{
		case 1:
			const Book**list = inventory.getBooks();
		case 2:

		case 3:

		case 4: 
			vector <const Book*>books = inventory.getBooksByQty();
			for (int i = 0; i < books.size(); i++)
			cout << "There are " << books[i]->qty << " books called " << books[i]->title << "by " << books[i]->author <<"."<< endl;
		case 5:
			vector <const Book*>books = inventory.getBooksByCost();
			for (int i = 0; i < books.size(); i++)
				cout << books[i].title << " by " << books[i].author << " costs $" << books[i].cost <<"."<< endl;
		case 6:
			vector <const Book*>books = inventory.getBooksByAge();
			for (int i = 0; i < books.size(); i++)
				cout << books[i].title << " by " << books[i].author << " is " << books[i].age <<" years old."<< endl;

		case 7:
			
			break;

		default:;

		}                                           //end of switch statement
	}                                               //end of infinite loop
	return 0;
}