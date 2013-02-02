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
	item::item(int upc, int shelf, std::string name)
	{
		this->upc = upc;
		this->shelf = shelf;
		this->name = name;
		this->expiration = NULL;
		this->quantity = NULL;
	}
	
	item::item(int upc, date expiration, int quantity)
	{
		this->upc = upc;
		this->shelf = NULL;
		this->name = NULL;
		this->expiration = expiration;
		this->quantity = quantity;
	}
	
   void item::setExpiration(date expire)
   {
	   this->expiration = expire;
   }
   
   date item::getExpiration()
   {
	   return this->expiration;
   }
   
   int item::getQuantity()
   {
	   return this->quantity;
   }
   
   void item::setQuantity(int quantity)
   {
	   this->quantity = quantity;
   }
	
   int item::item::getUPC()
   {
	   return this->upc;
   }
   
   
   int item::item::getShelfLife()
   {
	   return this->shelf;
   }
   
   
   std::string item::getName()
   {
	   return this->name;
   }
	
	
}
		
		