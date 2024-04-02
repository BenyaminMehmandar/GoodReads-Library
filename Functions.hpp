#ifndef FUNCTIONS_H
#define FUNCTIONS_H "FUNCTIONS_H"

#include "Users.hpp"
#include "Books.hpp"
#include "Reviews.hpp"
#include "Books.hpp"
#include "FollowEdges.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<std::string> command_splitter(std::string str); 
std::vector<std::string> splitter(std::string str, char delimiter);
std::vector<Users> read_users(std::string path);
std::vector<Authors> read_authors(std::string path);
std::vector<Books> read_books(std::string path);
std::vector<Reviews> read_reviews(std::string path);
std::vector<FollowEdges> read_follow_edges(std::string path);



#endif