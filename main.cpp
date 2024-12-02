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

void displayFriends(Manager &m)
{
  if (m.getCurrentUser() == nullptr)
  {
    cout << "No user is logged in!\n";
    return;
  }

  for (int i = 0; i < m.getCurrentUser()->getNumFriends(); i++)
  {
    FriendRelationship userFriend = m.getCurrentUser()->getFriend(i);
    if (userFriend.status == ACCEPTED)
    {
      cout << i + 1 << ". " << userFriend.friendUsername << endl;
    }
  }
}

void manageFollowRequests(Manager &m)
{

  // TODO: Find a way around the fact that the user can accept their own friend requests

  if (m.getCurrentUser() == nullptr)
  {
    cout << "No user is logged in!\n";
    return;
  }

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
    User *friendUser = m.findUser(m.getCurrentUser()->getFriend(i).friendUsername);

    if (m.getCurrentUser()->getFriend(i).status == PENDING)
    {

      if (tolower(bulkActionChoice) == 'y')
      {
        if (tolower(choice) == 'a')
        {
          m.getCurrentUser()->getFriend(i).status = ACCEPTED;
          friendUser->getFriend(friendUser->getFriendIndex(m.getCurrentUser()->getUsername())).status = ACCEPTED;

          cout << "Friend request accepted!\n";
        }
        else if (tolower(choice) == 'r')
        {
          m.getCurrentUser()->getFriend(i).status = BLOCKED;
          friendUser->getFriend(friendUser->getFriendIndex(m.getCurrentUser()->getUsername())).status = BLOCKED;
          cout << "Friend request rejected!\n";
        }
      }
      else
      {
        cout << m.getCurrentUser()->getFriend(i).friendUsername << " has sent you a friend request!\n";
        // TODO: Write code accept/reject the friends request as well
        cout << "Do you want to accept or reject this request? (a/r): ";
        char choice;
        cin >> choice;
        if (choice == 'a')
        {
          m.getCurrentUser()->getFriend(i).status = ACCEPTED;
          friendUser->getFriend(friendUser->getFriendIndex(m.getCurrentUser()->getUsername())).status = ACCEPTED;
          cout << "Friend request accepted!\n";
        }
        else if (choice == 'r')
        {
          m.getCurrentUser()->getFriend(i).status = BLOCKED;
          friendUser->getFriend(friendUser->getFriendIndex(m.getCurrentUser()->getUsername())).status = BLOCKED;
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

  // Check if the user is trying a duplicate friend request
  for (int i = 0; i < m.getCurrentUser()->getNumFriends(); i++)
  {
    if (m.getCurrentUser()->getFriend(i).friendUsername == friendUsername)
    {
      cout << "You have already sent a friend request to this user!\n";
      return;
    }
  }

  if (friendUsername == m.getCurrentUser()->getUsername())
  {
    cout << "You cannot send a friend request to yourself!\n";
    return;
  }

  User *friendUser = m.findUser(friendUsername);
  if (friendUser == nullptr)
  {
    cout << "User not found!\n";
    return;
  }

  m.getCurrentUser()->addFriend(friendUsername, PENDING);
  friendUser->addFriend(m.getCurrentUser()->getUsername(), PENDING);
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

void searchUser(Manager &m)
{
  if (m.getCurrentUser() == nullptr)
  {
    cout << "No user is logged in!\n";
    return;
  }

  string username;
  cout << "Enter the username you want to search for: ";
  cin >> ws;
  getline(cin, username);

  User *user = m.findUser(username);
  if (user == nullptr)
  {
    cout << "User not found!\n";
    return;
  }

  cout << "User found!\n";
  user->displayPublicData();
}

void signup(Manager &m)
{

  User *newUser = getUserFromInput(m.getUsers());
  m.addNewUser(newUser);
}

void login(Manager &m)
{
  if (m.getCurrentUser() != nullptr)
  {
    cout << "A user is already logged in!\n";
    return;
  }
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

void displayNewsFeed(Manager &m)
{
  // Write code to display the current users posts
  if (m.getCurrentUser() == nullptr)
  {
    cout << "No user is logged in!\n";
    return;
  }

  cout << "Your posts:\n";
  for (int i = 0; i < m.getCurrentUser()->getNumPosts(); i++)
  {
    cout << m.getCurrentUser()->getPost(i).getContent() << endl;
  }
}

void createPost(Manager &m)
{
  if (m.getCurrentUser() == nullptr)
  {
    cout << "No user is logged in!\n";
    return;
  }

  string content;
  cout << "Enter the content of the post: ";
  cin >> ws;
  getline(cin, content);

  m.getCurrentUser()->addPost(Post(content));
  cout << "Post created!\n";
}

void displayFriendsNewsFeed(Manager &m)
{
  if (m.getCurrentUser() == nullptr)
  {
    cout << "No user is logged in!\n";
    return;
  }

  for (int i = 0; i < m.getCurrentUser()->getNumFriends(); i++)
  {
    FriendRelationship userFriend = m.getCurrentUser()->getFriend(i);
    if (userFriend.status == ACCEPTED)
    {
      User *friendUser = m.findUser(userFriend.friendUsername);
      cout << "Posts of " << friendUser->getUsername() << ":\n";
      for (int j = 0; j < friendUser->getNumPosts(); j++)
      {
        cout << friendUser->getPost(j).getContent() << endl;
      }
    }
  }
}

void printMenu()
{
  int userChoice;
  Manager m;

  // m.loadUsersFromFile();
  // m.loadFriendsFromFile();

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
    cout << "10. Display friends list\n";
    cout << "11. Newsfeed\n";
    cout << "12. Display friends posts\n";
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
      cout << "Confirm again by entering 0!\n";
      cin >> userChoice;
      if (userChoice != 0)
        continue;

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
      createPost(m);
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
      searchUser(m);
    }
    else if (userChoice == 10)
    {
      displayFriends(m);
    }
    else if (userChoice == 11)
    {
      displayNewsFeed(m);
    }
    else if (userChoice == 12)
    {
      displayFriendsNewsFeed(m);
    }
  }

  // m.saveUsersToFile();
  // m.saveFriendsToFile();
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
