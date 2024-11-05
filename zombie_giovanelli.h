/*
  Author: Zachary Giovanelli
  Date: 4/17/2023
  Description: Zombie declarations class for data types for Nodes
*/

#pragma once
#include <iostream>

//Zombie class declarations
class Zombie
{
  //variables
 private:
  char type;

  //constructors
 public:
  Zombie();
  Zombie(char);

  //getter
  char getType();

  //operator overloading
  bool operator==(const Zombie&);
  friend std::ostream &operator<<(std::ostream& out, const Zombie& self);
};
