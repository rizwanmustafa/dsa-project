#include "user.hpp"
#include <iostream>

using namespace std;

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