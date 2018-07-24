#include <fstream>

#include "Library.hpp"
#include "Book.hpp"

using namespace std;

Library::Library() {
    m_bookList = nullptr;
    m_arraySize = 0;
    m_bookCount = 0;
    AllocateMemory(10);
}

Library::~Library() {
    DeallocateMemory();
}

void Library::DeallocateMemory() {
    if (m_bookList != nullptr) {
        delete [] m_bookList;
        m_bookList = nullptr;
        m_arraySize = 0;
        m_bookCount = 0;
    }
}

void Library::AllocateMemory(int size) {
    if (m_bookList != nullptr) {
        DeallocateMemory();
    }
    m_bookList = new Book[size];
    m_arraySize = size;
}

void Library::ResizeArray() {
    Book* biggerArray;
    biggerArray = new Book[m_arraySize + 10];
    for (int i = 0; i < m_arraySize; i++) {
        biggerArray[i] = m_bookList[i];
    }
    delete [] m_bookList;
    m_bookList = biggerArray;
    m_arraySize = m_arraySize + 10;
}

int Library::GetArraySize() {
    return m_arraySize;
}

int Library::GetBookCount() {
    return m_bookCount;
}

bool Library::isArrayFull() {
    if (m_bookCount == m_arraySize) {
        return true;
    } else if (m_bookCount < m_arraySize) {
        return false;
    }
}

void Library::DisplayBooksWithIndex() {
	for(int i = 0; i < m_bookCount; i++) {
		cout << i << ". \t" << m_bookList[i].GetTitle() << "\t " << m_bookList[i].GetAuthor() << endl;
	}
}

void Library::Run() {
	LoadData();
	MainMenu();
}

void Library::MainMenu() {
	bool isQuit = false;
	int inputChoice;

	while (isQuit == false) {
		cout << "------------------------- \n" << "| LIBRARY MAIN MENU | \n" << "------------------------- \n";
		cout << "1. Add new book" << endl;
		cout << "2. Update book" << endl;
		cout << "3. View stats" << endl;
		cout << "4. View all books" << endl;
		cout << "5. Save and quit" << endl;
		cout << "-------------------------- \n What do you want to do? \t";

		cin >> inputChoice;
		while (inputChoice < 1 || inputChoice > 5) {
			cout << "-------------------------- \n What do you want to do? \t";
			cin >> inputChoice;
		}
		if (inputChoice == 1) {
			NewBook();
		}
		else if (inputChoice == 2) {
			UpdateBook();
		}
		else if (inputChoice == 3) {
			ViewStats();
		}
		else if (inputChoice == 4) {
			ViewAllBooks();
		}
		else if (inputChoice == 5) {
			isQuit = true;
		}
	}

	SaveData();
}

void Library::NewBook() {
	if (isArrayFull() == true) {
		ResizeArray();
	}

	string title, author;
	int rs, ps;

	cout << "------------------------- \n" << "| ADD NEW BOOK | \n" << "------------------------- \n";

	cin.ignore();
	cout << "Enter book title: \t";
	getline(cin, title);
	cout << "Enter book author: \t";
	getline(cin, author);
	cout << "Enter reading status (0. Not Started; 1. Reading; 2. Finished): \t";
	cin >> rs;
	cout << "Enter reading status (0. Owned; 1. On wishlist): \t";
	cin >> ps;

	m_bookList[m_bookCount].SetBookInfo(title, author);
	m_bookList[m_bookCount].SetReadingStatus(ReadingStatus(rs));
	m_bookList[m_bookCount].SetPurchaseStatus(PurchaseStatus(ps));

	m_bookCount++;
}

