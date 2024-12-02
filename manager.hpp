#pragma once
#include <string>
#include "user.hpp"
#include <fstream>
#include "BST.hpp"
#include "LinkedList.hpp"

struct BstUserEntry
{
  User *user;
  string username;

  bool operator<(const BstUserEntry &other)
  {
    return username < other.username;
  }

  bool operator>(const BstUserEntry &other)
  {
    return username > other.username;
  }

  bool operator==(const BstUserEntry &other)
  {
    return username == other.username;
  }

  bool operator!=(const BstUserEntry &other)
  {
    return username != other.username;
  }

  bool operator<=(const BstUserEntry &other)
  {
    return username <= other.username;
  }

  bool operator>=(const BstUserEntry &other)
  {
    return username >= other.username;
  }
};

class Manager
{
  LinkedList<User *> users;

  User *currentUser;

  BST<BstUserEntry> userBst;

public:
  Manager()
  {
    this->currentUser = nullptr;
  }

  User *searchUser(string username)
  {
    BST<BstUserEntry>::BSTNode *node = userBst.getRootNode();

    while (node != nullptr)
    {
      if (node->data.username == username)
      {
        return node->data.user;
      }
      else if (node->data.username < username)
      {
        node = node->right;
      }
      else
      {
        node = node->left;
      }
    }

    return nullptr;
  }

  void logout()
  {
    currentUser = nullptr;
  }

  User *getCurrentUser()
  {
    return currentUser;
  }

  bool login(string username, string password)
  {
    for (int i = 0; i < users.size(); i++)
    {
      if (users[i]->getUsername() == username && users[i]->getPassword() == password)
      {
        currentUser = users[i];
        return true;
      }
    }
    return false;
  }

  User *findUser(string username)
  {
    for (int i = 0; i < users.size(); i++)
    {
      if (users[i]->getUsername() == username)
      {
        return users[i];
      }
    }
    return nullptr;
  }

  LinkedList<User *> &getUsers()
  {
    return users;
  }

  void addNewUser(User *user)
  {
    if (user == nullptr)
      return;

    users.insertLast(user);
    BstUserEntry entry;
    entry.user = user;
    entry.username = user->getUsername();

    userBst.insert(entry);
  }

  void printAllUsers()
  {
    for (int i = 0; i < users.size(); i++)
    {
      cout << users[i]->getUsername() << endl;
    }
  }

  void loadUsersFromFile(string filename = "users.txt")
  {
    ifstream file(filename);

    if (!file.is_open())
    {
      cout << "User File not found! Creating empty file!\n";

      ofstream newFile(filename);
      newFile.close();

      return;
    }

    string username, password, city;
    while (file)
    {
      getline(file, username);
      if (!file)
        break;
      getline(file, password);
      getline(file, city);
      User *newUser = new User(username, password, city);
      addNewUser(newUser);
    }

    file.close();
  }

  void saveUsersToFile(string filename = "users.txt")
  {
    ofstream file(filename);

    for (int i = 0; i < users.size(); i++)
    {
      file << users[i]->getUsername() << "\n"
           << users[i]->getPassword() << "\n"
           << users[i]->getCity();

      if (i != users.size() - 1)
      {
        file << "\n";
      }
    }

    file.close();
  }

  void saveFriendsToFile(string filename = "friends.txt")
  {
    ofstream file(filename);

    for (int i = 0; i < users.size(); i++)
    {
      for (int j = 0; j < users[i]->getNumFriends(); j++)
      {
        file << users[i]->getUsername() << "\n"
             << users[i]->getFriend(j).friendUsername << "\n"
             << users[i]->getFriend(j).status;

        if (i != users.size() - 1 || j != users[i]->getNumFriends() - 1)
        {
          file << "\n";
        }
      }
    }

    file.close();
  }

  void loadFriendsFromFile(string filename = "friends.txt")
  {
    ifstream file(filename);

    if (!file.is_open())
    {
      cout << "Friends File not found! Creating empty file!\n";

      ofstream newFile(filename);
      newFile.close();

      return;
    }

    string username, friendUsername, status;
    while (file)
    {
      getline(file, username);
      if (!file)
        break;
      getline(file, friendUsername);
      getline(file, status);

      User *user = findUser(username);
      if (user != nullptr)
      {
        user->addFriend(friendUsername, (RelationshipStatus)stoi(status));
      }
    }

    file.close();
  }

  void savePostsToFile(string filename = "posts.txt")
  {
    ofstream file(filename);

    for (int i = 0; i < users.size(); i++)
    {
      for (int j = 0; j < users[i]->getNumPosts(); j++)
      {
        file << users[i]->getUsername() << "\n"
             << users[i]->getPost(j).getContent();

        if (i != users.size() - 1 || j != users[i]->getNumPosts() - 1)
        {
          file << "\n";
        }
      }
    }

    file.close();
  }

  void loadPostsFromFile(string filename = "posts.txt")
  {
    ifstream file(filename);

    if (!file.is_open())
    {
      cout << "Posts File not found! Creating empty file!\n";

      ofstream newFile(filename);
      newFile.close();

      return;
    }

    string username, content;

    while (file)
    {
      getline(file, username);
      if (!file)
        break;
      getline(file, content);

      User *user = findUser(username);
      if (user != nullptr)
      {
        user->addPost(Post(content));
      }
    }

    file.close();
  }
};
