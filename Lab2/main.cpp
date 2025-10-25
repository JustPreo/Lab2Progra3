#include "bookstore.h"
#include <QCoreApplication>
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    BookStore store;
    string opcion;

    while (true) {
        cout << "1. Insert Book\n";
        cout << "2. Search by title\n";
        cout << "3. Search by ISBN\n";
        cout << "4. Auditlog\n";
        cout << "5. Exit\n";
        cout << "Select an option: ";
        getline(cin, opcion); //El getline que mencionaba el inge

        if (opcion == "1") {
            string titulo, autor, isbn;
            cout << "Title: ";
            getline(cin, titulo);
            cout << "Author: ";
            getline(cin, autor);
            cout << "ISBN(13 digits): ";
            getline(cin, isbn);

            try {
                std::array<int,13> arr = store.stringToIsbnArray(isbn);//Uso la funcion que puso el inge para ocnvertirlo a array
                Book BOOK(titulo, autor, arr);
                store.insertBook(BOOK);
                cout << "Book Added\n";
            } catch (const std::invalid_argument& e) {
                cout << e.what() << endl;
            }

        } else if (opcion == "2") {
            string titulo;
            cout << "Name of book to search: ";
            getline(cin, titulo);

            int pos = store.searchBookByTitle(titulo);
            if (pos != -1)
                cout << "Book Found:" << store.catalogue[pos].title << endl;
            else
                cout << "Book not found :(";

        } else if (opcion == "3") {
            string isbn;
            cout << "ISBN(13 digits): ";
            getline(cin, isbn);

            try {
                int pos = store.searchBookByISBN(isbn);
                if (pos != -1)
                    cout << "Book Found: " << store.catalogue[pos].title << endl;
                else
                    cout << "Book not found\n";
            } catch (const std::invalid_argument& e) {
                cout << e.what() << endl;
            }

        } else if (opcion == "4") {
            cout << "\n======= AUDIT LOG =======\n";
            if (store.audit.empty()) {
                cout << "No logs available\n";
            } else {
                for (const string& log : store.audit)//Entendi que el & usa el original y no crea otro en espacio de memoria
                    cout << log << endl;
            }
            cout << "=========================\n";

        } else if (opcion == "5") {
            cout << "Exiting...\n";
            break;

        } else {
            cout << "Invalid Option\n";
        }
    }
    store.catalogue.clear();//Me imagino que esto libera de memoria porque no me deja hacerle delete


    return a.exec();
}
