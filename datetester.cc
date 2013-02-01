#include <iostream>
#include "date.h"

using namespace std;

int main()
{
	inventory::date mydate;
	mydate.setDate(1,1,2000);
	for (int i = 0; i < 500; i++)
	{
		mydate.advanceDay();
		cout << "Advance Day from: " << mydate.getMonth() << "/" << mydate.getDay() << "/" << mydate.getYear() << endl;
			
	}
}