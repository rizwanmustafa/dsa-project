#pragma once
#include <string>
#include "post.hpp"
#include "stack.hpp"
using namespace std;

enum RelationshipStatus
{
  PENDING,
  ACCEPTED,
  BLOCKED
};

struct FriendRelationship
{
  string friendUsername;
  RelationshipStatus status;
};

class User
{
  string username;
  string password;
  string city;
  Stack<Post> posts;
  time_t lastloginTime;

  FriendRelationship *friends;
  int numFriends;

public:
  User(string username, string password, string city);
  User(const User &user);

  string getUsername() const;
  string getPassword() const;
  string getCity() const;

  void addFriend(string friendUsername, RelationshipStatus status);
  int getNumFriends() const;
  FriendRelationship& getFriend(int index) const;
  int getFriendIndex(string friendUsername) const;
  
  int getNumPosts() const;
  Post getPost(int index) const;
  void addPost(Post post);

  ~User();
};