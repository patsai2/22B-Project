#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>

#include "Module.h"
#include "Book.h"

class Inventory : public Module
{
	Book **books;
	int size;
	int array_size;

public:
	Inventory();
	~Inventory();
	bool open(std::string file);
	virtual void run();
	const Book **getBooks();
	const Book **getBooksByTitle();
	const Book **getBooksByQty();
	const Book **getBooksByCost();
	const Book **getBooksByAge();
	int getSize();
	void add(Book *book);
	void remove(const Book *book, int qty);
};

#endif
