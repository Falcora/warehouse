/* A 'item' keeps track of a specific food item
 *
 * Written by:
 * Seth Porter
 * January 31, 2013
 *
 */
	 
 #ifndef WAREHOUSE_H
 #define WAREHOUSE_H

#include <string>
#include "item.h"

namespace inventory
{
	class date;
  
	class warehouse
	{
	public:	
	   warehouse(string name);      // Constructor
	  
	   void itemReceive(int upc, int quantity, date expiration);
	   int itemRequest(int upc, int quantity);
	   bool isInStock(int upc);
	   void clearExpiredForDay(date current);
	   date busiestDay();
	   string name;
	   std::set<item> inventory;
	   
	private:
	   date busiest;
	   int transactionDayCount;
	   int busiestCount;
	};
}

#endif