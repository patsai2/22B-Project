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
#include "Book.h"


using namespace std;


Cashier::Cashier(Inventory &inventory): inventory(&inventory)
{
}

void Cashier::run()
{
    int booknumber;           //book title
    int x;                      //quantity of books
    float total=0;
    float tax;
    tax=.0862;
    float finalTotal;
    int exit=0;
    int answer;
    
    cout << "Serendipity Book Sellers" <<endl;
    cout << endl;
    cout << "Date:"<<" "<< __DATE__ << endl;                    //printing out Date and Time
    cout << "Time:"<< " "<< __TIME__ << endl;
    
    cout << endl;
    
    while(exit==0)                                              //loop to have user enter another book
    {
        
        cout<< "Which Book would you like purchase?" << endl;
        cout << endl;
        cout << "Here are your choices: " << endl;

        vector<const Book*> books = inventory->getBooks();
        for (size_t i = 0; i < books.size(); i++)               //for loop that prints out all the book titles, authors, date and quantity
        {
            cout << i + 1 << ". " << books[i]->qty << " x "
            << books[i]->title << " by " << books[i]->author
            << " added on " << ctime(&books[i]->date);
        }

        cout<< "Which Book number would you like to purchase?" << endl;             //asking user for book title number
        cin >> booknumber;
        cout<<"How many books with that title would you like to purchase?" << endl; //asking user for quantity
        cin>>x;
   
        if(booknumber>books.size() || booknumber < 1)              //need to find book, redo if statement
        {
            cout<<"Invalid Name"<<endl;
            continue;
        }
        else
        {
       
       int q=books[booknumber-1]->qty;                              //q equals qty from books class
       const long i= books[booknumber-1]->isbn;                     //i equals isbn number from books
       float price=books[booknumber-1]->price;                      //price equals price from books class
       total=price*q;                                               //calculating total of price multiplied by quantity
       
        cout << "Serendipity Book Sellers" <<endl;
        cout << endl;
        cout << "Date:"<<" "<< __DATE__ << endl;                                        //printing out date
    
        cout<<"Qty     ISBN            Title           Price         Total" <<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        cout<<"     "<<q << i<< books[booknumber-1]->title<< price<< total <<endl;     //print out info they need
       cout<<"Would you like to purchase another book? Enter 1 for YES or NO for checking out." << endl;    //asking user if they want to purchase another book
       cin>>answer;
       if(answer==0)
       {
           exit=1;                                              //exiting while loop
       }
   }
       finalTotal=tax*total;                                    //calculating final total with tax
       cout<< endl<<endl;
     cout<<"Subtotal:"<<" "<< total << endl;                    //subtotal equals total
     cout<<"Tax:"<<" "<< tax << endl;                           //tax is .0862
     cout<<"Total:"<<" "<< finalTotal << endl;                  //final total is tax*total
     cout<<endl;
     cout<< "Thanks For Shopping at Serendipity.";
    inventory->remove(books[booknumber-1], x-1);                //removing book from inventory
   }
    
}


