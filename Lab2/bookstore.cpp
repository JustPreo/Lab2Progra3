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
            audit.push_front("Search by title: " + title + " FOUND. " + getCurrentTimestamp());
            return mid;
        }
        else if (catalogue[mid].title<title){//Tiene que revisar si el mid es menor , actualiza low
            low = mid + 1;
        }
        else {
            high = mid -1;//Si es mayor , actualiza high
        }
    }
    audit.push_front("Search by title: " + title + " NOT FOUND. " + getCurrentTimestamp());
    return -1;
}

int BookStore::searchBookByISBN(string isbn){
    std::array<int,13> key = stringToIsbnArray(isbn);
    std::vector<int> sortedIndices = sortIndicesByIsbn(catalogue);//Convierte array a como deberia de verse

    int low = 0, high = sortedIndices.size() - 1;
    while (high >= low) {
        int mid = low + (high - low)/2;
        const auto& midIsbn = catalogue[sortedIndices[mid]].isbn;

        if (midIsbn == key) {
            audit.push_front("Search by ISBN: " + isbn + " FOUND. " + getCurrentTimestamp());
            return sortedIndices[mid];
        } else if (midIsbn < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    audit.push_front("Search by ISBN: " + isbn + " NOT FOUND. " + getCurrentTimestamp());
    return -1;
}
//-------------------------Funciones auxiliares-------------------------

string BookStore::getCurrentTimestamp(){ //Este es el metodo para conseguir el time
    time_t timestamp;
    time(&timestamp);
    return ctime(&timestamp);

}

std::vector<int> BookStore::sortIndicesByIsbn(const std::vector<Book>& books) {
    std::vector<int> indices(books.size());//Crea un vector con el tamano de books (que realmente es catalogue)
    for (int i = 0; i < (int)books.size(); ++i) {
        indices[i] = i;
    }

    std::sort(indices.begin(), indices.end(),
              [&books](int a, int b) {
                  return books[a].isbn < books[b].isbn;
              });

    return indices;
}


std::array<int,13> BookStore::stringToIsbnArray(const std::string& Input) {
    if (Input.size() != 13) //Revisa si el input no tiene el min
        throw std::invalid_argument("ISBN must have size of 13 ");
    //Los throws funcionan igualitos a Java , talvez solo cambia eso de std::

    std::array<int,13> arr;
    for (int i = 0; i < 13; ++i) {
        if (!isdigit(Input[i]))
            throw std::invalid_argument("ISBN must contain only numbers");
        arr[i] = Input[i] - '0'; // convertir char a num
    }
    return arr;
}
