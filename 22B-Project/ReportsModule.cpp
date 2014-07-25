#include<iostream>
#include<string>
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

		case 4: 

		case 5:

		case 6:

		case 7:
			
			break;

		default:;

		}                                           //end of switch statement
	}                                               //end of infinite loop
	return 0;
}