#pragma once
#include <iostream>
#include "post.hpp"


using namespace std;

Post::Post(){
  this->content = "";
}

Post::Post(string content){
    this->content = content;
}

Post::Post(const Post& p){
  cout << "Post copy constructor has been called!\n";
}


string Post::getContent() const{
    return this->content;
}
