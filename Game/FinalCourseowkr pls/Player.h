/*

Sami Ramond Uysal
W1730314
Game Programming Patterns Coursework

*/


#pragma once
#ifndef PLAYER
#define PLAYER
#include "location.h"
#include "Item.h"
#include "Container.h"
#include <iostream>
#include <vector>

class Player
{
private:
	Location position;
	vector<Item> inventory;
	int steps;
public:
	Player(Location l)
	{
		position = l;
	}
	bool hasItem(Item t)
	{
		for (int i = 0; i < inventory.size(); i++)
		{
			if (inventory[i] == t)	return true;
		}
		return false;
	}
	void addItem(Item a)
	{
		inventory.push_back(a);
	}

	void printStatus()
	{
		cout << "Current Location: " << position.getName() << endl;
		cout << "Description: " << position.getDescription() << endl;
		cout << "Inventory: \n";
		for (int i = 0; i < inventory.size(); i++)
		{
			cout << inventory[i].getName() << "  ";
		}
		cout << endl;

	}
	void updateLocation(Location l)
	{
		position = l;
	}
	int toLocation(string str)
	{
		return position.toLocation(str);
	}
	string getLocationName()
	{
		return position.getName();
	}
	vector<string> possibleMoves()
	{
		return position.possibleMoves();
	}
	vector<Item> getContent()
	{
		return position.getContent();
	}
	Item getKey(string dir)
	{
		return position.getKey(dir);
	}
};
#endif // !PLAYER


/*

Sami Ramond Uysal
W1730314
Game Programming Patterns Coursework

*/
