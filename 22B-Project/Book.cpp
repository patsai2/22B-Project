#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

#include "Book.h"

using namespace std;

/**
 * Book default constructor
 */
Book::Book() : date(time(0)) {}

/**
* Book constructor with initial values
*/
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

/**
 * Returns the date added formatted as mm/dd/yyyy
 */
string Book::getDateStr() const
{
	tm *time = localtime(&date);
	return to_string(time->tm_mon + 1) + "/" + to_string(time->tm_mday) + "/"
			+ to_string(time->tm_year + 1900);
}

/**
 * Sets the date added from a string in the format mm/dd/yyyy
 */
void Book::setDate(string date_str)
{
	stringstream ss(date_str);
	string token;

	getline(ss, token, '/');
	int month = stoi(token);
	getline(ss, token, '/');
	int day = stoi(token);
	getline(ss, token);
	int year = stoi(token);

	tm time = {0, 0, 0, day, month - 1, year - 1900};
	date = mktime(&time);
}

/**
 * Returns the wholesale cost as a string with a dollar sign and two decimal places
 */
string Book::getCostStr() const
{
	stringstream ss;
	ss << "$" << fixed << setprecision(2) << cost;
	return ss.str();
}

/**
 * Returns the retail price as a string with a dollar sign and two decimal places
 */
string Book::getPriceStr() const
{
	stringstream ss;
	ss << "$" << fixed << setprecision(2) << price;
	return ss.str();
}

/**
 * Overloaded output stream operator to output tab-separated book database entry
 */
std::ostream& operator<<(std::ostream& os, const Book& book)
{
	os << book.isbn << '\t'
			<< book.title << '\t'
			<< book.author << '\t'
			<< book.publisher << '\t'
			<< book.cost << '\t'
			<< book.price << '\t'
			<< book.getDateStr() << '\t'
			<< book.qty;
	return os;
}

/**
 *Overloaded input stream operator to read tab-separated book database entry
 */
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
	book.setDate(token);
	getline(is, token);
	book.qty = stoi(token);

	return is;
}
