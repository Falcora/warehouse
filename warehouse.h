/* A 'item' keeps track of a specific food item
 *
 * Written by:
 * Seth Porter
 * January 31, 2013
 *
 */
	 
 #ifndef WAREHOUSE_H
 #define WAREHOUSE_H

 #include<string>

 namespace inventory
 {
  
   class warehouse
   {
   public:	
       warehouse(string name);      // Constructor
	  
	   int itemReceive(int upc);
	   int itemRequest(int upc);
	   bool isInStock(int upc);
	   date busiestDay();
	   
   private:
	   string name;
	   
   };
}

#endif