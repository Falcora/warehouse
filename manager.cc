/* This class reads an input file and creates objects for items and warehouses.
 * Also, it calls functions on warehouses as stated by the input file.
 *
 */

#include "manager.h"

int main(int argc, char* argv[]){
  if(argc >2 || argc < 2)
    {
      cout << "Please include a filename." << endl;
      return 1;
    }
  string filename = args[1];
  ifstream inputfile(filename);
  string line;
  if(inputfile.is_open())
    {
      while(inputfile.good())
	{
	  getline(inputfile,line, ' ');
	  // The current line is held in 'line'
	  // This is where we read through each line
	  // and call the appropriate functions.
	  
	  // First split the line by whitespace
	  string buf; // Have a buffer string
	  stringstream ss(line); // Insert the string into a stream

	  vector<string> tokens; // Create vector to hold our words

	  while (ss >> buf)
	    tokens.push_back(buf);
	  // our line is separated as tokens in the tokens vector
	  
	  // Set up boolean variables to control the following if statements
	  bool food = false;
	  bool warehouse = false;
	  bool start = false;
	  bool receive = false;
	  bool next = false;
	  bool request = false;
	  bool end = false;

	  for(std::vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it) 
	    {
	      // here we check what the inital token is
	      if(*it == "FoodItem" || food)
		{
		  if(food)
		    {
		      // create a food item.
		      item food = new item(line.substr(21,10);
		    }
		  food = true;
		}
	      else if(*it == "Warehouse" || warehouse)
		{
		  // Create warehouse


		  warehouse = true;
		}
	      else if(*it == "Start" || start)
		{
		  // Set start date

		  start = true;
		}
	      else if(*it == "Receive" || receive)
		{
		  // call the receive function on the right warehouse

		  receive = true;
		}
	      else if(*it == "Next" || next)
		{
		  // call the next day function

		  next = true;
		}
	      else if(*it == "Request" || request)
		{
		  // call the request function

		  request = true;
		}
	      else if(*it == "End" || end)
		{
		  // Call the end function

		  end = true;
		}
	    }
	  
	}
      // The input file has been read.  Close it.
      inputfile.close();
      // Now prepare and send the report.
      
    }
  else cout << "Unable to open the file." << endl;



  return 0;
}
