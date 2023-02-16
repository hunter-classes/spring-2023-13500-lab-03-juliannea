#include <iostream>

#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include "reservoir.h"

#define MAX_LINES 365 //max amount of lines we expect in a file 

void reverse_order(std::string date1, std::string date2)
{
    //reading the data file 
   std::ifstream fin("Current_Reservoir_Levels.tsv");
   if(fin.fail())
   {
    std::cerr << "File cannott be opened for reading." <<std::endl;
    exit(1);
   }
    //removing the first line 
    std::string junk; //creates string variable 
    getline(fin, junk); //reads one line from file and stores it in junk 
    
    //setting variables
    std::string edate;
    std::string eastSt;
    std::string eastEl;
    std::string westSt;
    std::string westEl;
   
   //defining arrays
    
   std::string date[MAX_LINES];
   std::string el[MAX_LINES];

   //initalizing line number in array
   int line = 0;
   
    //reading file and storing to fin variable line by line 
    while(fin>>edate>>eastSt>>eastEl>>westSt>>westEl)
    {
        //skiping to end of line and ignoring remaining columns 
        fin.ignore(INT_MAX, '\n');

        //storing date and west elevation values to 
        if(date1 <= edate && edate <= date2)
        {
            date[line]=edate;
            el[line]=westEl;
            line++;

        }
    }
    for(int i = line - 1; i >= 0; i--)
	{
		std::cout << date[i] << " " << el[i] << " ft" << std::endl;
	}
    //closing data file 
    fin.close();
}