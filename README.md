# Templated Doubly-Linked List & Zombie Conga Line

This repository involves implementing a reusable, templated doubly-linked list in C++ and using it to create a "Zombie Conga Line" simulation. 

### Topics Covered
- C/C++ Syntax
- Pointers
- Dynamic Memory Allocation
- Data Structures (Linked Lists)
- Object-Oriented Programming

## Project Overview

The project is designed to build a Doubly-Linked List from scratch in C++, which can store any data type using C++ templates. Additionally, a simulation called "Zombie Conga" is implemented using this linked list structure. In the Zombie Conga Line, each node represents a zombie of a certain color (Red, Yellow, Green, Blue, Cyan, or Magenta), and each round a randomly chosen action is applied to the conga line.

### Specifications

#### Core Requirements
- **Templated Linked List**: The Linked List should be fully templated to handle any data type.
- **Zombie Conga Line**: Implement a simulation where zombies of different colors join or leave a conga line based on specific actions.

#### Project Structure
- **Linked List Implementation**: The main part of the project is the creation of a `LinkedList` and `Node` class, both templated.
- **Zombie Class**: A simple `Zombie` class is used to represent each zombie.
- **Conga Actions**: Actions like "Engine," "Caboose," "Brains!" and more are applied to modify the linked list.

#### Exception Handling
Utilize C++ standard exceptions to handle edge cases, such as invalid indices for insertion or deletion.

#### Filename Guidelines
Depending on your implementation choices (e.g., templated or untemplated, including/excluding Zombie Conga), use the following filenames:
- `hw5_<lastname>_<firstname>.cpp`
- `linkedlist_<lastname>.hpp` (for templated Linked List)
- `zombie_<lastname>.h`
- `zombie_<lastname>.cpp`
- `Makefile`

## Classes and Methods

### 1. Linked List Class
Implements the following public interface:
- `AddToFront`, `AddToEnd`, `AddAtIndex`
- `RemoveFromFront`, `RemoveFromEnd`, `RemoveTheFirst`, `RemoveAllOf`
- `RetrieveFront`, `RetrieveEnd`, `Retrieve`
- Additional helper functions, as needed

### 2. Node Class
The `Node` class is used within the linked list and stores:
- `data` (of template type `T`)
- `next` (pointer to the next node)
- `previous` (pointer to the previous node)

### 3. Zombie Class
A simple class that represents a zombie with a color attribute (`type: char`). Overloads `==` operator for comparisons and provides `ostream` overload for output.

### 4. Conga Actions
Actions include:
- **Engine!**: Adds a zombie to the front of the list.
- **Caboose!**: Adds a zombie to the end of the list.
- **Brains!**: Adds multiple zombies at various positions.
- **Rainbow Brains!**: Adds zombies of each color in a set sequence.

### Output
Each round displays:
- The round number and conga line size
- The generated zombie color and action
- The outcome of the action, including the updated conga line.

Example Output:

### Caboose Action
![](https://github.com/zgiovane/Zombie-Conga/blob/main/ExampleOutputs/ZombieCongaCaboose.png)

### JumpIn! Action
![](https://github.com/zgiovane/Zombie-Conga/blob/main/ExampleOutputs/ZombieCongaJumpIn.png)

## Usage
1. **Compile** the project with the provided `Makefile`.
2. **Run** the executable (`exe`).
3. **Input** the number of rounds when prompted.
4. Optionally, provide a seed for randomness with `-s <integer>`.
