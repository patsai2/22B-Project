//
//  CIS 22B Group 5 Final Project
//  Abhinav Anand, Simon Deng, Monica Metzger, and Philip Tsai
//  Professor Manish Goel
//
//  Pseudocode:
//	print options that reports module will do
//	get option number from user
//	if number is not within range tell user to re - enter value

//	case 1(inventory list)
//	use getBooks() to get the books array by ISBN
//	display book information(with title truncated to 35 chars)
//	return to Reports Menu

//	case 2(wholesale value)
//	use getBooks() to get the books array by ISBN
//	display book information(with title, and wholesale value)
//	Calculate total wholesale value and display the value

//	case 3(retail value)
//	use getBooks() to get the books array by ISBN
//	display book information(with title, and retail value)
//	Calculate total retail value and display the value

//	case 4(list by quantity)
//	use getBooks() to get the books array by ISBN
//	selection sort books array in order of quantity(descending order)
//	display book information in order of quantity(with title truncated to 35 chars)
//	return to Reports Menu

//	case 5(list by cost)
//	use getBooks() to get the books array by ISBN
//	selection sort books array in order of cost(ascending order)
//	display book information in order of cost(with title truncated to 35 chars)
//	return to Reports Menu

//	case 6(list by age)
//	use getBooks() to get the books array by ISBN
//	selection sort books array in order of age(ascending order)
//	display book information in order of age(with title truncated to 35 chars)
//	return to Reports Menu

//	case 7(return to main menu)
//	return to Main Menu


#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <iomanip>
#include "Inventory.h"
#include "Reports.h"

using namespace std;

Reports::Reports(Inventory& inventory) : inventory(&inventory) {}


