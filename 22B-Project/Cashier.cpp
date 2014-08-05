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
#include "Inventory.h"
#include "Book.h"
#include "Module.h"
#include <iomanip>
#include <ctime>

using namespace std;

Cashier::Cashier(Inventory &inventory): inventory(&inventory){}

void Cashier::run()
{
    
    string line;
    bool valid;
    string isbn;
    int x;
    int keepgoing=1;
    vector<Book> purchasedBooks;
    double finalTotal=0;
    double subt=0.0;
    double tax=.0862;
    
    
    
    cout <<endl;
    cout << "Serendipity Book Sellers" <<endl;
    
    vector<const Book*> books = inventory->getBooks();      //call getBooks function to find book
    while(keepgoing==1)
    {
        const Book *book = nullptr;
        
        do{
            cout<<"Please enter the ISBN of the book you would like to purchase."<<endl;
            getline(cin, isbn);
            book=inventory->getBook(isbn);
            
            if(book==NULL)                              //checking to see if book exists
            {
                cout<<"Invalid ISBN"<<endl;
            
                do{
                    cout<<"Would you like to try again Y/N? "<<endl;
                    string answer2;
                    getline(cin, answer2);
                    try
                    {
                        if(answer2=="N" || answer2=="n")
                        {
                            valid=true;
                            keepgoing=0;
                            break;
                        }
                        if(answer2 != "Y" || answer2!="y" || answer2!="N" || answer2!="n")
                        {
                            cout<<"Invalid"<<endl;
                            valid=false;
                        }
                        else valid=true;
                    }
                    catch(exception e)
                    {
                        cout<<"Invalid. Please enter Y to enter another ISBN or N to check out. Enter quit to quit the program.";
                        valid=false;
                    }
                }while(!valid);
            }//end of if statement
            
        }while(!book);
        
        if(keepgoing==0)
        {
            break;
        }
    
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
        
        if(book->qty<x)
        {
            cout<<"Do not have that many books in stock" <<endl;
            continue;
        }
        
        purchasedBooks.push_back(inventory->remove(book, x));
       
        do{
            cout<<"Enter Y: Add another book to my cart."<<endl;
            cout<<"Enter N: Check out"<<endl;
            string answer3;
            getline(cin, answer3);
            try
            {
                if(answer3=="y" || answer3=="Y")
                {
                    keepgoing=1;
                    valid=true;
                    break;
                }
                if(answer3=="N" || answer3=="n")
                {
                    valid=true;
                    keepgoing=0;
                }
                else
                {
                    cout<<"Invalid"<<endl;
                    valid=false;
                }
            }                                                               //end of try
            catch(exception e)
            {
                cout<<"Invalid." <<endl;
                cout<< "Enter Y: To put another book in your cart."<<endl;
                cout<<"Enter N: To check out." <<endl;
                valid=false;
            }
        }while(!valid);
        
    if(keepgoing==1)
    {
        continue;
    }
    if(keepgoing==0)
    {
        break;
    }
}//end of keepgoing while loop
    
    time_t timer=time(0);
    cout << "Serendipity Book Sellers" <<endl;
    cout << endl;
    cout << "Date:"<< ctime(&timer) <<endl;                             //FIX DATE
    
    cout<<"Qty     ISBN                 Title                       Price         Total" <<endl;
    cout<<"----------------------------------------------------------------------"<<endl;
    
    for(size_t i=0; i<purchasedBooks.size(); i++)
    {
        Book& b=purchasedBooks[i];
        double total=b.price*x;
        subt=subt+total;
        
        cout<<setw(2)<<b.qty <<" "<< b.isbn << " "<< setw(53)<<b.title<<setw(12)<< b.price<<setw(6)<< total<<endl;
    } //end of for loop//3, 11, 7, 6 for total---80 spaces total
    
    
    finalTotal=(tax*subt)+subt;                                 //calculating final total with tax*subt
    cout<< endl <<endl;
    cout<<"Subtotal: $" << fixed << setprecision(2) << subt << endl;
    cout<<"Tax: $" << (tax*subt) << endl;
    cout<<"Final Total: $" << finalTotal << endl;
    cout<<endl;
    cout<< "Thanks For Shopping at Serendipity.";
    
    return;
    
}
