#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include "Inventory.h"
#include "Book.h"

using namespace std;

Inventory::Inventory(string filename) : file(filename)
{
	string line;
	stringstream ss;

	while (getline(file, line)) {
		ss.clear();
		ss.str(line);
		Book *book = new Book();
		ss >> *book;
		add(book);
	}
}

Inventory::~Inventory()
{
	file.close();
	for (size_t i = 0; i < books.size(); i++) delete books[i];
}

void Inventory::run()
{
	string line;

	cout << "      Serendipity Booksellers" << endl;
	cout << "        Inventory Database" << endl;
	cout << endl;
	cout << "     1. Look Up a Book" << endl;
	cout << "     2. Add a Book" << endl;
	cout << "     3. Edit a Book's Record" << endl;
	cout << "     4. Delete a Book" << endl;
	cout << "     5. Return to the Main Menu" << endl;
	cout << endl;
	cout << "     Enter Your Choice: ";
	getline(cin, line);

	cout << endl;
	cout << "Add 5 x Book 1..." << endl;
	add(new Book("123456789", "Book 1", "Author", "Publisher", 1, 2, 5));
	cout << "Add 3 x Book 2..." << endl;
	add(new Book("987654321", "Book 2", "Author", "Publisher", 1, 2, 3));

	cout << endl;
	cout << "Books: " << endl;
	vector<const Book*> books = getBooks();
	for (size_t i = 0; i < books.size(); i++) {
		const Book *book = books[i];
		cout << i + 1 << ". $" << book->price << " - " << book->qty << " x "
				<< book->title << " by " << book->author
				<< " added on " << book->getDateStr() << endl;
	}
	cout << endl;

	cout << "Remove 1 x Book 1..." << endl;
	remove(books[0], 1);

	cout << endl;
	cout << "Books: " << endl;
	books = getBooks();
	for (size_t i = 0; i < books.size(); i++) {
		const Book *book = books[i];
		cout << i + 1 << ". $" << book->price << " - " << book->qty << " x "
				<< book->title << " by " << book->author
				<< " added on " << book->getDateStr() << endl;
	}
	cout << endl;

	cout << "Remove 4 x Book 1..." << endl;
	remove(books[0], 4);

	cout << endl;
	cout << "Books: " << endl;
	books = getBooks();
	for (size_t i = 0; i < books.size(); i++) {
		const Book *book = books[i];
		cout << i + 1 << ". $" << book->price << " - " << book->qty << " x "
				<< book->title << " by " << book->author
				<< " added on " << book->getDateStr() << endl;
	}
	cout << endl;
}

vector<const Book*> Inventory::getBooks()
{
	vector<const Book*> b;
	for (size_t i = 0; i < books.size(); i++) b.push_back(books[i]);
	return b;
}

const Book* Inventory::getBook(string isbn)
{
	return books[0];
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
	Inventory inventory("books.tsv");
	vector<const Book*> books = inventory.getBooks();
	for (size_t i = 0; i < books.size(); i++) cout << *(books[i]) << endl;
	Module *module = &inventory;
	module->run();
}
*/
