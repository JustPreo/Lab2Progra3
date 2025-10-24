#ifndef BOOKSTORE_H
#define BOOKSTORE_H
#include "book.h"
#include <list>
#include <string>
#include <vector>

class BookStore
{
public:
    std::vector<Book> catalogue;
    std::list<string> audit;

    BookStore();
    void insertBook(Book b);
    int searchBookByTitle(string title);
    int searchBookByISBN(string isbn);
    std::vector<int> sortIndicesByIsbn(const std::vector<Book>&);
    std::array<int,13> stringToIsbnArray(const std::string& Input);
    string getCurrentTimestamp();
};

#endif // BOOKSTORE_H
