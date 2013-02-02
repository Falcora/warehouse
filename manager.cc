/* This class reads an input file and creates objects for items and warehouses.
 * Also, it calls functions on warehouses as stated by the input file.
 *
 * Fernando Gomez
 */

#include "manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include "warehouse.h"
using namespace std;
using namespace inventory;

int main(int argc, char* argv[]){
  if(argc >2 || argc < 2)
	{
	  cout << "Please include a filename." << endl;
	  return 1;
	}
  string filename = argv[1];
  ifstream inputfile(filename);
  string line;
  
		date startDate;
	 set<item> items;				// Create a set to hold our items.
	 set<warehouse> warehouses;	// Create a set to hold our warehouses.
  
  
  if(inputfile.is_open())
	{
	  while(inputfile.good())
	{
	  getline(inputfile,line, ' ');
	  // The current line is held in 'line'
	  // This is where we read through each line
	  // and call the appropriate functions.
	  
	  // First split the line by whitespace
	  string buf; // Have a buffer string
	  stringstream ss(line); // Insert the string into a stream

	  vector<string> tokens; // Create vector to hold our words

	  while (ss >> buf)
		tokens.push_back(buf);
	  // our line is separated as tokens in the tokens vector
	  
	  // Set up boolean variables to control the following if statements
	  bool food = false;
	  bool warehouse = false;
	  bool start = false;
	  bool receive = false;
	  bool next = false;
	  bool request = false;
	  bool end = false;

	  for(std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it) 
		{
		  // here we check what the inital token is
		if(*it == "FoodItem" || food)
		{
			if(food)
			{
				++it;
				++it;
				++it;
				++it;
				string upcCode = *it;
				int upc = atoi(upcCode.c_str());
				++it;
				++it;
				++it;
				string shelfLife = *it;
				int shelf = atoi(shelfLife.c_str());
				
				std::string::size_type n;
				n = line.find("Name:");
				n = n + 6;
				string name = line.substr(n);
			  // create a food item.
			  item *food = new item(upc,2,name);
			  // add the new food item to our hashset
			  
			  items.insert(food);
			  break;
			}
		food = true;
		}
		else if(*it == "Warehouse" || warehouse)
		{
		  if(warehouse)
		  {
			  inventory::warehouse *house = new inventory::warehouse(line.substr(12));
			  warehouses.insert(house);
		  }
		  warehouse = true;
		}
		  else if(*it == "Start" || start)
		{
		  if(start)
		  {
			  // Get the date
			  int month = atoi( line.substr(12,2).c_str());
			  int day = atoi( line.substr(15,2).c_str());
			  int year = atoi( line.substr(18,4).c_str());

			  startDate.setDate(month, day, year);
		  }
		  start = true;
		}
		  else if(*it == "Receive" || receive)
		{
		  // call the receive function on the right warehouse
			if(receive)
			{
				// First, get the UPC of the item we are receiving.
				++it;
				string reUPC = *it;
				int receiveUPC = atoi(reUPC.c_str());
				// Then get the quantity
				++it;
				string qu = *it;
				int quantity = atoi(qu.c_str());
				// Then the the name of the receiving warehouse
				++it;
				string receivingWarehouse = *it;

				// Now find the warehouse in our set.
				inventory::warehouse *receiveWarehouse = new inventory::warehouse("temp");
				for(set<inventory::warehouse>::iterator houses = warehouses.begin(); houses != warehouses.end(); ++houses) 
				{
					inventory::warehouse tempHouse = *houses;
					if(receivingWarehouse == tempHouse.name)
					{
						*receiveWarehouse = tempHouse;
						break;
					}
				}

				// Now figure out the expiration date
				item *receiveItem = new item(0,0,"temp");
				for(set<item>::iterator itt = items.begin(); itt != items.end(); ++itt) 
				{
					item temp = *itt;
					if(receiveUPC == temp.getUPC())
					{
						*receiveItem = temp;
						break;
					}
				}
				int receiveItemShelfDays = receiveItem->getShelfLife();
				date *expiration = new date();
				for(int i = 0; i < receiveItemShelfDays; i++)
				{
					expiration->advanceDay();
				}

				// Now add the item to the warehouse

				receiveWarehouse->itemReceive(receiveUPC,quantity,*expiration);	
			}
		  receive = true;
		}
		  else if(*it == "Next" || next)
		{
		  // call the next day function
			startDate.advanceDay();
			++it;
		  next = true;
		}
		  else if(*it == "Request" || request)
		{
		  if(request)
		  {
			  string requestingUPC = *it;
			  int requestUPC = atoi(requestingUPC.c_str());

			  // Now get the quantity
			  ++it;
			  string reqQu = *it;
			  int requestedQuantity = atoi(reqQu.c_str());

			  // Now get the warehouse from where the items will be deducted.
			  ++it;
			  string reqHouse = *it;
			  inventory::warehouse *requestWarehouse = new inventory::warehouse("temp");
				for(set<inventory::warehouse>::iterator houses = warehouses.begin(); houses != warehouses.end(); ++houses) 
				{
					inventory::warehouse tempReqHouse = *houses;
					if(reqHouse == tempReqHouse.name)
					{
						*requestWarehouse = tempReqHouse;
						break;
					}
				}
			// Now attempt to deduct the items.
				requestWarehouse->itemRequest(requestUPC,requestedQuantity);
		  }
		  request = true;
		}
		  else if(*it == "End" || end)
		{
		  // Call the end function
			report(items,warehouses);
		  end = true;
		}
	}
	  
}
	  // The input file has been read.  Close it.
	  inputfile.close();
	  // Now prepare and send the report.
	  
	}
  else cout << "Unable to open the file." << endl;



  return 0;  // Exit the program.
}
/*
 * This function prints out the report
 */
