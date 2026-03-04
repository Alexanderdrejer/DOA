#include <vector>
#include "book.h"

class Library {
public:
    std::vector<Book> Books;
    std::vector<int> validCategories;
    std::vector<Book> borrowedBooks;
    std::vector<Book> availableBooks;

    void addBook(int ID_, int category_);
    bool borrow(int ID_, int category_);
    bool returnborrowed(int ID, int category);
    void displayBorrowedBooks();
    void displayAvailableBooks();
    int booksInCategory(int category);
    void displayAllBooks();

    int averageNumberPerCategory();

};