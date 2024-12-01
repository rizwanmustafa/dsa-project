#include <iostream>
#include "user.hpp"
#include "post.hpp"

using namespace std;

User::User(string username, string password, string city)
{

  cout << "A user created with the following attributes - \n";
  cout << "Username: " << username << "\n";
  cout << "Password: " << password << "\n";
  cout << "City: " << city << "\n";
}

User::User(const User &user)
{
  cout << "A user created with the following attributes";
  cout << "Username: " << user.username << "\n";
  cout << "Password: " << user.password << "\n";
  cout << "City: " << user.city << "\n";

  this->username = user.username;
  this->password = user.password;
  this->city = user.city;

  this->numPosts = user.numPosts;
  this->posts = new Post[numPosts];
  for (int i = 0; i < numPosts; i++)
  {
    posts[i] = user.posts[i];
  }


  this->numFriends = user.numFriends;
  this->friends = new FriendRelationship[numFriends];
  for (int i = 0; i < numFriends; i++)
  {
    friends[i] = user.friends[i];
  }

  this->lastloginTime = user.lastloginTime;
  
}
