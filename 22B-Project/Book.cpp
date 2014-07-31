#include <string>
#include <ctime>
#include <iostream>
#include <sstream>

#include "Book.h"

using namespace std;

Book::Book() {}

Book::Book(long isbn, string title, string author, string publisher, double cost,
			double price, int qty, time_t date)
	: isbn(isbn)
	, title(title)
	, author(author)
	, publisher(publisher)
	, date(date)
	, qty(qty)
	, cost(cost)
	, price(price) {}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.isbn << '\t'
			<< book.title << '\t'
			<< book.author << '\t'
			<< book.publisher << '\t'
			<< book.date << '\t'
			<< book.qty << '\t'
			<< book.cost << '\t'
			<< book.price << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Book& book)
{
	string line;
	getline(is, line);
	stringstream ss(line);

	string token;
	getline(ss, token, '\t');
	book.isbn = stol(token);
	getline(ss, token, '\t');
	book.title = token;
	getline(ss, token, '\t');
	book.author = token;
	getline(ss, token, '\t');
	book.publisher = token;
	getline(ss, token, '\t');
	book.date = stol(token);
	getline(ss, token, '\t');
	book.qty = stoi(token);
	getline(ss, token, '\t');
	book.cost = stod(token);
	getline(ss, token, '\t');
	book.price = stod(token);

	return is;
}