#ifndef REVIEWS_H
#define REVIEWS_H "REVIEWS_H"

#include "Users.hpp"
#include "Books.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Reviews{
public:
    Reviews(int id, int book_id, int user_id, int rating, std::string date, int number_of_likes);
    int get_number_of_likes();
    int get_user_id();
    int get_book_id();
    int get_rating();
    int get_id();
    std::string get_date();
    
private:
    Books* find_book_by_id(int book_id);
    Users* find_user_by_id(int user_id);
    int id;
    Books* book;
    Users* user;
    int book_id;
    int user_id;
    int rating;
    std::string date;
    int number_of_likes;
    std::vector<Books> books;
    std::vector<Users> users;
};


#endif