void Reports::run()
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
		cout << "Enter Your Choice: "; //asking user for quantity
		getline(cin, choice);
		try
		{
			x = stoi(choice);
			if (x<0 || x>7)
			{
				cout << "Invalid" << endl;
				valid = false;
			}
			else valid = true;
		}
		catch (exception e)
		{
			cout << "Please enter a value between 1 and 7.";
			valid = false;
		}
	} while (!valid);

	system("cls");

	vector <const Book*>books;

		switch (x)
		{
		case 1:
			books = inventory->getBooks();
			cout << left << setw(5) << " " << setw(40) << "Title" << setw(40) << "Author" << setw(40) << "Publisher" << setw(10) << "Quantity" << setw(10) << "Cost $" << setw(10) << "Price $" << setw(15) << "ISBN" << setw(10)<< "Date Added"<<setw(15)<<endl;

			for (size_t i = 0; i < books.size(); i++)
			{
				cout << left << setw(5) << (i + 1) << setw(40) << books[i]->title.substr(0, 35) << setw(40) << books[i]->author << setw(40) << books[i]->publisher << setw(10) << books[i]->qty << setw(10) << books[i]->cost << setw(10) << books[i]->price << setw(15) << books[i]->isbn << setw(10) << books[i]->getDateStr() << setw(15) << endl;
				//system("sleep .3");
				//system("pause");
			}
			system("pause");	
			
			break;

		case 2:
			books = inventory->getBooks();
			value = 0;
			
			cout << left << setw(5) << " " << setw(80) << "Title" << setw(10) << "Cost $" << endl;

			for (size_t i = 0; i < books.size(); i++)
			{
				value += books[i]->cost;
				cout << left << setw(5) << (i + 1) << setw(80) << books[i]->title << setw(10) << books[i]->cost << endl;
				//system("pause");

			}
			
			cout << endl;
			cout << "Inventory's wholesale value is $" << value << endl;
			system("pause");
			break;

		case 3:
			books = inventory->getBooks();
			value = 0;
			cout << left << setw(5) << " " << setw(80) << "Title" << setw(10) << "Price $" << endl;

			for (size_t i = 0; i < books.size(); i++)
			{
				value += books[i]->price;
				cout << left << setw(5) << (i + 1) << setw(80) << books[i]->title << setw(10) << books[i]->price << endl;

			}
			
			cout << "Inventory's retail value is $" << value << endl;
			system("pause");
			break;

		case 4: 
			books = inventory->getBooks();
			char a;
			cout << "Listing by Quantity: \n\n";
			cout << left << setw(5) << " " << setw(40) << "Title" << setw(40) << "Author" << setw(40) << "Publisher" << setw(10) << "Quantity" << setw(10) << "Cost $" << setw(10) << "Price $" << setw(15) << "ISBN" << setw(10) << "Date Added" << setw(15) << endl;

			selection_sort_qty(books);
			for (size_t i = 0; i < books.size(); i++)
			{
				cout << left << setw(5) << (i + 1) << setw(40) << books[i]->title.substr(0, 35) << setw(40) << books[i]->author << setw(40) << books[i]->publisher << setw(10) << books[i]->qty << setw(10) << books[i]->cost << setw(10) << books[i]->price << setw(15) << books[i]->isbn << setw(10) << books[i]->getDateStr() << setw(15) << endl;
			}
			system("pause");
			break;

		
		case 5:
			books = inventory->getBooks();
			cout << "Listing by Cost: \n\n";
			cout << left << setw(5) << " " << setw(40) << "Title" << setw(40) << "Author" << setw(40) << "Publisher" << setw(10) << "Quantity" << setw(10) << "Cost $" << setw(10) << "Price $" << setw(15) << "ISBN" << setw(10) << "Date Added" << setw(15) << endl;
			selection_sort_cost(books);
			for (size_t i = 0; i < books.size(); i++)
				cout << left << setw(5) << (i + 1) << setw(40) << books[i]->title.substr(0, 35) << setw(40) << books[i]->author << setw(40) << books[i]->publisher << setw(10) << books[i]->qty << setw(10) << books[i]->cost << setw(10) << books[i]->price << setw(15) << books[i]->isbn << setw(10) << books[i]->getDateStr() << setw(15) << endl;
			system("pause");

			break;

		case 6:
			books = inventory->getBooks();
			cout << "Listing by Age: \n\n";
			selection_sort_age(books);
			cout << left << setw(5) << " " << setw(40) << "Title" << setw(40) << "Author" << setw(40) << "Publisher" << setw(10) << "Quantity" << setw(10) << "Cost $" << setw(10) << "Price $" << setw(15) << "ISBN" << setw(10) << "Date Added" << setw(15) << endl;
			for (int i = 0; i < books.size(); i++){
				cout << left << setw(5) << (i + 1) << setw(40) << books[i]->title.substr(0, 35) << setw(40) << books[i]->author << setw(40) << books[i]->publisher << setw(10) << books[i]->qty << setw(10) << books[i]->cost << setw(10) << books[i]->price << setw(15) << books[i]->isbn << setw(10) << books[i]->getDateStr() << setw(15) << endl;
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

void Reports::selection_sort_qty(vector<const Book*>& books)
{
	int size = books.size();

	for (int i = 0; i < size; i++) {
		int least = i;

		for (int j = i + 1; j < size; j++)
		{
			if (cmp_val(books[j]->qty, books[least]->qty) > 0) {
				least = j;
			}
		}

		const Book* tmp = books[least];
		books[least] = books[i];
		books[i] = tmp;
	}
}

void Reports::selection_sort_cost(vector<const Book*>& books)
{
	int size = books.size();

	for (int i = 0; i < size; i++) {
		int least = i;

		for (int j = i + 1; j < size; j++)
		{
			if (cmp_val(books[j]->cost, books[least]->cost) > 0) {
				least = j;
			}
		}

		const Book* tmp = books[least];
		books[least] = books[i];
		books[i] = tmp;
	}
}

void Reports::selection_sort_age(vector<const Book*>& books)
{
	int size = books.size();

	for (int i = 0; i < size; i++) {
		int least = i;

		for (int j = i + 1; j < size; j++)
		{
			if (cmp_val(books[j]->date, books[least]->date) < 0) {
				least = j;
			}
		}

		const Book* tmp = books[least];
		books[least] = books[i];
		books[i] = tmp;
	}
}
