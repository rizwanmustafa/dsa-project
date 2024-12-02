#pragma once
#include <string>

using namespace std;

class Post
{
private:
  string content;

public:
  Post();
  Post(string content);
  Post(const Post &p);
  string getContent() const;
};