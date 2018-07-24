#ifndef LIBRARY_HPP_INCLUDED
#define LIBRARY_HPP_INCLUDED

#include "Book.hpp"

class Library {
    private:
        Book* m_bookList;
        int m_arraySize;
        int m_bookCount;

    public:
        Library();
        ~Library();
        void DeallocateMemory();
        void AllocateMemory(int size);
        void ResizeArray();
        int GetArraySize();
        int GetBookCount();
        bool isArrayFull();

		void DisplayBooksWithIndex();
		void Run();
		void MainMenu();
		void NewBook();
		void UpdateBook();
		void ViewAllBooks();
		void ViewStats();

		void SaveData();
		void LoadData();
};


#endif // LIBRARY_HPP_INCLUDED
