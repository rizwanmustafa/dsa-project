#include "user.hpp"
#include "LinkedList.hpp"
#include <iostream>

using namespace std;

bool isUsernameUnique(const LinkedList<User*> &users, string newUsername)
{
  for (int i = 0; i < users.size(); i++)
  {
    if (users[i]->getUsername() == newUsername)
    {
      return false;
    }
  }

  return true;
}

User *getUserFromInput(const LinkedList<User*>&existingUsers)
{
  string username = "", password = "", city = "";

  while (username == "" || isUsernameUnique(existingUsers, username) == false)
  {
    cout << "Enter username: ";
    cin >> ws;
    getline(cin, username);
  }

  while (password == "")
  {

    cout << "Enter password: ";
    cin >> ws;
    getline(cin, password);
  }

  while (city == "")
  {
    cout << "Enter city: ";
    cin >> ws;
    getline(cin, city);
  }

  return new User(username, password, city);
}