#pragma once
#include <string>
class Post{
  private:
  string content;
  public:
  Post(string content);
  Post(const Post& p);
  string getContent() const;

};