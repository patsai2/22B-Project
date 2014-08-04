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
#include "Module.h"


using namespace std;


Cashier::Cashier(Inventory &inventory): inventory(&inventory)
{
}

void Cashier::run()
{
    string isbn;           //book title
    int x;                      //quantity of books
   
    double tax;
    tax=.0862;
    double finalTotal;
    int exit=0;
    int answer;
    vector<const Book*> purchasedBooks;
    vector<int> quantities;
    double subt = 0.0;
    
    
    cout << "Serendipity Book Sellers" <<endl;
    cout << endl;
    cout << "Date:"<<" "<< __DATE__ << endl;                    //printing out Date and Time
    cout << "Time:"<< " "<< __TIME__ << endl;
    
    cout << endl;
    
    while(exit==0)                                              //loop to have user enter another book
    {
        
        cout << "Select which book to purchase: " << endl;

        vector<const Book*> books = inventory->getBooks();
        

        cout<< "Enter ISBN of the book you like to purchase?" << endl;             //asking user for isbn
        cin >> isbn;
        cout<<"How many books with that title would you like to purchase?" << endl; //asking user for quantity
        cin>>x;
        
   
        const Book *book=inventory->getBook(isbn);
        if(book==NULL)                                      //isbn does not match inventory, cout invalid
        {
            cout<<"Invalid ISBN"<<endl;
            cout<<"Would you like to try again Y/N?"<<endl;
            char answer2;
            cin>>answer2;
            if(answer2== 'Y' || 'y')
            {
                continue;
            }
            else
                exit=1;
        }
        
        else
        {
        if(book->qty<x)
        {
            cout<<"Do not have that many books in stock" <<endl;
            continue;
        }
            
            purchasedBooks.push_back(book);
            quantities.push_back(x);
            inventory->remove(book, x);                //removing book from inventory
           
            cout<<"Would you like to purchase another book? Enter 1 for YES or NO for checking out." << endl;    //asking user if they want to purchase another book
            cin>>answer;
            if(answer==0)
            {
                exit=1;                                              //exiting while loop
            }
            else continue;
          
   }
        
        cout << "Serendipity Book Sellers" <<endl;
        cout << endl;
        cout << "Date:"<<" "<< __DATE__ << endl;                                        //printing out date
        
        cout<<"Qty     ISBN            Title           Price         Total" <<endl;
        cout<<"-----------------------------------------------------------"<<endl;
        
        for(size_t i=0; i<purchasedBooks.size(); i++)
        {
            double total=book->price*x;
            subt=subt+total;
            
            cout<<"   "<<x << book->isbn << "          "<< book->title<<"     "<< book->price<<"     "<< total<<endl;
            //calculating total of price multiplied by quantity
        }
        
        
        
       finalTotal=(tax*subt)+subt;                                    //calculating final total with tax
       cout<< endl<<endl;
       cout<<"Subtotal:"<<" "<< subt << endl;                    //subtotal equals total
       cout<<"Tax:"<<" "<< tax*subt << endl;                           //tax is .0862
       cout<<"Final Total:"<<" "<< finalTotal << endl;                  //final total is tax*total
       cout<<endl;
       cout<< "Thanks For Shopping at Serendipity.";
   
   }
    
}


