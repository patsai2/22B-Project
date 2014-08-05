#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>
#include "Inventory.h"
#include"ReportsModule.h"

using namespace std;

ReportsModule::ReportsModule(Inventory& inventory) : inventory(&inventory) {}


void ReportsModule::run()
{

	int x;
	bool valid;
	string choice;
	double value;
	int forever = 1;
	while (forever == 1){
		system("cls");
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
	do {
		cout << "Enter Your Choice:" << endl; //asking user for quantity
		getline(cin, choice);
		try
		{
			x = stoi(choice);
			if (x<0)
			{
				cout << "Invalid" << endl;
				valid = false;
			}
			else valid = true;
		}
		catch (exception e)
		{
			cout << "Invalid quantity. Need number 1-7";
			valid = false;
		}
	} while (!valid);

	system("cls");

	vector <const Book*>books;

		switch (x)
		{
		case 1:
			books = inventory->getBooks();

			cout << left << setw(5) << " " << setw(80) << "Title" << setw(60) << "Author" << setw(40) << "Publisher" << setw(10) << "Quantity" << setw(10) << "Cost $" << setw(10) << "Price $" << setw(10) << "ISBN" << endl;

			for (size_t i = 0; i < books.size(); i++)
			{
				cout << left << setw(5) << (i + 1) << setw(80) << books[i]->title << setw(60) << books[i]->author << setw(40) << books[i]->publisher << setw(10) << books[i]->qty << setw(10) << books[i]->cost << setw(10) << books[i]->price << setw(10) << books[i]->isbn << endl;
				//system("sleep .3");
				//system("pause");
			}
			system("pause");	
			
			break;

		case 2:
			books = inventory->getBooks();
			value = 0;
			
			for (size_t i = 0; i < books.size(); i++)
			{
				value += books[i]->cost;
			}
			
			cout << "Inventory's wholesale value is $" << value << endl;
			system("pause");
			break;

		case 3:
			books = inventory->getBooks();
			value = 0;
			
			for (size_t i = 0; i < books.size(); i++)
			{
				value += books[i]->price;
			}
			
			cout << "Inventory's retail value is $" << value << endl;
			system("pause");
			break;

		case 4: 
			books = inventory->getBooks();
			char a;
			cout << "Listing by Quantity: \n\n";
			cout << left << setw(5) << " " << setw(80) << "Title" << setw(60) << "Author" << setw(40) << "Publisher" << setw(10) << "Quantity" << setw(10) << "Cost $" << setw(10) << "Price $" << setw(10) << "ISBN" << endl;

			//cout << "Quantity" << "\t" << "ISBN" << "\t" << "\t" << "\t" << "Title" << "\t" << "\t" << "\t" << "Author" << endl;
			Book::selection_sort_qty(books, inventory->getSize() );
			for (size_t i = 0; i < books.size(); i++)
			{
				cout << left << setw(5) << (i + 1) << setw(80) << books[i]->title << setw(60) << books[i]->author << setw(40) << books[i]->publisher << setw(10) << books[i]->qty << setw(10) << books[i]->cost << setw(10) << books[i]->price << setw(10) << books[i]->isbn << endl;
				//system("pause");
			}
				//cout << books[i]->qty << "\t" << "\t" <<  books[i]->isbn << "\t" << "\t" << books[i]->title << "\t" << "\t" << "\t" << books[i]->author << endl;
			system("pause");
			break;

		
		case 5:
			books = inventory->getBooks();
			cout << "Listing by Cost: \n\n";
			cout << "Cost" << "\t" << "\t" << "\t" << "ISBN" << "\t" << "\t" << "\t" "Title" << "\t" << "\t" << "\t" << "Author" << endl;
			Book::selection_sort_cost(books, inventory->getSize());
			for (size_t i = 0; i < books.size(); i++)
				cout << books[i]->cost << "\t" << "\t" << "\t"<< books[i]->isbn << "\t" << "\t" << books[i]->title << "\t" << " \t" << "\t" << books[i]->author << endl;
			system("pause");

			break;

		case 6:
			books = inventory->getBooks();
			cout << "Listing by Age: \n\n";
			Book::selection_sort_age(books, inventory->getSize());
			cout << "Age" << "\t" << "\t" << "\t" "ISBN" << "\t" << "\t" << "\t" << "Title" << "\t" << "\t" << "\t" << "Author" << endl;
			for (size_t i = 0; i < books.size(); i++){
				const Book*book = books[i];
				cout << ctime(&books[i]->date) << "\t" << "\t" << "\t" <<books[i]->isbn << "\t" << "\t" << books[i]->title << "\t" << "\t" << "\t" << books[i]->author << endl;
			}
			system("pause");
				break;

		case 7:
			forever = 0;
			break;

		default:
			cout<<"Not a Valid Choice \n\n";

		}                                           //end of switch statement
	}                                               //end of infinite loop
	return;
}
