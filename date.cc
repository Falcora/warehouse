/* A 'date' keeps track of the current day, and allows for it to be advanced
*
* Written by:
* Seth Porter
* January 31, 2013
*
*/

#include <iostream>
#include <string>

namespace inventory
{
	date::date()
	{
		this->month = 1;
		this->day = 1;
		this->year = 2001;
		this->set = FALSE;
	}
	
	void date::setDate(std::string mm, std::string dd, std::string yyyy)
	{
		this->month = mm;
		this->day = dd;
		this->year = yyyy;
		this->set = TRUE;
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
				isleap = TRUE;
			else if (this->year % 100 == 0)
				isleap = FALSE;
			else if (this->year % 4 == 0)
				isleap = TRUE;
			else
				isleap = FALSE;
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
	
	int getMonth()
	{
   		return this->month;
	}
   
	int getDay()
	{
   		return this->day;
	}
   
	int getYear()
	{
   		return this->year;
	}
}
