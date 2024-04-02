#include "Authors.hpp"
#include <sstream>
#include <vector>

using namespace std;

Authors::Authors(int Id, string Name, string Gender, string Member_since, int Year_of_birth, string Place_of_birth, vector<string> Genres){
    id = Id;
    name = Name;
    gender = Gender;
    member_since = Member_since;
    year_of_birth = Year_of_birth;
    place_of_birth = Place_of_birth;
    genres = Genres;
}

int Authors::get_id() { return id; }

string Authors::get_name() { return name; }

void Authors::to_string()
{
    ostringstream os;
    os << "id: " << id << endl;
    os << "Name: " << name << endl;
    os << "Year of Birth: " << year_of_birth << endl;
    os << "Place of Birth: " << place_of_birth << endl;
    os << "Member Since: " << member_since << endl;
    os << "Genres: " ;
    sort(genres.begin(), genres.end());
    for (int i = 0; i < genres.size(); ++i)
        os << genres[i] << " ";
    os << endl;
    os << "Books: " << endl;
    cout << os.str();
}



    
        
        