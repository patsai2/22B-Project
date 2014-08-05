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
    vector<const Book*> purchasedBooks;
    vector<int> quantities;
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
        cin>>isbn;
        //getline(cin, isbn);
        
        do {
            cout<<"How many books with that title would you like to purchase?" << endl; //asking user for quantity
            cin>>line;
            //getline(cin, line);
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
                cout<<"Would you like to try again Y/N? Or, Enter quit to quit."<<endl;
                string answer2;
                getline(cin, answer2);
                try
                {
                    if(answer2 != "Y" || "y" || "quit")
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
            do{
                
                cout<<"Enter 1:To put another book in your cart"<<endl
                <<"Enter 2: To quit out of program and return to main menu."<<endl
                <<"Enter 3: To check out"<<endl;
                
                int answer3;
                cin>>answer3;
                try
                {
                    if(answer3==1)
                    {
                        continue;
                    }
                    if(answer3==2)
                    {
                        return;
                    }
                    if(answer3==3)
                    {
                        break;
                    }
                    if(answer3 != 1 || 2 || 3)
                    {
                        cout<<"Invalid"<<endl;
                        valid=false;
                    }
                    else valid=true;
                }
                catch(exception e)
                {
                    cout<<"Invalid. Enter 1:To put another book in your cart"<<endl
                    <<"Enter 2: To quit out of program and return to main menu."<<endl
                    <<"Enter 3: To check out";
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
        const Book *b=purchasedBooks[i];
        int q=quantities[i];
        double total=b->price*x;
        subt=subt+total;
        
        cout<<"   "<<q<< "  " << b->isbn << "          "<< b->title<<"     "<< b->price<<"     "<< total<<endl;
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
