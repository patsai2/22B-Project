#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "Inventory.h"
#include "Book.h"

using namespace std;

Inventory::Inventory(string filename) : filename(filename)
{
	ifstream file(filename);
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
	ofstream file(filename);
	for (size_t i = 0; i < books.size(); i++) {
		file << *books[i] << endl;
		delete books[i];
	}
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
	cout << "Books: " << endl;
	vector<const Book*> books = getBooks();
	for (size_t i = 0; i < books.size(); i++) {
		const Book *book = books[i];
		cout << setw(3) << i + 1 << ". $" << fixed << setprecision(2) << setw(6) << book->price << " - " << setw(2) << book->qty << " x "
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
	for (size_t i = 0; i < books.size(); i++) {
		if (book->isbn < books[i]->isbn) {
			books.insert(books.begin() + i, book);
			return;
		}
	}

	books.push_back(book);
}

Book Inventory::remove(const Book *book, int qty)
{
	for (size_t i = 0; i < books.size(); i++) {
		if (books[i] == book) {
			books[i]->qty -= qty;

			Book removed = *books[i];
			removed.qty = qty;

			if (books[i]->qty <= 0)
            {
				delete books[i];
				books.erase(books.begin() + i);
			}

			return removed;
		}
	}

	return Book();
}