void report(set<item> items, set<warehouse> warehouses){
	cout << "Report by Fernando Gomez, Seth Porter" << endl;
	cout << endl;
	cout << "Unstocked Products:" << endl;

	// Determine which products do not exist in any warehouse.
	// Cycle through all the items, and see if they are in stock.

	item *tempItem = new item(0,0,"temp");
	for(set<item>::iterator it = items.begin(); it != items.end(); ++it) 
	{
		item tempItem = *it;
		int itemUPC = tempItem.getUPC();
		// Cycle through the warehouses and see if tempItem is unstocked
		bool inStock = false;
		inventory::warehouse *tempHouse = new inventory::warehouse("temp");
		for(set<inventory::warehouse>::iterator houses = warehouses.begin(); houses != warehouses.end(); ++houses) 
		{
			tempHouse = *houses;
			if(tempHouse->isInStock(itemUPC))
			{
				inStock = true;  // If item exists in any warehouse, then it is in stock.
			}
		}
		//if item was not in stock, print it out.
		if(!inStock)
		{
			cout << itemUPC << " " << tempItem.getName() << endl;
		}
	}
	cout << endl;

	// Determine which products still exist in every warehouse.

	cout << "Fully-Stocked Products:" << endl;

	item *tempStockItem = new item(0,0,"temp");
	for(set<item>::iterator it = items.begin(); it != items.end(); ++it) 
	{
		item tempStockItem = *it;
		int StockItemUPC = tempStockItem.getUPC();
		// Cycle through the warehouses and see if tempItem is fully stocked.
		bool fullyStocked = true;
		inventory::warehouse *tempHouse = new inventory::warehouse("temp");
		for(set<inventory::warehouse>::iterator houses = warehouses.begin(); houses != warehouses.end(); ++houses) 
		{
			tempHouse = *houses;
			if(!tempHouse->isInStock(StockItemUPC))
			{
				fullyStocked = false;  // If item doesn't exist in a warehouse, then it is not fully stocked.
			}
		}
		//if item was fully stocked, print it out.
		if(fullyStocked)
		{
			cout << StockItemUPC << " " << tempStockItem.getName() << endl;
		}
	}
	cout << endl;

	// Determine the single busiest days for each warehouse.

	cout << "Busiest Days:" << endl;

	inventory::warehouse *tempBusyHouse = new inventory::warehouse("temp");
	for(set<inventory::warehouse>::iterator houses = warehouses.begin(); houses != warehouses.end(); ++houses) 
	{
		tempBusyHouse = *houses;
		inventory::date busy = tempBusyHouse->busiestDay();

		cout << tempBusyHouse->name << " " << busy.getMonth() << "/" << busy.getDay() << "/" << busy.getYear() << " "  /*  << here we need a way to get the # of transactions */ << endl;
	}

	// Report is done.
}
