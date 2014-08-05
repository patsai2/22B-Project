#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

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
void Book::selection_sort_qty(vector<const Book*>& books, int size)
{


	for (int i = 0; i < size; i++) {
		int least = i;

		for (int j = i + 1; j < size; j++)
		{
			//	temp = cmp_val<int, int>(books[j]->qty, books[least]->qty);

			if (cmp_val<int, int>(books[j]->qty, books[least]->qty) < 0) {
				least = j;
			}
		}

		const Book* tmp = books[least];
		books[least] = books[i];
		books[i] = tmp;
	}
}
void Book::selection_sort_cost(vector<const Book*>& books, int size)
{
	for (int i = 0; i < size; i++) {
		int least = i;

		for (int j = i + 1; j < size; j++)
		{

			if (cmp_val<int, int>(books[j]->cost, books[least]->cost) < 0) {
				least = j;
			}
		}

		const Book* tmp = books[least];
		books[least] = books[i];
		books[i] = tmp;
	}
}

void Book::selection_sort_age(vector<const Book*>& books, int size)
{
	for (int i = 0; i < size; i++) {
		int least = i;

		for (int j = i + 1; j < size; j++)
		{

			if (cmp_val<int, int>(books[j]->date, books[least]->date) < 0) {
				least = j;
			}
		}

		const Book* tmp = books[least];
		books[least] = books[i];
		books[i] = tmp;
	}
}