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
  cout << "I ran fully!";
}

User::User(const User &user)
{
  cout << "Copy constructor called!\n";
  cout << "A user created with the following attributes";
  cout << "Username: " << user.username << "\n";
  cout << "Password: " << user.password << "\n";
  cout << "City: " << user.city << "\n";

  this->username = user.username;
  this->password = user.password;
  this->city = user.city;


  for(int i = 0; i < user.posts.size(); i++){
    this->posts.push(user.posts[i]);
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

User::~User(){
  cout << "Destructor called!\n";
  delete[] friends;
}

int User::getFriendIndex(string friendUsername) const{
  for(int i = 0; i < numFriends; i++){
    if(friends[i].friendUsername == friendUsername){
      return i;
    }
  }

  return -1;
}


int User::getNumPosts() const {return this->posts.size();}

  Post User::getPost(int index) const {
    return posts[index];
  }
  void User::addPost(Post post) {
    this->posts.push(post);
  }


void User::displayPublicData() const{
  cout << "Username: " << this->username << "\n";
  cout << "City: " << this->city << "\n";
  cout << "Number of friends: " << this->numFriends << "\n";
  cout << "Number of posts: " << this->posts.size() << "\n";
}