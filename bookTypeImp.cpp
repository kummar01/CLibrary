
#include <iostream>
#include "bookType.h"
#include <iomanip>
#include <string>
#include <cstdlib>

#include <fstream>
using namespace std;


void bookType::setBookInfo(string title, string ISBN, 
					 string Publisher, int PublishYear,
					 string auth[], double cost, int copies,
					 int authorCount)
{
	booktitle = title;
	bookISBN=ISBN;
	bookPublisher=Publisher;
	bookPublishYear=PublishYear;
	for (int i=0;i<4;i++)
	{authors[i]=auth[i];}
	price=cost;
	quantity=copies;
	noOfAuthors=authorCount;
}
void bookType::setBookTitle(string s)
{
    booktitle =  s;
}
void  bookType::setBookISBN(string s)
{
	bookISBN=s;
}
void bookType::setBookPrice(double cost)
{
	(price);
}
void bookType::setCopiesInStock(int noOfCopies)
{
	(quantity);
}
void bookType::printInfo() const
{
	cout<<"Title: "<<booktitle<<endl;
	cout<<"ISBN: "<<bookISBN<<endl;
    cout<<"Publisher: "<<bookPublisher<<endl;
	cout<<"Year of Publication: "<<bookPublishYear<<endl;
	cout<<"Number of Authors: "<<noOfAuthors<<endl;
	for (int i=0;i<3;i++)
	{cout<<"Authors: "<<authors[i]<<endl;}
	cout<<"Price: "<<price<<endl;
	cout<<"Quantities in stock: "<<quantity<<endl;
		
}
bool bookType::isISBN(string s) const
{
    return (bookISBN == s);
}
bool bookType::isTitle(string s) const
{
    return (booktitle == s);
}
bool bookType::isAuthor(string s) const
{
    bool found = false;
    int i;
    for (i = 0; i < noOfAuthors; i++)
        if (authors[i] == s)
        {
            found = true;
            break;
        }
    return found;
}

void bookType::getBookTitle(string& s) const
{
    s = booktitle;
}

double bookType::getBookPrice() const
{
    return price;
}
void bookType::getBookISBN(string& s) const
{
	s = bookISBN;
}
bool bookType::isInStock() const
{
    return (quantity > 0);
}
void bookType::makeSale()
{
    quantity--;
}
void bookType::printBookPrice() const
{
    cout << "Price = " << price << endl;
}
void bookType::printbookTitle() const
{
	cout << "Book Title = " << booktitle << endl;
}
void bookType::printbookTitleAndISBN() const
{

	cout << "ISBN = " << bookISBN <<" Book Title = " << booktitle<<endl;
	
}
void bookType::updateQuantity(int addBooks)
{
    quantity = quantity + addBooks;
}
void bookType::showQuantityInStock() const
{
	cout << "Quantity = " << quantity << endl;
}
bookType::bookType()
{
    int i;

    booktitle = "";
    bookISBN = "";
    bookPublisher = "";

    bookPublishYear = 1900;

    noOfAuthors = 0;

    for (i = 0; i < 4; i++)
        authors[i] = "";

    price = 0;
    quantity = 0;
}

