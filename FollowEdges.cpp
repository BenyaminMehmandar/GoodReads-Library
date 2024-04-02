#include "FollowEdges.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

FollowEdges::FollowEdges(int Id, vector<string> Followings, vector<string> Followers){
    id = Id;
    followings = Followings;
    followers = Followers;  
}


int FollowEdges::get_id() { return id; }
vector<string> FollowEdges::get_followings(){ return followings; }
vector<string> FollowEdges::get_followers() {return followers; }