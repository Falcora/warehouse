/* A 'item' keeps track of a specific food item
*
* Written by:
* Seth Porter
* January 31, 2013
*
*/

#include <iostream>
#include <string>
#include "item.h"
#include "date.h"

namespace inventory
{
	// Constructor
	warehouse::warehouse(string name)
	{
		this->name = name;
		this->busiest = NULL;
	}
	
	/*
	* Adds an item to the warehouse inventory.  Takes a UPC, a quantity, and an expiration date
	* 
	*/
   void itemReceive(int upc, int quantity, date expiration)
   {
	   // Add to inventory
   }
   
   
   /*
   * Indicates a request for an item in the warehouse.
   * Returns 0 if out of stock, or the number of items 'shipped' out.  
   * The quanitity shipped may differ from the quanitity ordered.
   */
   int itemRequest(int upc, int quantity)
   {
	   return 0;
   }
   
   
   /*
   * Simply returns true if an item is in stock, false otherwise
   * Used for reporting generation purposes.
   */
   bool isInStock(int upc)
   {
	   return true;
   }
   
   
   /*
   * Scan the inventory for items that expire on the 'current' date
   * Remove them from the inventory.
   */
   void clearExpiredForDay(date current)
   {
	   // Clear
   }
   
   
   date busiestDay()
   {
	   return this->busiest;
   }

	
	
}
		
		