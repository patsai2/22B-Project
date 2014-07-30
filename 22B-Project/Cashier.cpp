//
//  Cashier.cpp
//  ClassProjectCIS22B
//
//  Created by Monica Metzger on 7/29/14.
//  Copyright (c) 2014 Monica Metzger. All rights reserved.
//

#include "Cashier.h"
#include <iostream>
//#include "stdio.h"
#include "Inventory.h"


using namespace std;


Cashier::Cashier(Inventory &inventory): inventory(inventory)
{

}

void Cashier::run()
{
    string booktitle;           //book title
    int x;                      //quantity of books
    cout << "Serendipity Book Sellers" <<endl;
    cout << endl;
    //cout << "Date:"<<" "<< __DATE__ << endl;
    //cout << "Time:"<< " "<< __TIME__ << endl;
    cout << endl;
    cout<< "Which Book would you like purchase?" << endl;
    cout << endl;
	cout << "Books: " << endl;
	
    vector<const Book*> books = getBooks();
    for (size_t i = 0; i < books.size(); i++)
    {
		cout << i + 1 << ". " << books[i]->qty << " x "
        << books[i]->title << " by " << books[i]->author
        << " added on " << ctime(&books[i]->date);
    }

    cout<< "Which Book would you like to purchase?" << endl;
    cin >> booktitle;
    cout<<"How many books with that title would you like to purchase?" << endl;
    cin>>x;
}


