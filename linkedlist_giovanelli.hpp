/*
  Author: Zachary Giovanelli
  Date: 4/17/23
  Description: Forward declarations and method definitions for a Node and LinkedList data
  structure. Template to accept any data type such as Zombie.
*/

#include <iostream>
#include <string>
#pragma once

using std::string;
using std::cout;
using std::cin;
using std::endl;

//templating
template<typename T> class LinkedList;

//template for class Node
//declarations
template<typename T>
class Node
{
  friend class LinkedList<T>;
private:
  T data;
  Node<T>* next;
  Node<T>* previous;
  
public:
  //constructors
  Node<T>(); 
  Node<T>(T);
  Node<T>(T, Node<T>*, Node<T>*);
  
  //getters & setters
  T getData();
  void setData(T);
  Node<T>* getNext();
  void setNext(Node<T>*);
  Node<T>* getPrevious();
  void setPrevious(Node<T>*);
  
};

//Node method definitions
template<typename T>
Node<T>::Node()
{
  next = nullptr;
  previous = nullptr;
}

template<typename T>
Node<T>::Node(T data)
{
  this->data = data;
  next = nullptr;
  previous = nullptr;
}

template<typename T>
Node<T>::Node(T data, Node<T>* next, Node<T>* previous)
{
  this->data = data;
  this->next = next;
  this->previous = previous;
}

template<typename T>
T Node<T>::getData()
{
  return data;
}

template<typename T>
void Node<T>::setData(T data)
{
  this->data = data;
}

template<typename T>
Node<T>* Node<T>::getNext()
{
  return next;
}

template<typename T>
void Node<T>::setNext(Node<T>* next)
{
  this->next = next;
}

template<typename T>
Node<T>* Node<T>::getPrevious()
{
  return previous;
}

template<typename T>
void Node<T>::setPrevious(Node<T>* previous)
{
  this->previous = previous;
}

//templating for LinkedList class
// and declarations
template<typename T>
class LinkedList
{
private:
  Node<T>* head;
  Node<T>* tail;
  int count;
  
public:
  LinkedList(); //constructor
  ~LinkedList(void); // destructor
  void AddToFront(T);
  void AddToEnd(T);
  void AddAtIndex(T, int);
  void AddBefore(Node<T>*, T);
  void AddAfter(Node<T>*, T);
  T RemoveFromFront();
  T RemoveFromEnd();
  void RemoveTheFirst(T);
  void RemoveAllOf(T);
  T RemoveBefore(Node<T>*);
  T RemoveAfter(Node<T>*);
  bool ElementExists(T);
  Node<T>* Find(T);
  int IndexOf(T);
  T RetrieveFront();
  T RetrieveEnd();
  T Retrieve(int);
  void PrintList();
  void Empty();
  int Length(); 
};

//LinkedList method definitions
//constructor
template<typename T>
LinkedList<T>::LinkedList()
{
  head = nullptr;
  tail = nullptr;
}

//destructor
template<typename T>
LinkedList<T>::~LinkedList()
{
  Node<T>* current = head;
  while(current != nullptr)
    {
      current = current->getNext();
      delete head;
      head = current; 
    }
}

//adding Node to front of LinkedList
template<typename T>
void LinkedList<T>::AddToFront(T data) {
  if (head == nullptr)
    {
      //using constructor 
      Node<T>* newNode = new Node<T>(data, nullptr, nullptr);
      //setting head to newNode
      head = newNode;
      tail = newNode;
    }
  else
    {
      //using constructor
      Node<T>* newNode = new Node<T>(data, head, nullptr);
      //setting the previous pointer of head to newNode
      head->setPrevious(newNode);
      //setting the head to newNode
      head = newNode;
    }
}

//adding Node to end of LinkedList
template<typename T>
void LinkedList<T>::AddToEnd(T data) {
  if (tail == nullptr)
    {
      //using constructor 
      Node<T>* newNode = new Node<T>(data, nullptr, nullptr);
      //setting head to newNode
      tail = newNode;
      head = newNode;
    }
  else
    {
      //using constructor
      Node<T>* newNode = new Node<T>(data, nullptr, tail);
      //setting the previous pointer of head to newNode
      tail->setNext(newNode);
      //setting the head to newNode
      tail = newNode;
    }
}

