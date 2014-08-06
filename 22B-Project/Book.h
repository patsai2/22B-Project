#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ctime>

class Book
{
public:
	std::string isbn;
	std::string title;
	std::string author;
	std::string publisher;
	time_t date;
	int qty;
	double cost;
	double price;

	Book();
	Book(std::string isbn, std::string title, std::string author, std::string publisher,
			double cost, double price, int qty = 1, time_t date = time(0));

	std::string getDateStr() const;
	void setDate(std::string date_str);
	std::string getCostStr() const;
	std::string getPriceStr() const;

	friend std::ostream& operator<<(std::ostream& os, const Book& book);
	friend std::istream& operator>>(std::istream& is, Book& book);
};

#endif
