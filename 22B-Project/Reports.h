#ifndef REPORTSMODULE_H
#define REPORTSMODULE_H

#include <string>
#include <vector>

#include "Module.h"
#include "Inventory.h"


class Reports : public Module
{
	Inventory *inventory;

public:
	Reports(Inventory& inventory);

	void run();

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
