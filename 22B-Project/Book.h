#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ctime>

using namespace std;

class Book
{
public:
	long isbn;
	string title;
	string author;
	string publisher;
	time_t date;
	int qty;
	double cost;
	double price;

	Book(long isbn, string title, string author, string publisher, double cost,
			double price, int qty = 0, time_t date = time(0));
};

#endif
