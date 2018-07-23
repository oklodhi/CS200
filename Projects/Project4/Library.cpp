#include "Library.hpp"

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
    m_bookList = new int[size];
    m_arraySize = size;
}

void Library::ResizeArray() {
    Book* biggerArray;
    biggerArray = new int[m_arraySize + 10];
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


