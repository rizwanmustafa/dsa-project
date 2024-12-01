#pragma once
#include <string>
#include "post.hpp"
using namespace std;

enum RelationshipStatus{
  PENDING,
  ACCEPTED,
  BLOCKED 
};

struct FriendRelationship{
  string friendUsername;
  RelationshipStatus status;
};

class User{
  string username;
  string password;
  string city;
  Post* posts;
  int numPosts;
  time_t lastloginTime;

FriendRelationship* friends;
int numFriends;

public:
  User(string username, string password, string city);
  User(const User& user);

  string getUsername() const;
  

};