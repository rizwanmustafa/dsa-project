#include "user.hpp"
#include "LinkedList.hpp"
#include <iostream>

using namespace std;


bool isUsernameUnique(const LinkedList<User>& users, string newUsername){
  for(int i = 0; i < users.size(); i++){
    if(users[i].getUsername() == newUsername){
      return false;
    }
  }

  return true;
}

User getUserFromInput()
{
  string username, password, city;

  cout << "Enter username: ";
  cin >> ws;
  getline(cin, username);

  cout << "Enter password: ";
  cin >> ws;
  getline(cin, username);

  cout << "Enter city: ";
  cin >> ws;
  getline(cin, username);


  return User(username, password, city);
}