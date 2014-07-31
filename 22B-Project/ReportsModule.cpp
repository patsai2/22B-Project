#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include "Inventory.h"
#include"ReportsModule.h"

using namespace std;

ReportsModule::ReportsModule(Inventory& inventory) : inventory(inventory) {}

void ReportsModule::run()
{
	int choice; 
	double value;
	int forever = 1;
	while (forever == 1){
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
	cout << "     Enter Your Choice: ";
	cin >> choice;
	Inventory inventory;
	vector <const Book*>books;

		switch (choice)
		{
		case 1:
			books = inventory.getBooks();

			for (size_t i = 0; i < books.size(); i++)
			{
				cout << "Following is the information about " << books[i]->title << "book:" << endl;
				cout << "author " << books[i]->author << ", publisher " << books[i]->publisher << ", quantity in inventory " << books[i]->qty 
					<< ", cost " << books[i]->cost << ", price " << books[i]->price << ", and ISBN " << books[i]->isbn << "." << endl;
			}
			break;

		case 2:
			books = inventory.getBooks();
			value = 0;
			
			for (size_t i = 0; i < books.size(); i++)
			{
				value += books[i]->cost;
			}
			
			cout << "Inventory's wholesale value is " << value << endl;
			break;

		case 3:
			books = inventory.getBooks();
			value = 0;
			
			for (size_t i = 0; i < books.size(); i++)
			{
				value += books[i]->price;
			}
			
			cout << "Inventory's retail value is " << value << endl;
			break;
		
		case 4: 
			books = inventory.getBooksByQty();
			for (size_t i = 0; i < books.size(); i++)
			cout << "There are " << books[i]->qty << " books called " << books[i]->title << "by " << books[i]->author <<"."<< endl;
			break;
		
		case 5:
			books = inventory.getBooksByCost();
			for (size_t i = 0; i < books.size(); i++)
				cout << books[i]->title << " by " << books[i]->author << " costs $" << books[i]->cost <<"."<< endl;
			break;

		case 6:
			cout << "test"<<endl;
			//start
			for (size_t i = 0; i < books.size(); i++) {
				const Book *book = books[i];
				cout << i + 1 << ". " << books[i]->qty << " x "
					<< books[i]->title << " by " << books[i]->author
					<< " added on " << ctime(&books[i]->date);
			}
			cout << endl;

			cout << "Remove 1 x Book 1..." << endl;

			cout << endl;
			cout << "Books: " << endl;
			for (size_t i = 0; i < books.size(); i++) {
				const Book *book = books[i];
				cout << i + 1 << ". " << books[i]->qty << " x "
					<< books[i]->title << " by " << books[i]->author
					<< " added on " << ctime(&books[i]->date);
			}
			cout << endl;

			cout << "Remove 4 x Book 1..." << endl;

			cout << endl;
			cout << "Books: " << endl;
			for (size_t i = 0; i < books.size(); i++) {
				const Book *book = books[i];
				cout << i + 1 << ". " << books[i]->qty << " x "
					<< books[i]->title << " by " << books[i]->author
					<< " added on " << ctime(&books[i]->date);
			}
			//end
			for (size_t i = 0; i < books.size(); i++){
				const Book*book = books[i];
				cout << "test again" << endl;
				cout << books[i]->title << " by " << books[i]->author << " is " << ctime(&books[i]->date) << " years old." << endl;
			}
				break;

		case 7:
			forever = 0;
			break;

		default:;

		}                                           //end of switch statement
	}                                               //end of infinite loop
	return;
}