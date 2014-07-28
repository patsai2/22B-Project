#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

#include "Inventory.h"
#include "Book.h"

using namespace std;

Inventory::Inventory()
	: array_size(10)
	, books(new Book*[array_size]) {}

Inventory::~Inventory()
{
	delete[] books;
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
	cout << "Add 5 new books..." << endl;
	Book *book = new Book(0, "Title", "Author", "Publisher", 1, 2, 5);
	add(book);
	cout << "Book added: " << ctime(&books[getSize() - 1]->date);

	cout << "Remove 1 book..." << endl;
	remove(book, 1);
	cout << "Quantity: " << book->qty << endl;

	cout << "Remove 4 books..." << endl;
	remove(book, 4);
	cout << "Inventory size: " << getSize() << endl;
}

const Book **Inventory::getBooks()
{
	const Book **books = new const Book*[size];
	memcpy(books, this->books, size);
	return books;
}

int Inventory::getSize() { return size; }

void Inventory::add(Book *book)
{
	if (size == array_size) {
		array_size *= 2;
		Book **new_books = new Book*[array_size];
		memcpy(new_books, books, size);
		books = new_books;
	}

	books[size++] = book;
}

void Inventory::remove(const Book *book, int qty)
{
	for (int i = 0; i < size; i++) {
		if (books[i] == book) {
			books[i]->qty -= qty;

			if (books[i]->qty <= 0) {
				delete books[i];
				memcpy(books + i, books + i + 1, size - i - 1);
				size--;
			}

			break;
		}
	}
}

int main()
{
	Module *module = new Inventory();
	module->run();
}
