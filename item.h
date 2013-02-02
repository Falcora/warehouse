/* A 'item' keeps track of a specific food item
 *
 * Written by:
 * Seth Porter
 * January 31, 2013
 *
 */
	 
 #ifndef ITEM_H
 #define ITEM_H

 #include<string>
 #include "date.h"

 namespace inventory
 {
	 class date;
  
   class item
   {
   public:	
       item(int upc, int shelf, std::string name);      // Constructor
	   item(int upc, date expiration, int quantity);
	   
	  
	   int getUPC();
	   int getShelfLife();
	   std::string getName();
	   date getExpiration();
	   void setExpiration(date expire);
	   int getQuantity();
	   void setQuantity(int quantity);
	   
   private:
	   int upc;
	   int shelf;
	   std::string name;
	   date expiration;
	   int quantity;
   };
}

#endif