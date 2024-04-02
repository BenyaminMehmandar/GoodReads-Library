#include "Users.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

Users::Users(int I, string N, string P, string M, vector<string> FA, vector<string> FG, vector<string> WR, vector<string> CR, vector<string> R){
    id = I;
    name = N;
    place_of_birth = P;
    member_since = M;
    favorite_authors = FA;
    favorite_genres = FG;
    want_to_read = WR;
    currently_reading = CR;
    read = R;
    
}

int Users::get_id() { return id; }
vector<string> Users::get_want_to_read(){ return want_to_read; }
vector<string> Users::get_currently_reading(){ return currently_reading; }
vector<string> Users::get_read(){ return read; }
vector<string> Users::get_favorite_authors() { return favorite_authors; }
vector<string> Users::get_favorite_genres() { return favorite_genres; }

void Users::print_user_info_one()
{
    ostringstream os;
    os << "id: " << id << endl;
    os << "Name: " << name << endl;
    os << "Place of Birth: " << place_of_birth << endl;
    os << "Member Since: " << member_since << endl;
    os << "Favorite Genres: ";
    sort(favorite_genres.begin(), favorite_genres.end());
    for (int i = 0; i < favorite_genres.size()-1; ++i)
            os << favorite_genres[i] << ", ";
    os << favorite_genres[favorite_genres.size()-1];

    os << endl;
    cout << os.str();
}

void Users::print_user_info_two()
{
    ostringstream os;
    os << "Number of Books in Read Shelf: " << read.size() << endl;
    os << "Number of Books Want to Read Shelf: " << want_to_read.size() << endl;
    os << "Number of Books in Currently Reading Shelf: " << currently_reading.size() << endl;
    cout << os.str();
}