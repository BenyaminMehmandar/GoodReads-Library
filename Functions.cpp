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

vector<string> command_splitter(string str) {
    vector<string> command_line;
    string word = "";
    for (auto x : str)
    {
        if (x == ' ' || x == '\t')
        {
            if (word != "")
            {
                command_line.push_back(word);
                word = "";
            }
        }
        else
            word = word + x;
    }
    if (word != "")
    {
        command_line.push_back(word);
    }
    return command_line;
}




vector<string> splitter(string str, char delimiter){
    stringstream line(str);
    string splitted;
    vector<string> splitted_list;
    while(getline(line, splitted, delimiter))
    {
        splitted_list.push_back(splitted);
    }

    return splitted_list;

}


vector<Users> read_users(string path){
    vector<Users> users;
    fstream file;
    file.open(path);
    string line;
    string word;
    getline(file, line, '\n');
    while(getline(file, line, '\n'))
    {
        istringstream new_line(line);
        getline(new_line, word, ',');
        int id = stoi(word);
        getline(new_line, word, ',');
        string name = word;
        getline(new_line, word, ',');
        string place_of_birth = word;
        getline(new_line, word, ',');
        string member_since = word;
        getline(new_line, word, ',');
        vector<string> FavoriteAuthors = splitter(word, '$');
        getline(new_line, word, ',');
        vector<string> FavoriteGenres = splitter(word, '$');
        getline(new_line, word, ',');
        vector<string> Want_to_Read = splitter(word, '$');
        getline(new_line, word, ',');
        vector<string> Current_Reading = splitter(word, '$');
        getline(new_line, word, ',');
        vector<string> Read = splitter(word, '$');
        users.push_back(Users(id, name, place_of_birth, member_since, FavoriteAuthors, FavoriteGenres, Want_to_Read, Current_Reading, Read));

    }
    file.close();
    return users;

}

vector<Authors> read_authors(string path){
    vector<Authors> authors;
    fstream file;
    file.open(path);
    string line;
    string word;
    getline(file, line, '\n');
    while(getline(file, line, '\n'))
    {
        istringstream new_line(line);
        getline(new_line, word, ',');
        int id = stoi(word);
        getline(new_line, word, ',');
        string name = word;
        getline(new_line, word, ',');
        string gender = word;
        getline(new_line, word, ',');
        string member_since = word;
        getline(new_line, word, ',');
        int year_of_birth = stoi(word);
        getline(new_line, word, ',');
        string place_of_birth = word;
        getline(new_line, word, ',');
        vector<string> genres = splitter(word, '$');
        authors.push_back(Authors(id, name, gender, member_since, year_of_birth, place_of_birth, genres));
    }
    file.close();
    return authors;
}


vector<Books> read_books(string path){
    vector<Books> books;
    fstream file;
    file.open(path);
    string line;
    string word;
    getline(file, line, '\n');
    int i = 0;
    while(getline(file, line, '\n'))
    {
        istringstream new_line(line);
        getline(new_line, word, ',');
        int id = stoi(word);
        getline(new_line, word, ',');
        string title = word;
        getline(new_line, word, ',');
        int author_id = stoi(word);
        getline(new_line, word, ',');
        string genre = word;
        books.push_back(Books(id, title, author_id, genre));

    }
    file.close();
    return books;
}

vector<Reviews> read_reviews(string path){
    vector<Reviews> reviews;
    fstream file;
    file.open(path);
    string line;
    string word;
    getline(file, line, '\n');
    while(getline(file, line, '\n'))
    {
        istringstream new_line(line);
        getline(new_line, word, ',');
        int id = stoi(word);
        getline(new_line, word, ',');
        int book_id = stoi(word);
        getline(new_line, word, ',');
        int user_id = stoi(word);
        getline(new_line, word, ',');
        int rating = stoi(word);
        getline(new_line, word, ',');
        string date = word;
        getline(new_line, word, ',');
        int number_of_likes = stoi(word);
        reviews.push_back(Reviews(id, book_id, user_id, rating, date, number_of_likes));
    }
    file.close();
    return reviews;
}

vector<FollowEdges> read_follow_edges(string path){
    vector<FollowEdges> follow_edges;
    fstream file;
    file.open(path);
    string line;
    string word;
    getline(file, line, '\n');
    while(getline(file, line, '\n'))
    {
        istringstream new_line(line);
        getline(new_line, word, ',');
        int id = stoi(word);
        getline(new_line, word, ',');
        vector<string> followings = splitter(word, '$');
        getline(new_line, word, ',');
        vector<string> followers = splitter(word, '$');

        follow_edges.push_back(FollowEdges(id, followings, followers));
    }
    file.close();
    return follow_edges;
}
