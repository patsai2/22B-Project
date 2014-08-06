/*
 Print out Store Name statement
 Ask User to enter ISBN number of book they want to purchase
 do/while loop to ask user the quantity of books they want to purchase
 Use try catch to make sure they enter valid number
 Else keep asking for a valid ISBN. 
 Ask User the quantity they want to buy.
 Check to see if the quantity the user wants is in the inventory.
 Try and catch to make sure they are inputting a valid character.
 If not, ask user to input a new isbn and then a new quantity.
 Ask User if they would like to purchase another book or Check out. 
 Receive input and make sure it is a valid character. 
 If User wants to purchase another book, go back to beginning and ask the user to enter an ISBN.
 If User wants to check out, print out Check out screen.
 For loop print out all the books they want to buy with the quantity, isbn, title, price and total. 
 Calculate total, subtotal, tax, and final total.
 Print out calculations.
 Return to main menu.
 */

#define _CRT_SECURE_NO_WARNINGS

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
    bool valid=false;
    string isbn;
    int x=0;
    int keepgoing=1;
    vector<Book> purchasedBooks;
    double finalTotal=0;
    double subt=0.0;
    double tax=.0862;
    
    
    
    cout <<endl;
    cout << "Serendipity Book Sellers" <<endl;
    
    vector<const Book*> books = inventory->getBooks();                //call getBooks function to find book
    while(keepgoing==1)
    {
        const Book *book = nullptr;
        //do while loop to ask user to input ISBN. Checking to make sure it was a valid input.
        do{
            cout<<"Please enter the ISBN of the book you would like to purchase."<<endl;    //asking user for input of ISBN
            getline(cin, isbn);
            book=inventory->getBook(isbn);
            
            if(book==NULL)                                            //checking to see if book exists in inventory
            {
                cout<<"Invalid ISBN OR Book not in stock."<<endl;
            
                do{
                    cout<<"Would you like to try again Y/N? "<<endl;  //quering user if they want to enter a valid ISBN again
                    string answer2;
                    getline(cin, answer2);
                    try                                               //try catch to make sure User entered valid number
                    {
                        if(answer2=="Y" || answer2=="y")
                        {
                            keepgoing=1;
                            valid=true;
                        }
                        else if(answer2=="N" || answer2=="n")
                        {
                            keepgoing=0;
                            valid=true;
                            
                        }
                        else
                        {
                            cout<<"Invalid"<<endl;
                            valid=false;
                        }
                    }
                    catch(exception e)
                    {
                        cout<<"Invalid. Please enter Y to enter another ISBN or N to check out. Enter quit to quit the program." << endl;
                        valid=false;
                    }
                }while(!valid);
            }//end of if statement
            
            if(keepgoing==0)
                break;
            else
                continue;
        }while(!book);
        
        if(keepgoing==0)
            break;
       
    
        do {
            cout<<"How many books with that title would you like to purchase?" << endl; //asking user for quantity
            getline(cin, line);
            try                                                            //try catch to make sure User entered valid number
            {
                x=stoi(line);                                              //receive string. convert string to integer.
                if(x<0)                                                    //Test on integer

                {
                    cout<<"Invalid"<<endl;
                    valid=false;
                }
                if(book->qty<x)                                            //checking to see if the quantity the user has inputed is available in inventory
                {
                    cout<<"Do not have that many books in stock." <<endl;
                    valid=false;
                }
                else valid=true;
            }
            catch(exception e)
            {
                cout<<"Invalid quantity. Please enter valid number. " << endl;
                valid=false;
            }
          
        }while(!valid);
        
        purchasedBooks.push_back(inventory->remove(book, x));                //removing book and quantity from inventory
       
        do{
            cout<<"Enter Y: Add another book to my cart."<<endl;             //asking user if they want to purchase another book or check out.
            cout<<"Enter N: Check out"<<endl;
            string answer3;
            getline(cin, answer3);
            try                                                               //try and catch to see if answer is valid
            {
                if(answer3=="y" || answer3=="Y")                              //If aswered Y, ask again
                {
                    keepgoing=1;
                    valid=true;
                    break;
                }
                if(answer3=="N" || answer3=="n")                               //If answered N, check out
                {
                    valid=true;
                    keepgoing=0;
                }
                else
                {
                    cout<<"Invalid"<<endl;
                    valid=false;
                }
            }                                                                   //end of try
            catch(exception e)
            {
                cout<<"Invalid." <<endl;
                cout<< "Enter Y: To put another book in your cart."<<endl;
                cout<<"Enter N: To check out." <<endl;
                valid=false;
            }
        }while(!valid);
        
    if(keepgoing==1)                                                            //go back up to top of loop
    {
        continue;
    }
    if(keepgoing==0)                                                            //break loop
    {
        break;
    }
}//end of keepgoing while loop
    
    time_t timer=time(0);                                                       //variable for time and date
    cout << "Serendipity Book Sellers" <<endl;
    cout << endl;
    cout << "Date:"<< ctime(&timer) <<endl;                                     //prints out current data and time
    
    cout<<" Qty  ISBN       Title                                           Price   Total" <<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    
    for(size_t i=0; i<purchasedBooks.size(); i++)                               //for loop to traverse through purchased books
    {                                                                           //printa out all their information

        Book& b=purchasedBooks[i];
        double total=b.price*b.qty;                                                 //calculating total
        subt=subt+total;                                                        //calculating subtotal
        
        cout<<" "<<left<<setw(2)<< fixed << setprecision(2) <<b.qty <<"   "<< b.isbn << " "<< setw(40)<<b.title.substr(0, 40)<<setw(8)<<"       $"<< b.price<<setw(2)<<"  $" <<total<<endl;                                                       //printing out all information of each book
    } //end of for loop
    
    
    finalTotal=(tax*subt)+subt;                                                 //calculating final total with tax*subt
    cout<< endl <<endl;
    
    //printing out subtotal, tax, final total
    cout<<"Subtotal: $" << fixed << setprecision(2) << subt << endl;
    cout<<"Tax: $" << (tax*subt) << endl;
    cout<<"Final Total: $" << finalTotal << endl;
    cout<<endl;
    cout<< "Thanks For Shopping at Serendipity." <<endl;
    cout<<endl;
    return;
    
}
