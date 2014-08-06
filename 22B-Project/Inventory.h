#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <vector>

#include "Module.h"
#include "Book.h"

class Inventory : public Module
{
	std::string filename;
	std::vector<Book*> books;

public:
	Inventory(std::string file);
	~Inventory();
	void run();
	std::vector<const Book*> getBooks();
	const Book *getBook(std::string isbn);
	int getSize();
	void add(Book *book);
	Book remove(const Book *book, int qty);

	static int binary_search_isbn(std::string isbn,
			const std::vector<Book*>& books, int start, int end);
};

#endif
