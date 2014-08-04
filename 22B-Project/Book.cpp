#include <string>
#include <ctime>
#include <iostream>

#include "Book.h"

using namespace std;

Book::Book() {}

Book::Book(string isbn, string title, string author, string publisher,
		double cost, double price, int qty, time_t date)
	: isbn(isbn)
	, title(title)
	, author(author)
	, publisher(publisher)
	, date(date)
	, qty(qty)
	, cost(cost)
	, price(price) {}

string Book::getDateStr() const
{
	tm *time = localtime(&date);
	return to_string(time->tm_mon + 1) + "/" + to_string(time->tm_mday) + "/"
			+ to_string(time->tm_year + 1900);
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.isbn << '\t'
			<< book.title << '\t'
			<< book.author << '\t'
			<< book.publisher << '\t'
			<< book.cost << '\t'
			<< book.price << '\t'
			<< book.date << '\t'
			<< book.qty << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Book& book)
{
	string token;

	getline(is, token, '\t');
	book.isbn = token;
	getline(is, token, '\t');
	book.title = token;
	getline(is, token, '\t');
	book.author = token;
	getline(is, token, '\t');
	book.publisher = token;
	getline(is, token, '\t');
	book.cost = stod(token);
	getline(is, token, '\t');
	book.price = stod(token);
	getline(is, token, '\t');
	book.date = stol(token);
	getline(is, token);
	book.qty = stoi(token);

	return is;
}