//adding Node at specified index
template<typename T>
void LinkedList<T>::AddAtIndex(T data, int index) {
  if(index < 0 || (index > Length()))
    {
      throw std::out_of_range("Index below 0 or greater than size of list");
    }
  else if (index == 0)
    {
      AddToFront(data);
    }
  else if (index == Length())
    {
      AddToEnd(data);
    }
  else
    {
      // setting node pointer <current> equal to the head
      //assigning it to the stack
      Node<T>* current = head;
      for(int i = 0; i < index; i++)
	{
	  current = current->getNext();
	}
      Node<T>* newNode = new Node<T>(data, current, current->getPrevious()); 
      current->getPrevious()->setNext(newNode);
      current->setPrevious(newNode);
    }
}

//adding Node before a node pointer
template<typename T>
void LinkedList<T>::AddBefore(Node<T>* current, T data) {
  if(current->getPrevious() == nullptr)
    {
      AddToFront(data);
    }
  else
    {
      Node<T>* newNode = new Node<T>(data, current, current->getPrevious());
      current->getPrevious()->setNext(newNode);
      current->setPrevious(newNode);
    }
}

//adding a Node after a pointer node
template<typename T>
void LinkedList<T>::AddAfter(Node<T>* current, T data) {
  if(current->getNext() == nullptr)
    {
      AddToEnd(data);
    }
  else
    {
      Node<T>* newNode = new Node<T>(data, current->getNext(), current);
      current->getNext()->setPrevious(newNode);
      current->setNext(newNode);
    }
}

//removing Node from front of LinkedList
template<typename T>
T LinkedList<T>::RemoveFromFront() {
 Node<T>* current = head;
  if(head == nullptr)
    {
      throw std::invalid_argument("Head is null");
    }
  else if(current->getNext() == nullptr)
    {
      head = nullptr;
      return head->getData();
    }
  else
    {
  head = head->getNext();
  head->setPrevious(nullptr);
  delete current;
  return head->getData();
    }
}

//removing Node from end of LinkedList
template<typename T>
T LinkedList<T>::RemoveFromEnd() {
  Node<T>* current = head;
  if(current == nullptr)
    {
      throw std::invalid_argument("Can't remove from empty list!");
    }
  else if(current->getNext() == nullptr)
    {
      head = nullptr;
      return head->getData();
    }
  else
    {
  while (current->getNext()->getNext() != nullptr)
    {
      current = current->getNext();
    }
  current->setNext(nullptr);
  tail->setPrevious(nullptr);
  delete tail;
  tail = current;
  return tail->getData();
    }
}

//removing the first instance of a Node value
template<typename T>
void LinkedList<T>::RemoveTheFirst(T data) {
  Node<T>* current = head;
  if(current == nullptr)
    {
      throw std::invalid_argument("List is empty");
    }
  else if (head->getData() == data)
    {
      RemoveFromFront();
    }
  else if (tail->getData() == data)
    {
      RemoveFromEnd();
    }
  else 
    {
  while(current != nullptr)
    {
      if(current->getData() == data)
	{
	  current->getNext()->setPrevious(current->getPrevious());
	  current->getPrevious()->setNext(current->getNext());
	  current->setNext(nullptr);
	  current->setPrevious(nullptr);
	  delete current;
	  return;
	}
      current = current->getNext();
    }
    }
}

//remocing all instances of a Node value
template<typename T>
void LinkedList<T>::RemoveAllOf(T data) {
  while(ElementExists(data) != false)
    {
      RemoveTheFirst(data);
    }
}


