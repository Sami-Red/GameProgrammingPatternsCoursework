/*

Sami Ramond Uysal
W1730314
Game Programming Patterns Coursework

*/


#pragma once
#ifndef ITEM
#define ITEM
#include<string>
using namespace std;

class Item
{
	string name;
	string description;
public:
	Item(string n = "", string d = "")
	{
		name = n;
		description = d;
	}
	/*Item(Item& a)
	{
		name = a.getName();
		description = a.getDescription();
	}*/
	void setName(string a_name)
	{
		name = a_name;
	}
	void setDescription(string a_description)
	{
		description = a_description;
	}
	string getName() const
	{
		return name;
	}
	string getDescription() const
	{
		return description;
	}
	friend bool operator==(Item t1, Item t2);
};

bool operator==(Item t1, Item t2)
{
	return t1.getName() == t2.getName();
}
#endif // !ITEM

/*

Sami Ramond Uysal
W1730314
Game Programming Patterns Coursework

*/

