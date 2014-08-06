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
#define _CRT_SECURE_NO_WARNINGS
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
	int choice;
	bool valid;
	bool exit = false;

	do {
		cout << "      Serendipity Booksellers" << endl;
		cout << "        Inventory Database" << endl;
		cout << endl;
		cout << "     1. Look Up a Book" << endl;
		cout << "     2. Add a Book" << endl;
		cout << "     3. Edit a Book's Record" << endl;
		cout << "     4. Delete a Book" << endl;
		cout << "     5. Return to the Main Menu" << endl;
		cout << endl;

		do {
			try {
				cout << "Enter Your Choice: ";
				getline(cin, line);
				choice = stoi(line);
				valid = choice > 0 && choice <= 5;
			} catch (exception e) {
				valid = false;
			}
		} while (!valid && cout << "Please enter a value between 1 and 5." << endl);

		switch (choice) {
		case 1:
			lookupBook();
			break;
		case 2:
			addBook();
			break;
		case 3:
			editBook();
			break;
		case 4:
			deleteBook();
			break;
		case 5:
			exit = true;
			break;
		}
	} while (!exit);
}

void Inventory::lookupBook()
{

}

void Inventory::addBook()
{
}

void Inventory::editBook()
{
}

void Inventory::deleteBook()
{
}

vector<const Book*> Inventory::getBooks()
{
	vector<const Book*> b;
	for (size_t i = 0; i < books.size(); i++) b.push_back(books[i]);
	return b;
}

const Book* Inventory::getBook(string isbn)
{
	int index = binary_search_isbn(isbn, books, 0,
			static_cast<int>(books.size()));
	return index < 0 ? NULL : books[index];
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

/**
 * Returns the index of a book in a sorted vector using binary search
 * The starting index is inclusive, while the ending index is exclusive
 */
int Inventory::binary_search_isbn(string isbn, const vector<Book*>& books,
		int start, int end)
{
	if (start == end) return -1;

	int mid = (start + end) / 2;
	int index;

	if (books[mid]->isbn == isbn) {
		index = mid;
	} else if (books[mid]->isbn > isbn) {
		index = binary_search_isbn(isbn, books, start, mid);
	} else {
		index = binary_search_isbn(isbn, books, mid + 1, end);
	}

	return index;
}
