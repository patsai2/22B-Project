#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <ctime>
#include<vector>

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

	friend std::ostream& operator<<(std::ostream& os, const Book& book);
	friend std::istream& operator>>(std::istream& is, Book& book);

	static void selection_sort_qty(std::vector <const Book*>& books);
	static void selection_sort_cost(std::vector<const Book*>& books);
	static void selection_sort_age(std::vector<const Book*>& books);

	template<class T> static int cmp_val(T x, T y)
	{
		if (x < y) return -1;
		else if (x > y) return 1;
		else return 0;
	}
};

#endif
