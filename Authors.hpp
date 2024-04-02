#ifndef AUTHORS_H
#define AUTHORS_H "AUTHORS_H"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Authors{
public:
    Authors(int id, std::string name, std::string gender, std::string member_since, int year_of_birth, std::string place_of_birth, std::vector<std::string> genres);
    int get_id();
    std::string get_name();
    void to_string();

    
private:
    int id;
    std::string name;
    std::string gender;
    std::string member_since;
    int year_of_birth;
    std::string place_of_birth;
    std::vector<std::string> genres;

};

#endif
