#ifndef REPORTSMODULE_H
#define REPORTSMODULE_H

#include <string>
#include <vector>

#include "Module.h"
#include "Inventory.h"


class ReportsModule : public Module
{
	Inventory *inventory;

public:
	ReportsModule(Inventory& inventory);
	void selection_sort_qty(std::vector <const Book*>& books, int size);
	void selection_sort_cost(std::vector<const Book*>& books, int size);
	void selection_sort_age(std::vector<const Book*>& books, int size);
	template <class T, class E> T cmp_val(E x, E y)
	{
		if (x < y) return -1;
		else if (x > y) return 1;
		else return 0;
	}

	void run();
};




#endif
