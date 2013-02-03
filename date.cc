/* A 'date' keeps track of the current day, and allows for it to be advanced
*
* Written by:
* Seth Porter
* January 31, 2013
*
*/

#include <iostream>
#include <string>
#include "date.h"

namespace inventory
{
	date::date()
	{
		this->month = 1;
		this->day = 1;
		this->year = 2001;
		this->set = false;
	}
	
	void date::setDate(int mm, int dd, int yyyy)
	{
		this->month = mm;
		this->day = dd;
		this->year = yyyy;
		this->set = true;
	}
	
	void date::advanceDay()
	{
		
		
		
		// JAN MAR MAY JUL AUG OCT
		if (this->month == 1 || this->month == 3 || this->month == 5 || 
			this->month == 7 || this->month == 8 || this->month == 10)
		{
			if(this->day < 31)
			{
				this->day = this->day + 1;
				return;
			}
			else if (this->day == 31)
			{
				this->day = 1;
				this->month = this->month + 1;
				return;
			}
		}
		
		
		// APR JUN SEP NOV
		if (this->month == 4 || this->month == 6 || this->month == 9 || this->month == 11)
		{
			if(this->day < 30)
			{
				this->day = this->day + 1;
				return;
			}
			else if (this->day == 30)
			{
				this->day = 1;
				this->month = this->month + 1;
				return;
			}
		}
		
		// FEB
		if (this->month == 2)
		{
			// Check leap year (Pseudo algorithm from wikipedia)
			bool isleap;
			if (this->year % 400 == 0)
				isleap = true;
			else if (this->year % 100 == 0)
				isleap = false;
			else if (this->year % 4 == 0)
				isleap = true;
			else
				isleap = false;
			// END leap year check
			
			
			if (isleap)	// Perform Leap Year
			{
				if(this->day < 29)
				{
					this->day = this->day + 1;
					return;
				}
				else if (this->day == 29)
				{
					this->day = 1;
					this->month = this->month + 1;
					return;
				}
			}
			else		// Perform standard year
			{
				if(this->day < 28)
				{
					this->day = this->day + 1;
					return;
				}
				else if (this->day == 28)
				{
					this->day = 1;
					this->month = this->month + 1;
					return;
				}
			}
		}
		
		// DEC
		if (this->month == 12)
		{
			if(this->day < 31)
			{
				this->day = this->day + 1;
				return;
			}
			else if (this->day == 31)
			{
				this->day = 1;
				this->month = 1;
				this->year = this->year + 1;
				return;
			}
		}
		
		
		
		
		
	}
	
	//    	date & date::operator= (date & rhs)
	// {
	// 	if (this == &rhs)  // Compare addresses (not object contents)
	// 		return *this;
	// 	
	// 	this->month = rhs.getMonth();
	// 	this->day = rhs.getDay();
	// 	this->year = rhs.getYear();
	// 	this->set = true;
	// 	
	// 	
	// 	return *this;
	// }
	
	int date::getMonth()
	{
   		return this->month;
	}
   
	int date::getDay()
	{
   		return this->day;
	}
   
	int date::getYear()
	{
   		return this->year;
	}
}
