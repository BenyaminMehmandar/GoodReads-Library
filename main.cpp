#include "Users.hpp"
#include "Authors.hpp"
#include "Books.hpp"
#include "Reviews.hpp"
#include "GoodReads.hpp"
#include "FollowEdges.hpp"
#include "Functions.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;


int main(int argc, char *argv[])
{
    string path = argv[1];

    vector<Authors> authors;
    authors = read_authors(path + "/authors.csv");
    vector<Users> users;
    users = read_users(path + "/users.csv");
    vector<Books> books;
    books = read_books(path + "/books.csv");
    vector<Reviews> reviews;
    reviews = read_reviews(path + "/reviews.csv");
    vector<FollowEdges> follow_edges;
    follow_edges = read_follow_edges(path + "/follow_edges.csv");
    
    GoodReads GR(users, authors, books, reviews, follow_edges);

    string line ;
    getline(cin, line);
    vector<string> command = command_splitter(line);

    if (command[0] == "show_author_info")
    {
        Authors aut = GR.gen_author_info(stoi(command[1]));
        aut.to_string();
        GR.gen_book_id_and_title(stoi(command[1]));
    }

    else if (command[0] == "show_sorted_shelf")
        GR.print_all_shelf_books(stoi(command[1]), command[2], command[3]);

    else if (command[0] == "credit")
    {
        float credit = GR.compute_user_credit(stoi(command[1]));
        cout << fixed << setprecision(6) << credit << endl;
    }

    else if (command[0] == "best_book")
        GR.print_best_book_info();

    else if (command[0] == "best_reviewer")
        GR.print_best_reviewer_info();

    else if (command[0] == "recommand_first_approach")
        GR.print_best_book_for_user_info(stoi(command[1]));

    else if (command[0] == "recommand_second_approach")
    {
        int best_book_id = GR.find_best_book_second_approach(stoi(command[1]));
        GR.print_best_book_info_second_approch(best_book_id);
    }

}