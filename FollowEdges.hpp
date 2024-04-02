#ifndef FOLLOWEDGES_H
#define FOLLOWEDGES_H "FOLLOWEDGES_H"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class FollowEdges{
public:
    FollowEdges(int Id, std::vector<std::string> Followings, std::vector<std::string> Followers);
    int get_id();
    std::vector<std::string> get_followings();
    std::vector<std::string> get_followers();

private:

    int id;
    std::vector<std::string> followings;
    std::vector<std::string> followers;

};

#endif
