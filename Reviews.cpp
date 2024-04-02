#include "Reviews.hpp"


#include <sstream>
#include <vector>

using namespace std;


Reviews::Reviews(int Id, int Book_id, int User_id, int Rating, string Date, int Number_of_likes){
    id = Id;
    book_id = Book_id;
    user_id = User_id;
    rating = Rating;
    date = Date;
    number_of_likes = Number_of_likes;
}
    
int Reviews::get_number_of_likes() { return number_of_likes; }
int Reviews::get_user_id() { return user_id; }
int Reviews::get_book_id() { return book_id; }
int Reviews::get_rating() { return rating; }
int Reviews::get_id() { return id; }
string Reviews::get_date() { return date; }

    
Books* Reviews::find_book_by_id(int book_id){
    for (int i = 0; i < books.size() ; ++i)
        if (books[i].get_id() == book_id)
            return &books[i];
}

Users* Reviews::find_user_by_id(int user_id){
    for (int i = 0; i < users.size() ; ++i)
        if (users[i].get_id() == user_id)
            return &users[i];
}