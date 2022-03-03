/*

Sami Ramond Uysal
W1730314
Game Programming Patterns Coursework

*/


#pragma once
#ifndef CONTAINER
#define CONTAINER
#include"Item.h"
#include <iostream>
#include <vector>
using namespace std;

class Container : public Item
{
public:
	vector<Item> content;
	Item key_item;
	bool opened;
public:
	Container(string n, string des, vector<Item> con, Item key) :Item(n, des)
	{
		content = con;

		key_item = key;
		opened = false;
	}
	bool open(vector<Item>& inven)
	{
		for (int i = 0; i < inven.size(); i++)
		{
			if (key_item == inven[i]) {
				opened = true;
				return true;
			}
		}
		return opened;
	}
	vector<Item> getContent()
	{

		return content;
	}


};


#endif // !CONTAINER

/*

Sami Ramond Uysal
W1730314
Game Programming Patterns Coursework

*/
