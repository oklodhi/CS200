#ifndef BOOK_HPP_INCLUDED
#define BOOK_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

enum ReadingStatus { NOT_STARTED = 0, READING = 1, FINISHED = 2 };
enum PurchaseStatus { OWNED = 0, WISHLIST = 1 };

class Book {
    private:
        string m_title;
        string m_author;
        ReadingStatus m_readingStatus;
        PurchaseStatus m_purchaseStatus;


    public:
        void DisplayBook();
        int GetPurchaseStatus();
        string GetPurchaseStatusString();
        int GetReadingStatus();
        string GetReadingStatusString();
        string GetTitle();
        string GetAuthor();
        void SetBookInfo (const string& title, const string& author);
        void SetPurchaseStatus (PurchaseStatus ps);
        void SetReadingStatus (ReadingStatus rs);
};

#endif // BOOK_HPP_INCLUDED
