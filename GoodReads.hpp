#ifndef GOODREADS_H
#define GOODREADS_H "GOODREADS_H"

#include "Users.hpp"
#include "Books.hpp"
#include "Reviews.hpp"
#include "Books.hpp"
#include "FollowEdges.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class GoodReads{
public:
    GoodReads(std::vector<Users> u, std::vector<Authors> a, std::vector<Books> b, std::vector<Reviews> r, std::vector<FollowEdges> f);
    // std::string to_string();
    Authors gen_author_info(int author_id);
    void gen_book_id_and_title(int author_id);
    std::vector<std::string> gen_shelf_books(int user_id, std::string shelf_type);
    std::vector<std::string> gen_same_genre_books(int user_id, std::string shelf_type, std::string genre);
    std::vector<std::string> gen_diff_genre_books(int user_id, std::string shelf_type, std::string genre);
    void print_all_shelf_books(int user_id, std::string shelf_type, std::string genre);
    float compute_user_credit(int user_id);
    float compute_book_score(int book_id);
    void print_best_book_info();
    int compute_reviwer_likes(int user_id);
    void print_best_reviewer_info();
    int number_of_reviews_of_book(int book_id);
    float compute_rating(int book_id);
    int compute_favorite_genres_score(int user_id, int book_id);
    void print_best_book_for_user_info(int user_id);
    std::vector<int> find_close_followings_by_id(int user_id);
    std::vector<int> find_all_followings(int user_id);
    std::vector<int> find_three_best_books_of_user(int user_id);
    int find_most_repeated_element(std::vector<int> Vect);
    int find_best_book_second_approach(int user_id);
    void print_best_book_info_second_approch(int book_id);
    bool check_if_in_list(std::vector<int> vec, int x);

private:
    Authors* find_author_by_id(int author_id);
    std::vector<Users> users;
    std::vector<Authors> authors;
    std::vector<Books> books;
    std::vector<Reviews> reviews;
    std::vector<FollowEdges> follow_edges;
};


#endif