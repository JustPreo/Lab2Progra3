#include "bookstore.h"
#include <algorithm>
#include <ctime>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::sort;

BookStore::BookStore() {}

//-------------------------Funciones de agregar libros y buscar-------------------------
void BookStore::insertBook(Book b){
    catalogue.push_back(b);
    std::sort(catalogue.begin(),catalogue.end());//Hace sort
    audit.push_front("Book added:"+b.title);
}
int BookStore::searchBookByTitle(string title){
    int low = 0;
    int high = this->catalogue.size()- 1;

    while (high >= low){
        int mid = low + (high - low)/2;

        if (catalogue[mid].title == title){
            return mid;
        }
        else if (catalogue[mid].title<title){//Tiene que revisar si el mid es menor , actualiza low
            low = mid + 1;
        }
        else {
            high = mid -1;//Si es mayor , actualiza high
        }
    }
    return -1;
}

int BookStore::searchBookByISBN(string isbn){
    int low = 0;
    int high = this->catalogue.size()- 1;

    while (high >= low){
        int mid = low + (high - low)/2;

        if (catalogue[mid].isbn == stringToIsbnArray(isbn)){
            return mid;
        }
        else if (catalogue[mid].isbn<stringToIsbnArray(isbn)){//Tiene que revisar si el mid es menor , actualiza low
            low = mid + 1;
        }
        else {
            high = mid -1;//Si es mayor , actualiza high
        }
    }
    return -1;
}
//-------------------------Funciones auxiliares-------------------------

string BookStore::getCurrentTimestamp(){ //Este es el metodo para conseguir el time
    time_t timestamp;
    time(&timestamp);
    return ctime(&timestamp);

}

std::vector<int> BookStore::sortIndicesByIsbn(const std::vector<Book>&){

}

std::array<int,13> BookStore::stringToIsbnArray(const std::string& Input){

}
