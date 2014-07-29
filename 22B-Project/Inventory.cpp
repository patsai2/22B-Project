#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
#include <vector>

#include "Inventory.h"
#include "Book.h"

using namespace std;

Inventory::~Inventory()
{
	for (size_t i = 0; i < books.size(); i++) delete books[i];
}

void Inventory::run()
{
	string line;

	cout << "Serendipity Booksellers" << endl;
	cout << "Inventory Database" << endl;
	cout << "1. Look Up a Book" << endl;
	cout << "2. Add a Book" << endl;
	cout << "3. Edit a Book's Record" << endl;
	cout << "4. Delete a Book" << endl;
	cout << "5. Return to the Main Menu" << endl;
	cout << endl;
	cout << "Enter Your Choice: ";
	getline(cin, line);

	cout << endl;
	cout << "Add 5 x Book 1..." << endl;
	add(new Book(0, "Book 1", "Author", "Publisher", 1, 2, 5));
	cout << "Add 3 x Book 2..." << endl;
	add(new Book(0, "Book 2", "Author", "Publisher", 1, 2, 3));

	cout << endl;
	cout << "Books: " << endl;
	vector<const Book*> books = getBooks();
	for (size_t i = 0; i < books.size(); i++) {
		const Book *book = books[i];
		cout << i + 1 << ". " << books[i]->qty << " x "
				<< books[i]->title << " by " << books[i]->author
				<< " added on " << ctime(&books[i]->date);
	}
	cout << endl;

	cout << "Remove 1 x Book 1..." << endl;
	remove(books[0], 1);

	cout << endl;
	cout << "Books: " << endl;
	books = getBooks();
	for (size_t i = 0; i < books.size(); i++) {
		const Book *book = books[i];
		cout << i + 1 << ". " << books[i]->qty << " x "
			<< books[i]->title << " by " << books[i]->author
			<< " added on " << ctime(&books[i]->date);
	}
	cout << endl;

	cout << "Remove 4 x Book 1..." << endl;
	remove(books[0], 4);

	cout << endl;
	cout << "Books: " << endl;
	books = getBooks();
	for (size_t i = 0; i < books.size(); i++) {
		const Book *book = books[i];
		cout << i + 1 << ". " << books[i]->qty << " x "
			<< books[i]->title << " by " << books[i]->author
			<< " added on " << ctime(&books[i]->date);
	}
	cout << endl;

	cout << "Press enter to continue...";
	getline(cin, line);
}

vector<const Book*> Inventory::getBooks()
{
	vector<const Book*> b;
	for (size_t i = 0; i < books.size(); i++) b.push_back(books[i]);
	return b;
}

vector<const Book*> Inventory::getBooksByTitle() {
	return getBooks();
}
vector<const Book*> Inventory::getBooksByQty() {
	return getBooks();
}

vector<const Book*> Inventory::getBooksByCost() {
	return getBooks();
}

vector<const Book*> Inventory::getBooksByAge() {
	return getBooks();
}

int Inventory::getSize() { return books.size(); }

void Inventory::add(Book *book)
{
	books.push_back(book);
}

void Inventory::remove(const Book *book, int qty)
{
	for (size_t i = 0; i < books.size(); i++) {
		if (books[i] == book) {
			books[i]->qty -= qty;

			if (books[i]->qty <= 0) {
				delete books[i];
				books.erase(books.begin() + i);
			}

			break;
		}
	}
}

/*
int main()
{
	Module *module = new Inventory();
	module->run();
}
*/
