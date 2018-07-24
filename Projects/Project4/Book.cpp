#include <iostream>

#include "Book.hpp"
void Book::SetBookInfo( const string& title, const string& author )
{
    m_title = title;
    m_author = author;
}

void Book::SetReadingStatus( ReadingStatus rs )
{
    m_readingStatus = rs;
}

void Book::SetPurchaseStatus( PurchaseStatus ps )
{
    m_purchaseStatus = ps;
}

void Book::DisplayBook()
{
    cout << "Title: \t\t" << m_title << endl;
    cout << "Author: \t" << m_author << endl;
    cout << "Status: \t" << GetPurchaseStatusString() << ", " << GetReadingStatusString() << endl << endl;
}

string Book::GetTitle()
{
    return m_title;
}

string Book::GetAuthor()
{
    return m_author;
}

int Book::GetReadingStatus()
{
    return m_readingStatus;
}

string Book::GetReadingStatusString()
{
    if (m_readingStatus == NOT_STARTED) {
            return "Not started";
        } else if (m_readingStatus == READING) {
            return "Reading";
        } else if (m_readingStatus == FINISHED) {
            return "Finished";
        }
}

int Book::GetPurchaseStatus()
{
    return m_purchaseStatus;
}

string Book::GetPurchaseStatusString()
{
    if (m_purchaseStatus == OWNED) {
        return "Owned";
    } else if (m_purchaseStatus == WISHLIST) {
        return "Wishlist";
    }
}
