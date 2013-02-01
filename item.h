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

 namespace inventory
 {
  
   class item
   {
   public:	
       item(int upc, int shelf, string name);      // Constructor
	  
	   int getUPC();
	   int getShelfLife();
	   string getName();
	   
   private:
	   int upc;
	   int shelf;
	   string name;
   };
}

#endif