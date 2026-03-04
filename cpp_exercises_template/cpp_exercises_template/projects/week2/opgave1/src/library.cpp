#include "library.h"
#include <iostream>

void Library::addBook(int ID_, int category_)
{
    Books.emplace_back(ID_, category_);
    if (booksInCategory(category_) * 2 > averageNumberPerCategory()) {
        std::cout << "WARNING: You are not balanced :)))" << std::endl;
    }
    validCategories.push_back(category_);
    availableBooks.emplace_back(ID_, category_);
}

bool Library::borrow(int ID_, int category_)
{
    for (auto itr = availableBooks.begin(); itr != availableBooks.end(); ++itr) {
        if (ID_ == itr->ID && category_ == itr->category) {
            borrowedBooks.push_back(*itr);
            availableBooks.erase(itr);
            return true;
        }
    }
    return false;
}

bool Library::returnborrowed(int ID, int category)
{
    for (auto itr = borrowedBooks.begin(); itr != borrowedBooks.end(); ++itr) {
        if (ID == itr->ID && category == itr->category) {
            availableBooks.push_back(*itr);
            borrowedBooks.erase(itr);
            return true;
        }
    }
    return false;
}

void Library::displayBorrowedBooks()
{
    std::cout << "Borrowed books: \n";
    for (auto &boeger : borrowedBooks) {
        std::cout << "ID: " << boeger.ID << ". Category: " << boeger.category << ".\n";
    }
}

void Library::displayAvailableBooks()
{
    std::cout << "Available books:";
    for (auto &boeger : availableBooks) {
        std::cout <<  "ID: " << boeger.ID << ". Category: " << boeger.category << ".\n";
    }
}

int Library::booksInCategory(int category)
{
    int boegerIKategori = 0;
    for (size_t i = 0; i < Books.size(); ++i) {
        if (Books[i].category == category) {
            boegerIKategori++;
        }
    }
    return boegerIKategori;
}

void Library::displayAllBooks()
{
    std::cout << "All books are: \n";
    for (auto &boeger : Books) {
        std::cout << "ID: " << boeger.ID << ". Category: " << boeger.category << "\n";
    }
}

int Library::averageNumberPerCategory()
{
    if (validCategories.empty()) {
        return 0;
    }
    return Books.size() / validCategories.size();
}