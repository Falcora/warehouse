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

namespace inventory
{
	item::item(int upc, int shelf, string name)
	{
		this->upc = upc;
		this->shelf = shelf;
		this->name = name;
	}
	
	
   int item::getUPC()
   {
	   return this->upc;
   }
   
   
   int item::getShelfLife()
   {
	   return this->shelf;
   }
   
   
   string item::getName()
   {
	   return this->name;
   }
	
	
}
		
		