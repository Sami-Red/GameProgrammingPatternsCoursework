/*

Sami Ramond Uysal
W1730314
Game Programming Patterns Coursework

*/



#include<iostream>
#include <fstream>
#include<string>
#include"Item.h"
#include "Player.h"
#include "location.h"
#include "Container.h"
#include <sstream>

using namespace std;

int main()
{
	ifstream file;
	file.open("stuff.txt");
	vector<Item> items;
	vector<Location> locations;
	string tempLine;
	while (!file.eof())
	{
		string line;
		if (tempLine.size() < 2)
		{
			file >> line;
		}
		else
			line = tempLine;
		if (line == "  ")
		{
			break;
		}
		if (line == "Item:")
		{
			string name;
			getline(file, name);
			string desc;
			file >> line;
			getline(file, desc);
			file >> line;
			if (line == "Item:" or line == "Location:")
			{
				tempLine = line;
			}
			if (line == "Contents:")
			{
				vector<Item> con;
				getline(file, line);
				stringstream ss(line);
				string itemss;
				while (getline(ss, itemss, ','))
				{
					con.push_back(Item(itemss));
				}
				file >> line;

				file >> line;
				items.push_back(Container(name, desc, con, Item(line)));
				//tempLine = "Item:";
			}
			else
			{
				Item temp(name, desc);
				items.push_back(temp);

			}
		}
		else if (line == "Location:")
		{
			tempLine = "";
			int num;
			file >> num;
			string name, desc, content;
			file >> line;
			getline(file, name);
			file >> line;
			getline(file, desc);
			Location l(num, name, desc);
			file >> line;
			if (line == "Contents:")
			{

				vector<string> con;
				getline(file, line);
				stringstream ss(line);
				string itemss;
				while (getline(ss, itemss, ','))
				{
					con.push_back(itemss);

				}
				for (int i = 0; i < con.size(); i++)
				{
					l.addItem(con[i], "");


				}

				while (true)
				{
					getline(file, line);

					if (line == "Location:")
					{
						tempLine = line;
						break;
					}
					if (line == " ")
					{
						break;
					}
					stringstream ss(line);
					string dir;
					ss >> dir;
					int locNum;
					ss >> locNum;
					string key;
					char ch;
					ss >> ch;
					getline(ss, key);
					l.addConnection(dir, locNum);
					l.addKey(dir, Item(key));


				}
			}
			locations.push_back(l);

		}


	}

	Player p(locations[0]);

	while (true)
	{
		p.printStatus();
		if (p.getLocationName() == " Exit")
		{
			cout << "You have reached exit point and won game";
			return 0;
		}
		cout << "You have following options\n";
		vector<string> moves = p.possibleMoves();
		if (moves.size() > 0)
		{
			for (int i = 0; i < moves.size(); i++)
			{
				cout << "move to " << moves[i] << endl;
			}
		}
		vector<Item> con = p.getContent();
		if (con.size() > 0)
		{
			cout << "You can pickup following\n";

			for (int i = 0; i < con.size(); i++)
			{
				cout << i + 1 << con[i].getName() << endl;
			}
		}
		int choice = 0;
		while (true)
		{
			cout << "Press 1 to move in direction or 2 to pickup item: ";
			cin >> choice;
			if (choice == 1)
			{
				string str;
				cout << "Enter direction (WEST/EAST etc.): ";
				cin >> str;
				//str = " " + str;
				Item t = p.getKey(str);
				if (p.hasItem(t) || t == Item())
				{

					int aval = 0;
					aval = p.toLocation(str);
					for (int i = 0; i < locations.size(); i++)
					{
						if (locations[i].getNum() == aval)
						{
							p.updateLocation(locations[i]);
							cout << "\nLOCATION UPDATED!\n";
							break;
						}
					}
				}
				else
					cout << "You need an item to move in this direction!!!\n";
				break;
			}
			else if (choice == 2)
			{
				int inum;
				cout << "Enter item number you want to pickup\n";
				cin >> inum;
				if (inum<1 || inum>con.size())
				{
					cout << "INVALID OPTION\n";
				}
				else
				{
					if (con[inum - 1].getName() == " Strongbox")
					{
						p.addItem(Item(" Red Key"));
					}
					else
					{
						p.addItem(con[inum - 1]);
					}
				}
				break;
			}
			else
				cout << "Invalid choice try again\n";
		}
		cout << endl;
	}
	return 0;
}


/*

Sami Ramond Uysal
W1730314
Game Programming Patterns Coursework

*/
