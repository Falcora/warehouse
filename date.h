/* A 'date' keeps track of the current day, and allows for it to be advanced
 *
 * Written by:
 * Seth Porter
 * January 31, 2013
 *
 */
	 
 #ifndef DATE_H
 #define DATE_H

 #include<string>

 namespace inventory
 {
   // class node;  // A forward declaration of the class.  We can now
   //                 // create pointer variables involving the node class.
  
   class date
   {
   public:	
       date();      // Constructor
       ~date();     // Destructor
	   
	   void advanceDay();
	   void setDate(std::string mm, std::string dd, std::string yyyy);
	   int getMonth();
	   int getDay();
	   int getYear();
	   
   private:
	   int month;
	   int day;
	   int year;
	   bool set;
   };
}

#endif