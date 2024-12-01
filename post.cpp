#pragma once
#include <iostream>
#include "post.hpp"


using namespace std;

Post::Post(){
  cout << "Post constructor has been called!\n";
}

Post::Post(const Post& p){
  cout << "Post copy constructor has been called!\n";
}
