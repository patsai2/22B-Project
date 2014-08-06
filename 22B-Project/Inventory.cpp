/**
 * Pseudocode:
 *     while "Return to the Main Menu" not selected
 *         show inventory module menu
 *         prompt for user selection
 *
 *         if "Look Up a Book" selected
 *             show available values to search by
 *             prompt for value to search by
 *             prompt for search term
 *             list books in inventory for which selected value contains search term
 *
 *         else if "Add a Book" selected
 *             confirm user wants to add a book
 *             prompt for and validate each value of the new book
 *             add book into inventory
 *
 *         else if "Edit a Book's Record" selected
 *             prompt for isbn of book to edit
 *             find book by isbn in inventory
 *             show available values to edit
 *             prompt for value to edit
 *             show current value
 *             prompt for new value
 *             ask if user would like to edit another value
 *
 *         else if "Delete a Book" selected
 *             prompt for isbn of book to delete
 *             delete book from inventory
 */

#define _CRT_SECURE_NO_WARNINGS

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

/**
 * Inventory module constructor from the filename of the book inventory database
 */
Inventory::Inventory(string filename) : filename(filename)
{
	ifstream file(filename);

	if (!file.is_open()) throw "File not found or not readable: " + filename;

	string line;
	stringstream ss;

	while (getline(file, line)) {
		ss.clear();
		ss.str(line);

		Book *book = new Book();
		try {
			ss >> *book;
			add(book);
		} catch (string e) {
			if (e == "Invalid book") {
				delete book;
				throw "Inventory database corrupted";
			}
		}
	}
}

/**
 * Inventory module destructor
 */
Inventory::~Inventory()
{
	ofstream file(filename);
	for (size_t i = 0; i < books.size(); i++) {
		file << *books[i] << endl;
		delete books[i];
	}
}

/**
 * Runs the Inventory module
 */
