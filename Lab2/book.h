#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <array>


using std::string;
using std::array;


class Book
{
public:
    string title;
    string author;
    std::array<int,13> isbn {};

    Book();
    Book(string title,string author,std::array<int,13> isbn);

    bool operator<(const Book& other) const;
};

#endif // BOOK_H
