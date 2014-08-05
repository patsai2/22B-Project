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
    bool valid;
    
    
    cout << "Serendipity Book Sellers" <<endl;
    cout << endl;
    cout << "Date:"<<" "<< __DATE__ << endl;                    //printing out Date and Time
    cout << "Time:"<< " "<< __TIME__ << endl;
    
    cout << endl;
    
    while(exit==0)                                              //loop to have user enter another book
    {
        vector<const Book*> books = inventory->getBooks();      //call getBooks function to find book
        cout<< "Enter ISBN of the book you like to purchase?" << endl;             //asking user for isbn
        getline(cin, isbn);
        do{
           cout<<"How many books with that title would you like to purchase?" << endl; //asking user for quantity
            string line;
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
        if(book==NULL)                                      //isbn does not match inventory, cout invalid
        {
            cout<<"Invalid ISBN"<<endl;
        }
            /*cout<<"Would you like to try again Y/N? Or, Hit 1 to quit."<<endl;
            char answer2;
            cin>>answer2;
            if(answer2== 'Y' || 'y')
            {
                continue;
            }
            else if(
            else
                exit=1;
                    }*/
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
                                cout<<"Invalid quantity. Need Valid number";
                                valid=false;
                            }
                        }while(!valid);
                    
                    
                    
                    
                    
 //<< endl; //asking user for quantity
                        string line;
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
            const Book *b=purchasedBooks[i];
            int q=quantities[i];
            double total=book->price*x;
           
            subt=subt+total;
            
            cout<<"   "<<q<< " " << b->isbn << "          "<< b->title<<"     "<< b->price<<"     "<< total<<endl;
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


