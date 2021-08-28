#include <string>
using namespace std;
class bookType 
{
public:
    void setBookInfo(string title, string ISBN, 
					 string Publisher, int PublishYear,
					 string auth[], double cost, int copies,
					 int noAuthors);
    void setBookTitle(string s);
    void setBookISBN(string s);
    void setBookPrice(double cost);
    void setCopiesInStock(int noOfCopies);

    void printInfo() const;

    bool isISBN(string s) const;
    bool isTitle(string s) const;
    bool isAuthor(string s) const;

    void getBookTitle(string& s) const;
    void getBookISBN(string& s) const;
    double getBookPrice() const;

    bool isInStock() const;
    void makeSale();

    void printBookPrice() const;
    void printbookTitle() const;
    void printbookTitleAndISBN() const;
    void showQuantityInStock() const;
    void updateQuantity(int addBooks);
        
    bookType();

private:
    string booktitle;
    string bookISBN;
    string bookPublisher;
    int bookPublishYear;
    string authors[4];

    double price;
    int quantity;

    int noOfAuthors;
};
