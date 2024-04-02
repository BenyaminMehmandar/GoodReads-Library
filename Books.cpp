#include "Books.hpp"


#include <sstream>
#include <vector>

using namespace std;


Books::Books(int Id, string Title, int a, string G){
    id = Id;
    title = Title;
    author_id = a;
    genre = G;
}

Authors* Books::find_author_by_id(int author_id){
    for (int i = 0; i < authors.size() ; ++i)
        if (authors[i].get_id() == author_id)
            return &authors[i];
}

int Books::get_id() { return id; }

int Books::get_author_id() { return author_id; }

string Books::get_genre() { return genre; }
string Books::get_title() { return title; }

void Books::to_string()
{
    ostringstream os;
    os << "id: " << id << " " << "Title: " << title << endl;
    cout << os.str();
}

void Books::print_book_info()
{
    ostringstream os;
    os << "id: " << id << endl;
    os << "Title: " << title  << endl;
    os << "Genre: "<< genre << endl;
    cout << os.str();
}