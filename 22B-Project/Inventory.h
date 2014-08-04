#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <fstream>
#include <vector>

#include "Module.h"
#include "Book.h"

class Inventory : public Module
{
	std::fstream file;
	std::vector<Book*> books;

public:
	Inventory(std::string file);
	~Inventory();
	void run();
	std::vector<const Book*> getBooks();
	const Book *getBook(std::string isbn);
	int getSize();
	void add(Book *book);
	void remove(const Book *book, int qty);
};

#endif
