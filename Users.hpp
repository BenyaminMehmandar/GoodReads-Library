#ifndef USERS_H
#define USERS_H "USERS_H"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Users{
public:
    Users(int I, std::string N, std::string P, std::string M, std::vector<std::string> FA, std::vector<std::string> FG, std::vector<std::string> WR, 
    std::vector<std::string> CR, std::vector<std::string> R);
    int get_id();
    std::vector<std::string> get_favorite_genres();
    std::vector<std::string> get_favorite_authors();
    std::vector<std::string> get_want_to_read();
    std::vector<std::string> get_currently_reading();
    std::vector<std::string> get_read();

    void print_user_info_one();
    void print_user_info_two();
    
private:

    int id;
    std::string name;
    std::string place_of_birth;
    std::string member_since;
    std::vector<std::string> favorite_authors;
    std::vector<std::string> favorite_genres;
    std::vector<std::string> want_to_read;
    std::vector<std::string> currently_reading;
    std::vector<std::string> read;
};

#endif

