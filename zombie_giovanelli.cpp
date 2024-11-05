/*
  Author: Zachary Giovanelli
  Date: 4/17/2023
  Description:Defines all methods for Zombie class 
*/

#include "zombie_giovanelli.h"
#include <iostream>
#include <string>

//method definitions of class Zombie
//constructor
Zombie::Zombie() {
  this->type = 'Z';
}

//constructor
Zombie::Zombie(char z) {
  this->type = z;
}

//getter
char Zombie::getType() {
  return type;
}

//operator overloader to compare Zombie values
bool Zombie::operator==(const Zombie& other) {
  return this->type == other.type;
}

//operator overloader to print Zombie value out
std::ostream& operator<<(std::ostream& out, const Zombie& self)
{
  out << self.type;
  return out;
}
