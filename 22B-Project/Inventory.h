#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

#include "Module.h"
#include "Book.h"

class Inventory : public Module
{
	std::fstream file;
	std::vector<Book*> books;

public:
	~Inventory();
	bool open(std::string file);
	void close();
	void run();
	std::vector<const Book*> getBooks();
	std::vector<const Book*> getBooksByTitle();
	std::vector<const Book*> getBooksByQty();
	std::vector<const Book*> getBooksByCost();
	std::vector<const Book*> getBooksByAge();
	int getSize();
	void add(Book *book);
	void remove(const Book *book, int qty);
};

#endif
