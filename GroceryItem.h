#pragma once
#include <string>
#include <map>

class GroceryItem {

public:

	//Default constructor that initializes an empty grocery item
	//@returns - nothing
	//@throws - nothing
	GroceryItem();

	//Creates a grocery item with a name and quantity
	//@param name - the name of the grocery item
	//@param quantity - the quantity of the grocery item
	//@returns - nothing
	//@throws - nothing
	GroceryItem(const std::string& name, int quantity);

	//Gets the name of the grocery item
	//@returns - the item's name
	//@throws - nothing
	std::string getName() const;

	//Gets the quantity of the grocery item
	//@returns - the item's quantity
	//@throws - nothing
	int getQuantity() const;

	//Loads inventory data from a file and fills the inventory map
	//@param fileName - the name of the file to load
	//@returns - true if the file was sucessfully opened, false otherwise
	//@throws - nothing
	static bool loadFile(const std::string& fileName);

	//Searches the inventory for an item by name
	//@param name - the name of the item to search for
	//@returns - pointer to the GroceryItem if found, otherwise nullptr
	//@throws - nothing
	static GroceryItem* itemLookup(const std::string& name);

	//Provides read only access to the inventory map
	//@returns - constant reference to the inventory map
	//@throws - nothing
	static const std::map<std::string, GroceryItem*>& getInventory();

	//Writes a backup file containing the inventory data
	//@returns - nothing
	//@throws - nothing
	static void writeBackupFile();

private:
	static std::map<std::string, GroceryItem*> inventory;
	std::string name;
	int quantity;

	

};