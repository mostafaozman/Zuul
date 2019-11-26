#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <map>
#include "room.h"
#include "item.h"

using namespace std;

void initializeRooms(vector<Room*>* rooms);
void initializeItems(vector<Item*>* items);
void printRoom(vector<Room*>* rooms, vector<Item*>* items, int currentRoom);
void printInventory(vector<Item*>* items, vector<int> inventory);
void pickItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]);
void dropItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[]);
int move(vector<Room*>* rooms, int currentRoom, char direction[]); 


int main()
{
  vector<Room*> rooms;
  vector<Item*> items;
  vector<int> inventory;
  char input[30];
  int currentRoom = 1;
  initializeItems(&items);
  initializeRooms(&rooms);

  cout << "You find yourself in the dark stranded at school. The doors all around the perimiter are locked, can you get out?" << endl; 

  cout << "\n" << "type 'help' if you need help" << endl;

  

}

void initializeItems(vector<Item*>* items)
{
  // key
  Item* key = new Item();
  key -> setName((char*)("Janitor Key"));
  key -> setID(1);
  items -> push_back(key);
  //coins
  Item* coin = new Item();
  coin -> setName((char*)("Two Quarters"));
  coin -> setID(2);
  items -> push_back(coin);
  //Screw
  Item* screw = new Item();
  screw -> setName((char*)("A half inch screw"));
  screw -> setID(3);
  items	-> push_back(screw);
  // light bulb
  Item* light = new Item();
  light -> setName((char*)("LED light bulb"));
  light -> setID(4);
  items	-> push_back(coin);
  // Screw Driver
  Item* driver = new Item();
  driver -> setName((char*)("A screw driver"));
  driver -> setID(5);
  items -> push_back(driver); 
}

void printRoom(vector<Room*>* rooms, vector<Item*>* items, int currentRoom)
{
  vector<Room*>::iterator i;
  vector<Item*>::iterator j;

  for ( i = rooms -> begin(); i != rooms -> end(); i++)
    {
      if (currentRoom == (*i) -> getID())
	{
	  cout << (*i) -> getDescription() << "." << endl;
	  cout << "Your exits are: ";
	  for (map<int, char*>::const_iterator it = (*i) -> getExit() -> begin(); it != (*i) -> getExit() -> end(); i++)
	    {
	      cout << it -> second << " "; 
	    }
	  cout << endl;
	  cout << "In this room there are: " << endl;
	  for (z = items -> begin(); z != items -> end(); z++)
	    {
	      if((*i) -> getItem() == (*z) -> getID())
		{
		  cout << (*z) -> getName() << endl; 
		}
	    }
	  cout << endl;
	  break; 
	}
    }
}

void printInventory(vector<Item*>* items, vector<int> inventory)
{
  vector<int>::iterator i;
  vector<Item*>::iterator j;

  for (i = inventory.begin(); i != inventory.end(); i++)
    {
      for (j = items -> begin(); j != items -> end(); j++)
	{
	  if( *i == (*j) -> getID())
	    {
	      cout << (*j) -> getName() << endl; 
	    }
	}
    }
  cout << endl; 

}

void pickItem(vector<Room*>* rooms, vector<Item*>* items, vector<int>* inventory, int currentRoom, char name[])
{
  vector<Room*>::iterator i;
  vector<Item*>::iterator j;
}
