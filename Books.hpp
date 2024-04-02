
#ifndef BOOKS_H
#define BOOKS_H "BOOKS_H"

#include "Authors.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


class Books{
public:
    Books(int Id, std::string Title, int a, std::string G);
    int get_id();
    int get_author_id();
    std::string get_title();
    std::string get_genre();
    void to_string();
    void print_book_info();
    
private:
    Authors* find_author_by_id(int author_id);
    int id;
    std::string title;
    Authors* author;
    int author_id;
    std::string genre;
    std::vector<Authors> authors;

};



#endif