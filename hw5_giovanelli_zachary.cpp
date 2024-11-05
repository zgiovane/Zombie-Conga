/*
  Author: Zachary Giovanelli
  Date: 4/17/2023
  Description: Code that creates a zombie conga line. Using linkedlist and zombie data type
  to output zombies letters to console. Can add zombies remove zombies to the conga line.
*/

//importing libraries
#include "linkedlist_giovanelli.hpp"
#include "zombie_giovanelli.h"
#include <iostream>
#include <string>
#include <time.h>
#include <cmath>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

//forward declaration
void engine_action(LinkedList<Zombie>* list, Zombie randomZomb);
void caboose_action(LinkedList<Zombie>* list, Zombie randomZomb);
void jump_in_action(LinkedList<Zombie>* list, Zombie randomZomb);
void everyone_out_action(LinkedList<Zombie>* list, Zombie randomZomb);
void you_out_action(LinkedList<Zombie>* list, Zombie randomZomb);
void brains_action(LinkedList<Zombie>* list, Zombie randomZomb);
void rainbow_action(LinkedList<Zombie>* list, Zombie randomZomb);
void friends_action(LinkedList<Zombie>* list, Zombie randomZomb);

int main(int argc, char* argv[]) {
  //variables
  int round;
  int rndCount = 0;
  int randAction;
  int zombRound;
  string zombAction;
  int randZombie;
  int randZombie2;
  int randZombie3;
  int randZombie4;
  Zombie zomb;
  char response;
  
  //checks if user gave Seed argument
  if((argc >= 3) && (strcmp(argv[1], "-s")) == 0)
    {
      srand(atoi(argv[2]));
    }
  else
    {
    srand(time(0));
    }

  //begin Zombie conga
  cout << "Welcome! How many rounds would you like to play for?" << endl;
  cin >> round;
  LinkedList<Zombie>* newList = new LinkedList<Zombie>();

  //generates random Zombie character
  randZombie = rand() % 6;

  if(randZombie == 0)
    {
      zomb = Zombie('R');
    }
  else if(randZombie == 1)
    {
      zomb = Zombie('Y');
    }
  else if(randZombie == 2)
    {
      zomb = Zombie('G');
    }
  else if(randZombie == 3)
    {
      zomb = Zombie('B');
    }
  else if(randZombie == 4)
    {
      zomb = Zombie('C');
    }
  else
    {
      zomb = Zombie('M');
    }

  //performs function with given new LinkedList and random Zombie
  rainbow_action(newList, zomb);

  //generate second random Zombie
    randZombie2 = rand() % 6;

  if(randZombie2 == 0)
    {
      zomb = Zombie('R');
    }
  else if(randZombie2 == 1)
    {
      zomb = Zombie('Y');
    }
  else if(randZombie2 == 2)
    {
      zomb = Zombie('G');
    }
  else if(randZombie2 == 3)
    {
      zomb = Zombie('B');
    }
  else if(randZombie2 == 4)
    {
      zomb = Zombie('C');
    }
  else
    {
      zomb = Zombie('M');
    }

  //perform second function with newly generated random Zombie
  brains_action(newList, zomb);

  //generates 3rd random Zombie
  randZombie3 = rand() % 6;

  if(randZombie3 == 0)
    {
      zomb = Zombie('R');
    }
  else if(randZombie3 == 1)
    {
      zomb = Zombie('Y');
    }
  else if(randZombie3 == 2)
    {
      zomb = Zombie('G');
    }
  else if(randZombie3 == 3)
    {
      zomb = Zombie('B');
    }
  else if(randZombie3 == 4)
    {
      zomb = Zombie('C');
    }
  else
    {
      zomb = Zombie('M');
    }

  //performs same function with new random Zombie
  brains_action(newList, zomb);

  //generates 4th random zombie
  randZombie4 = rand() % 6;

  if(randZombie4 == 0)
    {
      zomb = Zombie('R');
    }
  else if(randZombie4 == 1)
    {
      zomb = Zombie('Y');
    }
  else if(randZombie4 == 2)
    {
      zomb = Zombie('G');
    }
  else if(randZombie4 == 3)
    {
      zomb = Zombie('B');
    }
  else if(randZombie4 == 4)
    {
      zomb = Zombie('C');
    }
  else
    {
      zomb = Zombie('M');
    }

  //performs final function with 4th random zombie
  brains_action(newList, zomb);

  //begins conga line iteration
  while(rndCount <= round)
    {
      if(round <= rndCount)
	{
	  cout << "Do you want to continue the party? (y/n):" << endl;
	  cin >> response;
	  if (response == 'Y')
	    {
	      rndCount = 0;
	      cout << "Welcome! How many rounds would you like to play for?" << endl;
	      cin >> round;
	    }
	  else
	    {
	      break;
	    }
	}
      
      if(rndCount % 5 == 0)
	{
	  newList->RemoveFromFront();
	  newList->RemoveFromEnd();
	}
      
      //prints list before any actions are performed 
      cout << "Round: " << rndCount << endl;
      cout << "Size: " << newList->Length() << " :: ";
      newList->PrintList();

      //generates random zombie and random action
      randAction = rand() % 8;
      zombRound = rand() % 6;
      
      if(zombRound == 0)
	{
	  zomb = Zombie('R');
	}
      else if(zombRound == 1)
	{
	  zomb = Zombie('Y');
	}
      else if(zombRound == 2)
	{
	  zomb = Zombie('G');
	}
      else if(zombRound == 3)
	{
	  zomb = Zombie('B');
	}
      else if(zombRound == 4)
	{
	  zomb = Zombie('C');
	}
      else
	{
	  zomb = Zombie('M');
	}
      
      if (randAction == 0)
	{
	  engine_action(newList, zomb);
	  zombAction = "[Engine!]";
	}
      else if (randAction == 1)
	{
	  caboose_action(newList, zomb);
	  zombAction = "[Caboose!]";
	}
      else if (randAction == 2)
	{
	  jump_in_action(newList, zomb);
	  zombAction = "[Jump In!]";
	}
      else if (randAction == 3)
	{
	  everyone_out_action(newList, zomb);
	  zombAction = "[Everyone Out!]";
	}
      else if (randAction == 4)
	{
	  you_out_action(newList, zomb);
	  zombAction = "[You Out!]";
	}
      else if (randAction == 5)
	{
	  brains_action(newList, zomb);
	  zombAction = "[Brains!]";
	}
      else if (randAction == 6)
	{
	  rainbow_action(newList, zomb);
	  zombAction = "[Rainbow!]";
	}
      else
	{
	  friends_action(newList, zomb);
	  zombAction = "[Friends!]";
	}

      //outputs conga line with new random zombie and random actions called
      cout << "New Zombie: " << "[" << zomb << "]" << " -- Action: " << zombAction << endl;
      cout << "The conga line is now:" << endl;
      cout << "Size: " << newList->Length() << " :: ";
      newList->PrintList();
      cout << "**************************************************" << endl;
      cout << endl;
      rndCount++;
      
      if(newList->Length() == 0)
	{
	  cout << "The party is over!" << endl;
	  break;
	}
    }
}

