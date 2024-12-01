#include <iostream>
#include "user.hpp"
#include "LinkedList.hpp"
#include "misc.hpp"

using namespace std;

class Manager{
  LinkedList<User> users;


  public:

  void addNewUser(User& user){
    users.insertLast(user);
  }

  void printAllUsers(){
    for(int i = 0; i < users.size(); i++){
      cout << users[i].getUsername() << endl;
    }
  }

};


void signup(Manager& m){

  User newUser = getUserFromInput();
  m.addNewUser(newUser);

}



void printMenu()
{
  int userChoice;
  Manager m;

  while (true)
  {
    m.printAllUsers();
    cout << "0. Exit\n";
    cout << "1. Signup\n";
    cout << "2. Login\n";
    cout << "3. Logout\n";
    cout << "4. Follow Request\n";
    cout << "5. Cancel and Accept Requests\n";
    cout << "6. Posts\n";
    cout << "7. Notifications\n";
    cout << "8. Messaging\n";
    cout << "9. Search Users\n";
    cout << "10. Followers List\n";
    cout << "11. Newsfeed\n";
    cout << "Enter choice: ";

    while(!(cin >> userChoice) || userChoice < 0 || userChoice > 11){
      cin.clear();
      cin.ignore(100000, '\n');
      cout << "Invalid value!\n";
      cout << "Enter choice: ";
    }

    if (userChoice == 0){
      cout << "Allah Hafiz!\n";
      return;
    }
    else if (userChoice == 1){
      cout << "Signup functionality!\n";
    }
    else if (userChoice == 2){
      cout << "Login functionality!\n";
    }
    else if (userChoice == 3){
      cout << "Logout functionality!\n";
    }
    else if (userChoice == 4){
      cout << "Follow Request functionality!\n";
    }
    else if (userChoice == 5){
      cout << "Cancel and Accept Requests functionality!\n";
    }
    else if (userChoice == 6){
      cout << "Posts functionality!\n";
    }
    else if (userChoice == 7){
      cout << "Notifications functionality!\n";
    }
    else if (userChoice == 8){
      cout << "Messaging functionality!\n";
    }
    else if (userChoice == 9){
      cout << "Search Users functionality!\n";
    }
    else if (userChoice == 10){
      cout << "Followers List functionality!\n";
    }
    else if (userChoice == 11){
      cout << "Newsfeed functionality!\n";
    }


  }
}

void printIntro()
{
  cout << "This is some dope introduction!\n";
  cout << "Press enter to continue!\n";
  system("pause");
  system("cls");
}

int main()
{
  printIntro();

  printMenu();

  return 0;
}
