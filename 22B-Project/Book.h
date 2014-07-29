#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ctime>

class Book
{
public:
	long isbn;
	std::string title;
	std::string author;
	std::string publisher;
	time_t date;
	int qty;
	double cost;
	double price;

	Book(long isbn, std::string title, std::string author, std::string publisher,
			double cost, double price, int qty = 1, time_t date = time(0));

	friend std::ostream& operator<<(std::ostream& os, Book& book);
};

#endif
