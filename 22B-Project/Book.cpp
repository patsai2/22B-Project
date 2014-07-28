#include <string>
#include <ctime>

#include "Book.h"

using namespace std;

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
