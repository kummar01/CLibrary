#include <iostream>
#include "bookType.h"
#include <iomanip>
#include <string>
#include <cstdlib>

#include <fstream>
using namespace std;


void getBookData(bookType books[], int& noOfBooks);
void printBookData(bookType books[], int noOfBooks);
void searchBookData(bookType books[], int bookCount);
void searchBookDataByISBN(bookType books[], int bookCount, string ISBN,
                         int& loc);
void searchBookDataByTitle(bookType books[], int bookCount, string title,
                            int& loc);
void updateCopiesInStock(bookType books[], int bookCount);
void showMenu();
void subMenu();
int main() {
   bookType Books[100];// array to store up to 100 books
   int noOfBooks=4;//variable to store the number of books in the array
    int Users_Choice;//variable to store the user’s choice when they use the menu
    cout<<fixed<<showpoint<<setprecision(2);
    getBookData(Books,noOfBooks);//break occurs before here why???????????????????????
  
    showMenu();//show user the main menu
    
    cin>>Users_Choice;
    while(Users_Choice!=9)
    {
	switch(Users_Choice)
       {
       	case 1:
       		for (int i=0; i<noOfBooks;i++)
			   Books[i].printbookTitle();
       		break;
       		
       	case 2:
       		for (int i=0; i<noOfBooks;i++)
       		Books[i].printbookTitleAndISBN();
       		break;
       	case 3:
       	    searchBookData(Books, noOfBooks);
       		break;
       	case 4:
       	   updateCopiesInStock(Books, noOfBooks);
       		break;
       	case 5:
       	    for (int i=0; i<noOfBooks;i++)
       	    	Books[i].printInfo(); 
			   break;
		default: break; 	
	   }
    	showMenu();
		cin>>Users_Choice;
	}
	
	//infile.close();
    return 0;
}
void getBookData(bookType books[], int& noOfBooks)
{
    string title;
    string ISBN;
    string Publisher;
    int PublishYear;
    string auth[4];
    double cost;
    int copies;
    int authorCount;
    int i, j;
    char ch;
   
    ifstream infile;
    infile.open("bookData.txt");
    if (!infile)
    {
    	cout<<"There is a problem with the input file "<<endl;
    	return ;
    }
        infile >> noOfBooks;
        infile.get(ch);
     
    for (i = 0; i < noOfBooks; i++)
    {
        getline(infile, title);
        getline(infile,ISBN);
        getline(infile,Publisher);
        infile >> PublishYear >> cost >> copies >> authorCount;
        infile.get(ch);

        for (j = 0; j < authorCount; j++)
            getline(infile, auth[j]);

        books[i].setBookInfo(title, ISBN, Publisher, 
                             PublishYear, auth, cost, copies, 
                             authorCount);
    }
}



void searchBookData(bookType books[], int bookCount)
{
    int choice;
    char ch;
     
    int loc;

    string str;
    subMenu();
       
    cin>>choice;
    
    switch(choice)
       {
       	case 1:
       		cout<<"Enter the ISBN of the book"<<endl;
       		cin>>str;
			searchBookDataByISBN(books,bookCount,str,loc);
       		if (loc !=-1)
       		{cout<<"The store sells this book"<<endl;
       		break;
       		}
       		else
       		{cout<<"The store does not sells this book";
       		break;}
       	case 2:
       		cout<<"Enter the title of the book"<<endl;
       		cin.get(ch);
        	getline(cin,str);
       		searchBookDataByTitle(books,bookCount,str,loc);
       		if (loc !=-1)
       		{cout<<"The store sells this book"<<endl;}
       		else
       		{cout<<"The store does not sells this book";
       		break;}
       default: break; 
        }
        
}
void searchBookDataByISBN(bookType books[], int bookCount, string ISBN, int& loc)
//This is the code to locate the index of the books array where the ISBN is found 
{
    int i;
    loc = -1;

    for (i = 0; i < bookCount; i++)
        if (books[i].isISBN(ISBN))
        {
            loc = i;
            break;
        }
}
void searchBookDataByTitle(bookType books[], int bookCount, string title, int& loc)
//This is the code to locate the index of the books array where the Title is found 
{
        int i;
       loc = -1;

    for (i = 0; i < bookCount; i++)
        if (books[i].isTitle(title))
        {
            loc = i;
            break;
        }
}
void updateCopiesInStock(bookType books[], int bookCount)
{
    int choice;

    int loc;

    int count;
    char ch;

    string str;
    subMenu();
    cin>>choice;
     switch(choice)
       {
       	case 1:
       		cout<<"Enter the ISBN of the book"<<endl;
       		cin>>str;
			searchBookDataByISBN(books, bookCount,str,loc);
       		if (loc !=-1)
       		{cout<<"Enter the number of books ";
       		cin>>count;//might be confusion here
       		books[bookCount].updateQuantity(count);
       		break;
			}
       		else
       		cout<<"The store does not sells this book";
       		break;
       	case 2:
       		cout<<"Enter the title of the book"<<endl;
       		cin.get(ch);
        	getline(cin,str);
			searchBookDataByTitle(books,bookCount,str,loc);
       		if (loc !=-1)
       		{cout<<"Enter the number of books ";
       		cin>>count;
       		books[bookCount].updateQuantity(count);}
       		else
       		cout<<"The store does not sells this book";
       		break;
       	default: break; 
   }
   
}
void printBookData(bookType books[], int noOfBooks)
{
	for (int i=0; i<noOfBooks;i++)
	books[i].printInfo();
	
}
void showMenu()
{
cout<<"Welcome to Rock's Book Store"<<endl;
cout<<"To make a selection enter the number and press enter"<<endl;
cout<<"1: Print a list of books"<<endl;
cout<<"2: Print a list of books and ISBN numbers"<<endl;
cout<<"3: To see if a book in store"<<endl;
cout<<"4: To update the number of copies of a book"<<endl;
cout<<"5: To print books data"<<endl;
cout<<"9: Exit the program."<<endl;
}
void subMenu()
{
	cout<<"Enter"<<endl;
cout<<"1: To search the book by ISBN"<<endl;
cout<<"2: To search the book by title"<<endl;
}
