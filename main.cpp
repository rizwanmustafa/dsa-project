#include <iostream>
#include "user.hpp"
#include "LinkedList.hpp"
#include "misc.hpp"
#include <fstream>
#include "manager.hpp"

// TODO: Add password resets through security questions
// TODO: Add notification for friend requests when they are accepted or rejected
// TODO: Allow searching of users using BST

using namespace std;

void manageFollowRequests(Manager &m)
{
  if (m.getCurrentUser() == nullptr)
  {
    cout << "No user is logged in!\n";
    return;
  }

  // Write code to display all friend requests and allow user to accept or reject them and allow user to do bulk action

  // Ask user if they want to perform a bulk action at all
  cout << "Do you want to perform a bulk action? (y/n): ";
  char bulkActionChoice;
  cin >> bulkActionChoice;

  char choice;

  if (tolower(bulkActionChoice) == 'y')
  {
    cout << "Do you want to accept or reject all friend requests? (a/r): ";
    cin >> choice;
  }

  for (int i = 0; i < m.getCurrentUser()->getNumFriends(); i++)
  {
    if (m.getCurrentUser()->getFriend(i).status == PENDING)
    {

      if (tolower(bulkActionChoice) == 'y')
      {
        if (tolower(choice) == 'a')
        {
          m.getCurrentUser()->getFriend(i).status = ACCEPTED;
          cout << "Friend request accepted!\n";
        }
        else if (tolower(choice) == 'r')
        {
          m.getCurrentUser()->getFriend(i).status = BLOCKED;
          cout << "Friend request rejected!\n";
        }
      }
      else
      {
        cout << m.getCurrentUser()->getFriend(i).friendUsername << " has sent you a friend request!\n";
        User* friendUser = m.findUser(m.getCurrentUser()->getFriend(i).friendUsername);
        // TODO: Write code accept/reject the friends request as well
        cout << "Do you want to accept or reject this request? (a/r): ";
        char choice;
        cin >> choice;
        if (choice == 'a')
        {
          m.getCurrentUser()->getFriend(i).status = ACCEPTED;
          cout << "Friend request accepted!\n";
        }
        else if (choice == 'r')
        {
          m.getCurrentUser()->getFriend(i).status = BLOCKED;
          cout << "Friend request rejected!\n";
        }
      }
    }
  }
}


void sendFriendRequest(Manager &m)
{
  if (m.getCurrentUser() == nullptr)
  {
    cout << "No user is logged in!\n";
    return;
  }

  string friendUsername;
  cout << "Enter the username of the friend you want to send a request to: ";
  cin >> ws;
  getline(cin, friendUsername);

  User *friendUser = m.findUser(friendUsername);
  if (friendUser == nullptr)
  {
    cout << "User not found!\n";
    return;
  }

  m.getCurrentUser()->addFriend(friendUsername, PENDING);
  cout << "Friend request sent!\n";
}


void printCurrentUser(Manager &m)
{
  User *currentUser = m.getCurrentUser();
  if (currentUser != nullptr)
  {
    cout << "Current User: " << currentUser->getUsername() << endl;
  }
  else
  {
    cout << "No user is logged in!\n";
  }
}

void signup(Manager &m)
{

  User *newUser = getUserFromInput(m.getUsers());
  m.addNewUser(newUser);
}

void login(Manager &m)
{
  string username, password;
  cout << "Enter username: ";
  cin >> ws;
  getline(cin, username);
  cout << "Enter password: ";
  cin >> ws;
  getline(cin, password);

  if (m.login(username, password))
  {
    cout << "Login successful!\n";
  }
  else
  {
    cout << "Login failed!\n";
  }
}

void printMenu()
{
  int userChoice;
  Manager m;

  m.loadUsersFromFile();
  m.loadFriendsFromFile();

  while (true)
  {
    // TODO: Remove these debug lines
    cout << "Printing all users:\n";
    m.printAllUsers();

    printCurrentUser(m);
    cout << "0. Exit\n";
    cout << "1. Signup\n";
    cout << "2. Login\n";
    cout << "3. Logout\n";
    cout << "4. Manage Friend Requests\n";
    cout << "5. Send Friend Requests\n";
    cout << "6. Create a Post\n";
    cout << "7. View your Notifications\n";
    cout << "8. Message a friend\n";
    cout << "9. Search Users\n";
    cout << "10. Followers List\n";
    cout << "11. Newsfeed\n";
    cout << "Enter choice: ";

    while (!(cin >> userChoice) || userChoice < 0 || userChoice > 11)
    {
      cin.clear();
      cin.ignore(100000, '\n');
      cout << "Invalid value!\n";
      cout << "Enter choice: ";
    }

    if (userChoice == 0)
    {
      cout << "Allah Hafiz!\n";
      break;
    }
    else if (userChoice == 1)
    {
      signup(m);
    }
    else if (userChoice == 2)
    {
      login(m);
    }
    else if (userChoice == 3)
    {
      m.logout();
    }
    else if (userChoice == 4)
    {
      manageFollowRequests(m);
    }
    else if (userChoice == 5)
    {
      sendFriendRequest(m);
    }
    else if (userChoice == 6)
    {
      cout << "Posts functionality!\n";
    }
    else if (userChoice == 7)
    {
      cout << "Notifications functionality!\n";
    }
    else if (userChoice == 8)
    {
      cout << "Messaging functionality!\n";
    }
    else if (userChoice == 9)
    {
      cout << "Search Users functionality!\n";
    }
    else if (userChoice == 10)
    {
      cout << "Followers List functionality!\n";
    }
    else if (userChoice == 11)
    {
      cout << "Newsfeed functionality!\n";
    }
  }

  m.saveUsersToFile();
  m.saveFriendsToFile();
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
