#include <iostream>

using namespace std;

#include "Book.hpp"

void Phase1_Test1() {
    Book book1;
    book1.SetBookInfo("Harry Potter", "J.K. Rowling");
    book1.GetTitle();
    book1.GetAuthor();

    Book book2;
    book2.SetPurchaseStatus(OWNED);
    book2.GetPurchaseStatus();
    book2.GetPurchaseStatusString();

    Book book3;
    book3.SetReadingStatus(FINISHED);
    book3.GetReadingStatus();
    book3.GetReadingStatusString();

    Book book4;
    book4.SetBookInfo("Game of Thrones", "George R. R. Martin");
    book4.SetReadingStatus(READING);
    book4.SetPurchaseStatus(WISHLIST);
    book4.DisplayBook();
}

int main() {
    Phase1_Test1();

    return 0;
}
