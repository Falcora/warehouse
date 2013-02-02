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
#include "warehouse.h"
#include <set>

namespace inventory
{
	// Constructor
	warehouse::warehouse(std::string name)
	{
		this->name = name;
		this->busiest = date();
		this->inventory = NULL;
		this->transactionDayCount = 0;
	}
	
	/*
	* Adds an item to the warehouse inventory.  Takes a UPC, a quantity, and an expiration date
	* 
	*/
   void warehouse::itemReceive(int upc, int quantity, date expiration)
   {
	   this->transactionDayCount += 1;
	   item rec_item = item(upc, expiration, quantity);
	   this->inventory.insert(rec_item);
   }
   
   
   /*
   * Indicates a request for an item in the warehouse.
   * Returns 0 if out of stock, or the number of items 'shipped' out.  
   * The quanitity shipped may differ from the quanitity ordered.
   */
   int warehouse::itemRequest(int upc, int quantity)
   {   
	   int shipped = 0;
	   
	   if (inventory == NULL)
		   return 0;
	   
	   std::set<item> *ourinventory;
	   ourinventory = this->inventory;
	   std::set<item>::iterator it;
	   for (it=ourinventory.begin(); it!=ourinventory.end(); ++it)
	   {
		   if (it.getUPC() == upc)
		   {
			   // Found item.  (is this the oldest?  (Should be because it starts at beginning)
			   if (it.getQuantity >= quantity)
			   {
				   it.setQuantity(it.getQuantity - quantity);
				   shipped = quantity;
				   transactionDayCount++;
				   return shipped;
			   }
			   else if (it.getQuantity > 0)
			   {
				   int available = it.getQuantity;
			   	   it.setQuantity(0);
				   shipped = available;
				   transactionDayCount++;
				   return shipped;
			   }
			
		   }
	   }
	   return 0;
   }
   
   
   /*
   * Simply returns true if an item is in stock, false otherwise
   * Used for reporting generation purposes.
   */
   bool warehouse::isInStock(int upc)
   {
	   std::set<item> *ourinventory;
	   ourinventory = this->inventory;
	   std::set<item>::iterator it;
	   for (it=ourinventory.begin(); it!=ourinventory.end(); ++it)
	   {
		   if (it.getUPC() == upc)
		   {
			   // Found item.  
			   if (it.getQuantity > 0)
			   {
				   return true;
			   }
			
		   }
	   }
	   
	   
	   return false;
   }
   
   
   /*
   * Scan the inventory for items that expire on the 'current' date
   * Remove them from the inventory.
   */
   void warehouse::clearExpiredForDay(date current)
   {
	   ourinventory* = this->inventory;
	   std::set<item>::iterator it;
	   date expiration;
	   for (it=ourinventory.begin(); it!=ourinventory.end(); ++it)
	   {
		   expiration = it.getExpiration();
		   if (expiration.getMonth() == current.getMonth())
		   {
			   if (expiration.getDay() == current.getDay())
			   {
				   if (expiration.getYear() == current.getYear())
				   {
					   ourinventory.erase(it);
				   }
			   }
		   }
	   }
	   
	   // Reset busiest count, update if neccessary
	   if (busiestCount < transactionDayCount)
	   {
		   busiestCount = transactionDayCount;
		   busiest = current;
	   }
	   
   }
   
   
   date warehouse::busiestDay()
   {
	   return this->busiest;
   }

	
	
}
		
		