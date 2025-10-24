#include "book.h"
#include <string>
#include <array>

using std::string;

Book::Book(string title,string author,std::array<int,13> isbn) {
    this->author = author;
    this->title = title;
    this->isbn = isbn;
}
bool Book::operator<(const Book& other) const{
    //Revisar titulo primero
    if (title.compare(other.title)<0){
        return true;
    }
    //Revisar author si son titulos iguales
    else if (title.compare(other.title)==0){
        if (author.compare(other.author)<0){//Osea si author es primero
            return true;
        }
        else{
            if (isbn<other.isbn){
                return false;
            }
        }
        return true;
    }
    return false;//Si no se cumple alguna de estas

}
