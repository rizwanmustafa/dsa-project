#pragma once
#include <string>
#include "user.hpp"
#include <fstream>
#include "LinkedList.hpp"


class Manager{
  LinkedList<User*> users;

  User* currentUser;

  public:
  Manager(){
    this->currentUser = nullptr;

  }

  void logout(){
    currentUser = nullptr;
  }

  User* getCurrentUser(){
    return currentUser;
  }

  bool login(string username, string password){
    for(int i = 0; i < users.size(); i++){
      if(users[i]->getUsername() == username && users[i]->getPassword() == password){
        currentUser = users[i];
        return true;
      }
    }
    return false;
  }

  User* findUser(string username){
    for(int i = 0; i < users.size(); i++){
      if(users[i]->getUsername() == username){
        return users[i];
      }
    }
    return nullptr;
  }

  LinkedList<User*>& getUsers(){
    return users;
  }

  void addNewUser(User* user){
    users.insertLast(user);
  }

  void printAllUsers(){
    for(int i = 0; i < users.size(); i++){
      cout << users[i]->getUsername() << endl;
    }
  }


  void loadUsersFromFile(string filename = "users.txt"){
    ifstream file(filename);

    if(!file.is_open()){
      cout << "User File not found! Creating empty file!\n";

      ofstream newFile(filename);
      newFile.close();

      return;
    }

    string username, password, city;
    while(file){
      getline(file, username);
      if(!file) break;
      getline(file, password);
      getline(file, city);
      User* newUser = new User(username, password, city);
      addNewUser(newUser);
    }

    file.close();

  }

  void saveUsersToFile(string filename = "users.txt"){
    ofstream file(filename);

    for(int i = 0; i < users.size(); i++){
      file << users[i]->getUsername() << "\n" << users[i]->getPassword() << "\n" << users[i]->getCity();

      if(i != users.size() - 1){
        file << "\n";
      }
    }

    file.close();
  }

  void saveFriendsToFile(string filename = "friends.txt"){
    ofstream file(filename);

    for(int i = 0; i < users.size(); i++){
      for(int j = 0; j < users[i]->getNumFriends(); j++){
        file << users[i]->getUsername() << "\n" << users[i]->getFriend(j).friendUsername << "\n" << users[i]->getFriend(j).status;

        if(i != users.size() - 1 || j != users[i]->getNumFriends() - 1){
          file << "\n";
        }
      }
    }

    file.close();
  }

  void loadFriendsFromFile(string filename = "friends.txt"){
    ifstream file(filename);

    if(!file.is_open()){
      cout << "Friends File not found! Creating empty file!\n";

      ofstream newFile(filename);
      newFile.close();

      return;
    }

    string username, friendUsername, status;
    while(file){
      getline(file, username);
      if(!file) break;
      getline(file, friendUsername);
      getline(file, status);

      User* user = findUser(username);
      if(user != nullptr){
        user->addFriend(friendUsername, (RelationshipStatus)stoi(status));
      }

      User* friendUser = findUser(friendUsername);
      if(friendUser != nullptr){
        friendUser->addFriend(username, (RelationshipStatus)stoi(status));
      }
    }

    file.close();

  }

};

