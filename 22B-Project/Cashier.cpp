//
//  Cashier.cpp
//  ClassProjectCIS22B
//
//  Created by Monica Metzger on 7/29/14.
//  Copyright (c) 2014 Monica Metzger. All rights reserved.
//

#include "Cashier.h"
#include <iostream>
#include "stdio.h"
#include "Inventory.h"


using namespace std;


Cashier::Cashier(Inventory &inventory): inventory(&inventory)
{
}

void Cashier::run()
{
    int booknumber;           //book title
    int x;                      //quantity of books
    
    
    cout << "Serendipity Book Sellers" <<endl;
    cout << endl;
    cout << "Date:"<<" "<< __DATE__ << endl;
    cout << "Time:"<< " "<< __TIME__ << endl;
    
    cout << endl;
    cout<< "Which Book would you like purchase?" << endl;
    cout << endl;
	cout << "Here are your choices: " << endl;

    vector<const Book*> books = inventory->getBooks();
    for (size_t i = 0; i < books.size(); i++)
    {
		cout << i + 1 << ". " << books[i]->qty << " x "
        << books[i]->title << " by " << books[i]->author
        << " added on " << ctime(&books[i]->date);
    }

    cout<< "Which Book number would you like to purchase?" << endl;
    cin >> booknumber;
    cout<<"How many books with that title would you like to purchase?" << endl;
    cin>>x;
   
    if(booknumber>books.size() || booknumber < 1)              //need to find book, redo if statement
    {
        cout<<"Invalid Name"<<endl;
    }
   else
   {
  //  Book *book= const books[booknumber-1];
       
     cout << "Serendipity Book Sellers" <<endl;
     cout << endl;
     cout << "Date:"<<" "<< __DATE__ << endl;
     cout<<"Qty     ISBN            Title           Price         Total" <<endl;
     cout<<"-----------------------------------------------------------"<<endl;
     cout<<"     "<<books[booknumber-1]->qty << books[booknumber-1]->isbn<< books[booknumber-1]->title<< books[booknumber-1]->price<< total<endl;     //print out info they need
     cout<< endl<<endl;
    // cout<<"Subtotal:"<<" "<<  << endl;
    //  cout<<"Tax:"<<" "<< print out tax << endl;
     //cout<<"Total:"<<" "<< print out total << endl;
     cout<<endl;
     cout<< "Thanks For Shopping at Serendipity.";
    inventory->remove(books[booknumber-1], x-1);
   }
}


