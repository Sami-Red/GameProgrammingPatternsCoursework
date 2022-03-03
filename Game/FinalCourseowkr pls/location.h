/*

Sami Ramond Uysal
W1730314
Game Programming Patterns Coursework

*/

#pragma once
#ifndef LOCATION
#define LOCATION
#include "Item.h"
#include "Container.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Location
{
private:
	int number;
	string description;
	string name;
	vector <Item> contents;
	map<string, Item> key_items;
	map<string, int> connection;
public:
	Location(int num = 0, string nam = " ", string des = " ")
	{
		number = num;
		description = des;
		name = nam;
	}
	int getNum()
	{
		return number;
	}
	void setNumber(int a)
	{
		number = a;
	}
	vector<Item> getContent()
	{
		return contents;
	}
	void setDescription(string d)
	{
		description = d;
	}
	string getDescription()
	{
		return description;
	}
	string getName()
	{
		return name;
	}
	;
	void setName(string n)
	{
		name = n;
	}
	void addItem(string name, string description)
	{
		contents.push_back(Item(name, description));
	}
	void addKey(string direction, Item item)
	{
		key_items.insert(pair<string, Item>(direction, item));
	}
	void addConnection(string direction, int location)
	{
		connection.insert(pair<string, int>(direction, location));
	}
	Item getKey(string dir)
	{

		auto it = key_items.find(dir);
		if (it == key_items.end())
		{
			cout << "INVALID VALUE\n";
			return Item("SSS");
		}
		Item a = it->second;
		if (a.getName() == "");
		return Item();
		return a;
	}
	int toLocation(string dir)
	{
		auto it = connection.find(dir);
		return it->second;
	}
	vector<string> possibleMoves()
	{
		vector<string> a;
		for (auto i = connection.begin(); i != connection.end(); i++)
		{
			a.push_back(i->first);
		}
		return a;
	}
};


#endif

/*

Sami Ramond Uysal
W1730314
Game Programming Patterns Coursework

*/
