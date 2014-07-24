#include "Book.h"

Book::Book(long isbn, string title, string author, string publisher, double cost,
			double price, int qty, int date) {
	this->isbn = isbn;
	this->title = title;
	this->author = author;
	this->publisher = publisher;
	this->date = date;
	this->qty = qty;
	this->cost = cost;
	this->price = price;
}