void Library::UpdateBook() {
	cout << "------------------------- \n" << "| UPDATE BOOKS | \n" << "------------------------- \n";
	DisplayBooksWithIndex();

	int index, choice;
	cout << "Which index to update? \t";
	cin >> index;
	cout << "What do you want to update? \n1. Title \n2. Author \n3. Reading Status \n4. Purchase status" << endl;
	cin >> choice;
	while (choice < 1 || choice > 4) {
		cout << "What do you want to update? \n1. Title \n2. Author \n3. Reading Status \n4. Purchase status" << endl;
		cin >> choice;
	}

	string currentTitle = m_bookList[index].GetTitle();
	string currentAuthor = m_bookList[index].GetAuthor();
	string title, author;
	int rs, ps;

	cin.ignore();
	if (choice == 1) {
		cout << "Enter book title: \t";
		getline(cin, title);
		m_bookList[index].SetBookInfo(title, currentAuthor);
	}
	else if (choice == 2) {
		cout << "Enter book author: \t";
		getline(cin, author);
		m_bookList[index].SetBookInfo(currentTitle, author);
	}
	else if (choice == 3) {
		cout << "Enter reading status (0. Not Started; 1. Reading; 2. Finished): \t";
		cin >> rs;
		m_bookList[index].SetReadingStatus(ReadingStatus(rs));
	}
	else if (choice == 4) {
		cout << "Enter reading status (0. Owned; 1. On wishlist): \t";
		cin >> ps;
		m_bookList[index].SetPurchaseStatus(PurchaseStatus(ps));
	}
}

void Library::ViewAllBooks() {
	cout << "------------------------- \n" << "| VIEW ALL BOOKS | \n" << "------------------------- \n";

	for (int i = 0; i < m_bookCount; i++) {
		m_bookList[i].DisplayBook();
	}
}

void Library::ViewStats() {
	int totalOwned = 0, totalWishlist = 0, totalFinished = 0, totalReading = 0, totalNotStarted = 0;

	for (int i = 0; i < m_bookCount; i++) {
		if (m_bookList[i].GetPurchaseStatus() == OWNED) {
			totalOwned++;
		}
		else if (m_bookList[i].GetPurchaseStatus() == WISHLIST) {
			totalWishlist++;
		}

		if (m_bookList[i].GetReadingStatus() == READING) {
			totalReading++;
		}
		else if (m_bookList[i].GetReadingStatus() == NOT_STARTED) {
			totalNotStarted++;
		}
		else if (m_bookList[i].GetReadingStatus() == FINISHED) {
			totalFinished++;
		}
	}

	cout << "------------------------- \n" << "| BOOK STATS | \n" << "------------------------- \n";
	cout << "Total books: \t" << m_bookCount << endl;
	cout << "Books owned: \t" << totalOwned << endl;
	cout << "Books on wishlist: \t" << totalWishlist << endl;
	cout << "Books finished: \t" << totalFinished << endl;
	cout << "Currently reading: \t" << totalReading << endl;
	cout << "Books not started: \t" << totalNotStarted << endl;
}

void Library::SaveData() {
	ofstream output;
	output.open("books.txt");

	for (int i = 0; i < m_bookCount; i++) {
		output << "BOOK" << i << "\t " << m_bookList[i].GetTitle() << endl;
		output << "\t " << m_bookList[i].GetAuthor() << endl;
		output << "\t " << m_bookList[i].GetPurchaseStatusString() << endl;
		output << "\t " << m_bookList[i].GetReadingStatusString() << endl << endl;
	}

	output.close();
}

void Library::LoadData() {
	string header, title, author;
	int rs, ps;

	ifstream input;
	input.open("books.txt");

	while (input >> header) {
		input.ignore();
		getline(input, title);
		getline(input, author);
		input >> rs;
		input >> ps;

		if (isArrayFull() == true) {
			ResizeArray();
		}

		m_bookList[m_bookCount].SetBookInfo(title, author);
		m_bookList[m_bookCount].SetPurchaseStatus(PurchaseStatus(ps));
		m_bookList[m_bookCount].SetReadingStatus(ReadingStatus(rs));

		m_bookCount++;
	}

	input.close();
}