void Inventory::run()
{
	string line;
	int choice;
	bool valid;
	bool exit = false;

	do {
		system("cls");
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

/**
 * Allows the user to look up a book in the inventory
 */
void Inventory::lookupBook()
{
	string line;
	int choice;
	bool valid;

	system("cls");
	cout << "Look up a book by:" << endl;
	cout << endl;
	cout << "     1. ISBN" << endl;
	cout << "     2. Title" << endl;
	cout << "     3. Author" << endl;
	cout << "     4. Publisher" << endl;
	cout << "     5. Cancel" << endl;
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

	if (choice == 5) return;

	string search;

	cout << "Enter a search term: ";
	getline(cin, search);

	cout << endl;
	cout << "Search results for \"" << search << "\":" << endl;
	cout << "ISBN       Title                       Author     Publisher Cost    Price   Qty" << endl;
	cout << "===============================================================================" << endl;
	for (size_t i = 0; i < books.size(); i++) {
		const Book *book = books[i];

		switch (choice) {
		case 1:
			if (book->isbn.find(search) == -1) continue;
			break;
		case 2:
			if (book->title.find(search) == -1) continue;
			break;
		case 3:
			if (book->author.find(search) == -1) continue;
			break;
		case 4:
			if (book->publisher.find(search) == -1) continue;
			break;
		}

		cout << book->isbn << " "
				<< left << setw(27) << book->title.substr(0, 27) << " "
				<< setw(10) << book->author.substr(0, 10) << " "
				<< setw(9) << book->publisher.substr(0, 9) << " "
				<< right << setw(7) << book->getPriceStr() << " "
				<< setw(7) << book->getCostStr() << " "
				<< setw(2) << book->qty << endl;
	}
	cout << endl;
	system("pause");
}

/**
 * Allows the user to add a new book into the inventory
 */
void Inventory::addBook()
{
	string line;
	bool valid;

	cout << "Add a new book? (y/n): ";
	getline(cin, line);
	if (line != "y" && line != "Y") return;

	Book *book = new Book();

	// isbn
	do {
		cout << "Enter the ISBN: ";
		getline(cin, line);
		if (line.length() != 10) {
			valid = false;
		} else {
			book->isbn = line;
			valid = true;
		}
	} while (!valid && cout << "Please enter a 10-digit ISBN." << endl);

	// title
	cout << "Enter the title: ";
	getline(cin, book->title);

	// author
	cout << "Enter the author: ";
	getline(cin, book->author);

	// publisher
	cout << "Enter the publisher: ";
	getline(cin, book->publisher);

	// cost
	do {
		try {
			cout << "Enter the wholesale cost: $";
			getline(cin, line);

			double cost = stod(line);
			if (cost <= 0) {
				valid = false;
			} else {
				book->cost = cost;
				valid = true;
			}
		} catch (exception e) {
			valid = false;
		}
	} while (!valid && cout << "Please enter a valid cost." << endl);

	// price
	do {
		try {
			cout << "Enter the retail price: $";
			getline(cin, line);

			double price = stod(line);
			if (price <= 0) {
				valid = false;
			} else {
				book->price = price;
				valid = true;
			}
		} catch (exception e) {
			valid = false;
		}
	} while (!valid && cout << "Please enter a valid price." << endl);

	// quantity
	do {
		try {
			cout << "Enter the quantity: ";
			getline(cin, line);

			int qty = stoi(line);
			if (qty <= 0) {
				valid = false;
			} else {
				book->qty = qty;
				valid = true;
			}
		} catch (exception e) {
			valid = false;
		}
	} while (!valid && cout << "Please enter a valid quantity." << endl);

	add(book);
}

/**
 * Allows the user to edit a book's record in the inventory
 */
void Inventory::editBook()
{
	string line;
	bool valid;
	int choice;
	Book *book;

	do {
		cout << "Enter the ISBN of the book you would like to edit: ";
		getline(cin, line);
		book = getEditableBook(line);

		if (!book) {
			cout << "ISBN not found. Would you like to try another ISBN? (y/n): ";
			getline(cin, line);

			if (line != "y" && line != "Y") return;
		}
	} while (!book);

	do {
		system("cls");

		cout << endl;
		cout << "ISBN: " << book->isbn << endl;
		cout << "Which value would you like to edit?" << endl;
		cout << endl;
		cout << "    1. ISBN" << endl;
		cout << "    2. Title" << endl;
		cout << "    3. Author" << endl;
		cout << "    4. Publisher" << endl;
		cout << "    5. Wholesale cost" << endl;
		cout << "    6. Retail price" << endl;
		cout << "    7. Quantity" << endl;
		cout << "    8. Cancel" << endl;
		cout << endl;

		do {
			try {
				cout << "Enter Your Choice: ";
				getline(cin, line);
				choice = stoi(line);
				valid = choice > 0 && choice <= 8;
			} catch (exception e) {
				valid = false;
			}
		} while (!valid && cout << "Please enter a value between 1 and 8." << endl);

		if (choice == 8) return;

		switch (choice) {
		// isbn
		case 1:
			cout << "Current ISBN: " << book->isbn << endl;
			do {
				cout << "Enter a new ISBN: ";
				getline(cin, line);
				if (line.length() != 10) {
					valid = false;
				} else {
					book->isbn = line;
					valid = true;
				}
			} while (!valid && cout << "Please enter a 10-digit ISBN." << endl);
			break;

		// title
		case 2:
			cout << "Current title: " << book->title << endl;
			cout << "Enter a new title: ";
			getline(cin, book->title);
			break;

		// author
		case 3:
			cout << "Current author: "  << book->author << endl;
			cout << "Enter a new author: ";
			getline(cin, book->author);
			break;

		// publisher
		case 4:
			cout << "Current publisher: " << book->publisher << endl;
			cout << "Enter a new publisher: ";
			getline(cin, book->publisher);
			break;

		// cost
		case 5:
			cout << "Current wholesale cost: " << book->getCostStr() << endl;
			do {
				try {
					cout << "Enter a new wholesale cost: $";
					getline(cin, line);

					double cost = stod(line);
					if (cost <= 0) {
						valid = false;
					} else {
						book->cost = cost;
						valid = true;
					}
				} catch (exception e) {
					valid = false;
				}
			} while (!valid && cout << "Please enter a valid cost." << endl);
			break;

		// price
		case 6:
			cout << "Current retail price: " << book->getPriceStr() << endl;
			do {
				try {
					cout << "Enter a new retail price: $";
					getline(cin, line);

					double price = stod(line);
					if (price <= 0) {
						valid = false;
					} else {
						book->price = price;
						valid = true;
					}
				} catch (exception e) {
					valid = false;
				}
			} while (!valid && cout << "Please enter a valid price." << endl);
			break;

		// quantity
		case 7:
			do {
				cout << "Current quantity: " << book->qty << endl;
				try {
					cout << "Enter a new quantity: ";
					getline(cin, line);

					int qty = stoi(line);
					if (qty <= 0) {
						valid = false;
					} else {
						book->qty = qty;
						valid = true;
					}
				} catch (exception e) {
					valid = false;
				}
			} while (!valid && cout << "Please enter a valid quantity." << endl);
			break;
		}

		cout << "Edit another value? (y/n): ";
		getline(cin, line);
	} while (line == "y" || line == "Y");
}

/**
 * Allows the user to delete a book from the inventory
 */
void Inventory::deleteBook()
{
	string isbn;
	const Book *book;

	do {
		cout << "Enter the ISBN of the book you would like to delete: ";
		getline(cin, isbn);
		book = getBook(isbn);

		if (!book) {
			string line;
			cout << "ISBN not found. Would you like to try another ISBN? (y/n): ";
			getline(cin, line);

			if (line != "y" && line != "Y") return;
		}
	} while (!book);
}

/**
 * Returns a vector of pointers to the books contained the the inventory
 * sorted by ISBN
 */
vector<const Book*> Inventory::getBooks()
{
	vector<const Book*> b;
	for (size_t i = 0; i < books.size(); i++) b.push_back(books[i]);
	return b;
}

/**
 * Returns a pointer to the book with the given isbn,
 * or a null pointer if not found
 */
const Book *Inventory::getBook(string isbn)
{
	return getEditableBook(isbn);
}

/**
 * Returns a pointer to an editable book with the given isbn,
 * or a null pointer if not found
 */
Book *Inventory::getEditableBook(string isbn)
{
	int index = binary_search_isbn(isbn, books, 0,
			static_cast<int>(books.size()));
	return index < 0 ? NULL : books[index];
}

/**
 * Returns the number of books in the inventory
 */
int Inventory::getSize() { return books.size(); }

/**
 * Adds a new book into the inventory.
 * The book must be dynamically allocated.
 */
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

/**
 * Remove the given quantity of a book from the inventory
 */
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
 * Returns the index of a book in a sorted vector using binary search.
 * The starting index is inclusive, while the ending index is exclusive.
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
