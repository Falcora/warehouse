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
  
   class date
   {
   public:	
       date();      // Constructor
	   
	   void advanceDay();
	   void setDate(int mm, int dd, int yyyy);
	   int getMonth();
	   int getDay();
	   int getYear();
	   
    date & operator= (date & rhs);  // Modifies this object
	   
   private:
	   int month;
	   int day;
	   int year;
	   bool set;
   };
}

#endif