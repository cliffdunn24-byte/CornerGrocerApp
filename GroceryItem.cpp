#include "GroceryItem.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

map<string, GroceryItem*> GroceryItem::inventory;

//Default constructor initializing name and quantity
GroceryItem::GroceryItem() :
	name("none"), quantity(0) { }

//Constructor initializing grocery item with provided name and quantity
GroceryItem::GroceryItem(const string& name, int quantity) :
	name(name), quantity(quantity) { }

//Returns the name of the grocery item
string GroceryItem::getName() const {
	return name;
}

//Returns the quantity of the grocery item
int GroceryItem::getQuantity() const {
	return quantity;
}

//Looks up an item in the inventory map
GroceryItem* GroceryItem::itemLookup(const string& name) {

	//Check if the item exists in the inventory
	if (inventory.count(name)) {
		return inventory[name];
	}

	return nullptr;
}

//Provides read only access to the inventory map
const std::map<std::string, GroceryItem*>& GroceryItem::getInventory() {
	return inventory;
}

//Loads inventory data from a file
bool GroceryItem::loadFile(const string& fileName) {

	//Clear existing inventory before loading new data
	inventory.clear();

	ifstream file(fileName);

	if (!file.is_open()) {
		return false;
	}

	string itemName;

	//Read each line of the file as a grocery item name
	while (getline(file, itemName)) {

		//Increment quantity if the item already exists
		if (inventory.count(itemName)) {
			inventory[itemName]->quantity++;
		}

		//Create new grocery item if the items is not found
		else {
			inventory[itemName] = new GroceryItem(itemName, 1);
		}

	
	}

	file.close();

	return true;
}

//Writes inventory data to backup file
void GroceryItem::writeBackupFile() {

	ofstream outFile("frequency.dat");

	//Write each item and its quantity to the backup file
	for (const auto& pair : inventory) {
		outFile << pair.first << " " << pair.second->getQuantity() << endl;
	}
}