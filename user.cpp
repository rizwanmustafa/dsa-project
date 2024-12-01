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

  this->username = username;
  this->password = password;
  this->city = city;
  this->numFriends = 0;
  this->numPosts = 0;
  cout << "I ran fully!";
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

string User::getUsername() const
{
  return this->username;
}

string User::getPassword() const
{
  return this->password;
}

string User::getCity() const
{
  return this->city;
}

void User::addFriend(string friendUsername, RelationshipStatus status)
{
  FriendRelationship *newFriends = new FriendRelationship[numFriends + 1];
  for (int i = 0; i < numFriends; i++)
  {
    newFriends[i] = friends[i];
  }

  newFriends[numFriends].friendUsername = friendUsername;
  newFriends[numFriends].status = status;

  delete this->friends;

  this->friends = newFriends;
  this->numFriends++;

}

int User::getNumFriends() const { return this->numFriends;}


  FriendRelationship& User::getFriend(int index) const{
    return friends[index];
  }
