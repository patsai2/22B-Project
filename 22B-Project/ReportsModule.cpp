#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<iomanip>
#include "Inventory.h"
#include"ReportsModule.h"

using namespace std;

ReportsModule::ReportsModule(Inventory& inventory) : inventory(&inventory) {}

void ReportsModule::selection_sort_qty(vector<const Book*>& books, int size)
{
	for (int i = 0; i < size; i++) {
		int least = i;

		for (int j = i + 1; j < size; j++) {
			if (books[j]->qty<books[least]->qty) {
				least = j;
			}
		}

		const Book* tmp = books[least];
		books[least]= books[i];
		books[i] = tmp;
	}
}
void ReportsModule::selection_sort_cost(vector<const Book*>& books, int size)
{
	for (int i = 0; i < size; i++) {
		int least = i;

		for (int j = i + 1; j < size; j++) {
			if (books[j]->cost<books[least]->cost) {
				least = j;
			}
		}

		const Book* tmp = books[least];
		books[least] = books[i];
		books[i] = tmp;
	}
}

void ReportsModule::selection_sort_age(vector<const Book*>& books, int size)
{
	for (int i = 0; i < size; i++) {
		int least = i;

		for (int j = i + 1; j < size; j++) {
			if (books[j]->date<books[least]->date) {
				least = j;
			}
		}

		const Book* tmp = books[least];
		books[least] = books[i];
		books[i] = tmp;
	}
}


void ReportsModule::run()
{

	int choice; 
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
	cout << "     Enter Your Choice: ";
	cin >> choice;
	system("cls");
	vector <const Book*>books;
		switch (choice)
		{
		case 1:
			books = inventory->getBooks();

			//cout << "Book" << "\t\t\t" << "Author" << "\t\t" << "Publisher" << "\t\t" << "Quantity" << "\t" << "Cost $" << "\t" << "Price" << "\t" << "ISBN" << endl;

			cout << left << setw(60) << "Book" << setw(60) << "Author" << setw(30) << "Publisher" << setw(30) << "Quantity" << setw(10) << "Cost $" << setw(10) << "Price $" << setw(10) << "ISBN" << endl;

			for (size_t i = 0; i < books.size(); i++)
			{
				cout << left << setw(60) << books[i]->title << setw(60) << books[i]->author << setw(30) << books[i]->publisher << setw(30) << books[i]->qty << setw(10) << books[i]->cost << setw(10) << books[i]->price << setw(10) << books[i]->isbn << endl;
				cout << endl;
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
			cout << "Quantity" << "\t" << "ISBN" << "\t" << "\t" << "\t" << "Title" << "\t" << "\t" << "\t" << "Author" << endl;
			selection_sort_qty(books, inventory->getSize() );
			for (size_t i = 0; i < books.size(); i++)
				cout << books[i]->qty << "\t" << "\t" <<  books[i]->isbn << "\t" << "\t" << books[i]->title << "\t" << "\t" << "\t" << books[i]->author << endl;
			system("pause");
			break;

		
		case 5:
			books = inventory->getBooks();
			cout << "Listing by Cost: \n\n";
			cout << "Cost" << "\t" << "\t" << "\t" << "ISBN" << "\t" << "\t" << "\t" "Title" << "\t" << "\t" << "\t" << "Author" << endl;
			selection_sort_cost(books, inventory->getSize());
			for (size_t i = 0; i < books.size(); i++)
				cout << books[i]->cost << "\t" << "\t" << "\t"<< books[i]->isbn << "\t" << "\t" << books[i]->title << "\t" << " \t" << "\t" << books[i]->author << endl;
			system("pause");

			break;

		case 6:
			books = inventory->getBooks();
			cout << "Listing by Age: \n\n";
			selection_sort_age(books, inventory->getSize());
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
