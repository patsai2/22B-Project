//
//  Cashier.cpp
//  ClassProjectCIS22B
//
//  Created by Monica Metzger on 7/29/14.
//  Copyright (c) 2014 Monica Metzger. All rights reserved.
//
/*
 Print out Welcome statement with date and time
 
 */
#include "Cashier.h"
#include <iostream>
#include "stdio.h"
#include "Inventory.h"
#include "Book.h"
#include "Module.h"


using namespace std;

Cashier::Cashier(Inventory &inventory): inventory(&inventory){}

void Cashier::run()
{
    
    string line;
    bool valid;
    string isbn;
    int x;
    int keepgoing=0;
    vector<Book> purchasedBooks;
    double finalTotal=0;
    double subt=0.0;
    double tax=.0862;
    
    cout <<endl;
    cout << "Serendipity Book Sellers" <<endl;
    cout << endl;
    //print out time and date
    
    vector<const Book*> books = inventory->getBooks();      //call getBooks function to find book
    while(keepgoing==0)
    {
        
        cout<<"Please enter the ISBN of the book you would like to purchase."<<endl;
        getline(cin, isbn);
        
        do {
            cout<<"How many books with that title would you like to purchase?" << endl; //asking user for quantity
            getline(cin, line);
            try
            {
                x=stoi(line);
                if(x<0)
                {
                    cout<<"Invalid"<<endl;
                    valid=false;
                }
                else valid=true;
            }
            catch(exception e)
            {
                cout<<"Invalid quantity. Need Valid number";
                valid=false;
            }
        }while(!valid);
        
        
        const Book *book=inventory->getBook(isbn);
        
        if(book==NULL)                              //checking to see if book exists
        {
            cout<<"Invalid ISBN"<<endl;
            
            do{
                cout<<"Would you like to try again Y/N? "<<endl;
                string answer2;
                getline(cin, answer2);
                try
                {
                    if(answer2 != "Y" || "y" || "N" || "n")
                    {
                        cout<<"Invalid"<<endl;
                        valid=false;
                    }
                    if(answer2=="N" || "n")
                    {
                        keepgoing=1;
                        break;
                    }
                    else valid=true;
                }
                catch(exception e)

                {
                    cout<<"Invalid. Please enter Y to enter another ISBN or N to check out. Enter quit to quit the program.";
                    valid=false;
                }
            }while(!valid);
            
        }
        
        else
        {
            if(book->qty<x)
            {
                cout<<"Do not have that many books in stock" <<endl;
                continue;
            }
            
            purchasedBooks.push_back(inventory->remove(book, x));
            do{
                
                cout<<"Enter Y: Add another book to my cart."<<endl
                <<"Enter N: Check out"<<endl;
                string answer3;
                getline(cin, answer3);
                try
                {
                    if(answer3=="y" || "Y")
                    {
                        continue;
                    }
                    /*  if(answer3=="N" || "n")
                     {
                     valid=true;
                     }*/
                    if(answer3 != "N" || "n" || "y" || "Y" )
                    {
                        cout<<"Invalid"<<endl;
                        valid=false;
                    }
                    else valid=true;
                }                                                               //end of try
                catch(exception e)
                {
                    cout<<"Invalid." <<endl;
                    cout<< "Enter Y: To put another book in your cart."<<endl;
                    cout<<"Enter N: To check out." <<endl;
                    valid=false;
                }
            }while(!valid);
        }
    }                                                                        //end of keepgoing while loop
    
    cout << "Serendipity Book Sellers" <<endl;
    cout << endl;
    cout << "Date:"<<" "<< __DATE__ << endl;                             //FIX DATE
    
    cout<<"Qty     ISBN            Title           Price         Total" <<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    
    for(size_t i=0; i<purchasedBooks.size(); i++)
    {
        Book& b=purchasedBooks[i];
        double total=b.price*x;
        subt=subt+total;
        
        cout<<"   "<<b.qty<< "  " << b.isbn << "          "<< b.title<<"     "<< b.price<<"     "<< total<<endl;
    }       //end of for loop
    
    
    finalTotal=(tax*subt)+subt;                                 //calculating final total with tax*subt
    cout<< endl<<endl;
    cout<<"Subtotal:"<<" "<< subt << endl;
    cout<<"Tax:"<<" "<< (tax*subt) << endl;
    cout<<"Final Total:"<<" "<< finalTotal << endl;
    cout<<endl;
    cout<< "Thanks For Shopping at Serendipity.";
    
    return;
    
}
