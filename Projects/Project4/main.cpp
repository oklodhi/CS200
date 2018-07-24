#include <iostream>

using namespace std;

#include "Book.hpp"
#include "Library.hpp"

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

void Phase2_Test1() {
    Library lib;
    lib.AllocateMemory(10);
    lib.GetArraySize();

    Library lib2;
    lib2.AllocateMemory(5);
    lib2.ResizeArray();
    lib2.GetArraySize();
}

void Phase3_Test1() {
	Library library;
	library.Run();
}

void Phase4_Test1() {
    Library library;
    library.Run();
}

int main() {
    //Phase1_Test1();
    //Phase2_Test1();
    //Phase3_Test1();
    Phase4_Test1();

	return 0;
}