//adds random Zombie to front of the LinkedList
void engine_action(LinkedList<Zombie>* list, Zombie randomZomb)
{
  list->AddToFront(randomZomb);
}

//adds random Zombie to end of the LinkedList
void caboose_action(LinkedList<Zombie>* list, Zombie randomZomb)
{
  list->AddToEnd(randomZomb);
}

//inserts a random zombie at random index within LinkedList
void jump_in_action(LinkedList<Zombie>* list, Zombie randomZomb)
{
  int position = rand() % (list->Length()+1);
  list->AddAtIndex(randomZomb, position);
}


//Removes all zombies with certain character from LinkedList
void everyone_out_action(LinkedList<Zombie>* list, Zombie randomZomb)
{
   list->RemoveAllOf(randomZomb);
}


//removes first instance of Zombie with certain character
void you_out_action(LinkedList<Zombie>* list, Zombie randomZomb)
{
  //remove first matching zombie from list
  //find matching zombie
  //remove from list
  list->RemoveTheFirst(randomZomb);
}

//generates to matching zombies to random zombie and adds them to list
void brains_action(LinkedList<Zombie>* list, Zombie randomZomb)
{
  //generate two more matching Zombies
  Zombie zombMatch1 = Zombie(randomZomb);
  Zombie zombMatch2 = Zombie(randomZomb);
  //add one to front engine_action
  engine_action(list, randomZomb);
  //add one to end caboose_action
  caboose_action(list, zombMatch1);
  //add one to middle /round down
  int index = floor(list->Length()/2);
  list->AddAtIndex(zombMatch2, index);
}

//calls 2 other functions to add random zombie to front and
//corresponding zombies to end of list
void rainbow_action(LinkedList<Zombie>* list, Zombie randomZomb)
{
  engine_action(list,randomZomb);  
  Zombie zombR = Zombie('R');
  caboose_action(list, zombR);
  Zombie zombY = Zombie('Y');
  caboose_action(list, zombY);
  Zombie zombG = Zombie('G');
  caboose_action(list, zombG);
  Zombie zombB = Zombie('B');
  caboose_action(list, zombB);
  Zombie zombC = Zombie('C');
  caboose_action(list, zombC);
  Zombie zombM = Zombie('M');
  caboose_action(list, zombM);
}

//finds Zombie matching given random Zombie and adds either before
// or after depending on random value of coinFlip
void friends_action(LinkedList<Zombie>* list, Zombie randomZomb)
{
  if (list->ElementExists(randomZomb))
    {
      int coinFlip = rand() % 2;
      if(list->Find(randomZomb) == nullptr)
	{
	  return;
	}
      else
	{
      if(coinFlip == 0)
	{
	  list->AddBefore((list->Find(randomZomb)), randomZomb);
	}
      else
	{
	  list->AddAfter((list->Find(randomZomb)), randomZomb);
	}
	}
    }
    else
      {
	caboose_action(list, randomZomb);
      }
}