//removing a node before a given pointer Node
template<typename T>
T LinkedList<T>::RemoveBefore(Node<T>* current) {
  if(current == head)
    {
      throw std::out_of_range("Node given is Head. No node before head.");
    }
  else if (current->getPrevious() == head)
    {
      return RemoveFromFront();
    }
  else
    {
      Node<T>* temp = head;
      while(temp->getNext() != current)
	{
	  temp = temp->getNext();
	}
      temp->getNext()->setPrevious(temp->getPrevious());
      temp->getPrevious()->setNext(current);
      temp->setNext(nullptr);
      temp->setPrevious(nullptr);
      delete temp;
      return current->getData();
    }
}

//removing a node after a given pointer Node
template<typename T>
T LinkedList<T>::RemoveAfter(Node<T>* current) {
  if(current == tail)
    {
      throw std::out_of_range("Node give is Tail. No node after Tail.");
    }
  else if(current->getNext() == tail)
    {
      return RemoveFromEnd();
    }
  else
    {
      Node<T>* temp = head;
      while(temp != current->getNext())
	{
	  temp = temp->getNext();
	}
      temp->getPrevious()->setNext(temp->getNext());
      temp->getNext()->setPrevious(current);
      temp->setNext(nullptr);
      temp->setPrevious(nullptr);
      delete temp;
      return current->getData();
    }
}

//checking if a Node value exists in LinkedList
template<typename T>
bool LinkedList<T>::ElementExists(T data) {
  Node<T>* current = head;
  while(current != nullptr)
    {
      if(current->getData() == data)
	{
	  return true;
	}
      else
	{
	  current = current->getNext();
	}
    }
  return false;
}

//find a Node value in a LinkedList
template<typename T>
Node<T>* LinkedList<T>::Find(T data) {
  Node<T>* current = head;
  while(current != nullptr)
    {
      if(current->getData() == data)
	{
	  return current;
	}
      current = current->getNext();
    }
  return nullptr;
}

//finding index of a given Node value
template<typename T>
int LinkedList<T>::IndexOf(T data) {
  if(ElementExists(data) == false)
    {
      return -1;
    }
  else
    {
      int count = 0;
      Node<T>* current = head;
      while(current != nullptr)
	{
	  if(current->getData() == data)
	    {
	      return count;
	    }
	  current = current->getNext();
	  count++;
	}
      return -1;
    }
}

//retrieving the first Node in a LinkedList
template<typename T>
T LinkedList<T>::RetrieveFront() {
  if(head == nullptr)
    {
      throw std::invalid_argument("Can't retrieve the head from empty list!");
    }
  return head->getData();
}

//retrieving a Node from the end of a LinkedList
template<typename T>
T LinkedList<T>::RetrieveEnd() {
  if(head == nullptr)
    {
      throw std::invalid_argument("Can't retrive the end from empty list!");
    }
  return tail->getData();
}

//retrieving a Node from a given index
template<typename T>
T LinkedList<T>::Retrieve(int index) {
  Node<T>* current = head;

  if(index < 0 || index > Length())
    {
      throw std::out_of_range("Index is less than 0 or greater than list size!");
    }
  else
    {
      while(current != nullptr)
      {
	if(IndexOf(current->getData()) == index)
	  {
	    return current->getData();
	  }
	current = current->getNext();
      }
      return current->getData();
    }
}

//printing all contents of a LinkedList
template<typename T>
void LinkedList<T>::PrintList() {
  Node<T>* current = head;
  if(current == nullptr)
    {
      cout << ("List is empty!") << endl;
    }
  while(current != nullptr)
    {
      cout << "[" << current->getData();
      if(current->getNext() == nullptr)
	{
	  cout << "]";
	}
      else
	{
	  cout << "]=";
	} 
      current = current->getNext();
    }
  cout << endl;
  delete current; 
}

//emptying all Nodes in a LinkedList
template<typename T>
void LinkedList<T>::Empty() {
  Node<T>* current = head;
  while(current != nullptr)
    {
      current = current->getNext();
      delete head;
      head = current; 
    }
}

//returns the size of a LinkedList
template<typename T>
int LinkedList<T>::Length() {
  int count = 0;
  Node<T>* current = head;
  while(current != nullptr)
    {
      count += 1;
      current = current->getNext();
    }
  return count;
}
