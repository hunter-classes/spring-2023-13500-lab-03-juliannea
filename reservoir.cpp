#include <iostream>

#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include "reservoir.h"
#include <limits.h>

//get east storage
double get_east_storage(std::string date)
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
    std::string edate; //variable for date 
    std::string eastSt; //variable for east storage 
    double storage;

    // this stores each line in the file into the variable by the order it's in 
    while(fin >> edate >> eastSt) 
    {
        //checking when the dat is equal to a date in data fiel 
        if(date == edate)
        {
            //storing the east storage 
            storage = std::stod(eastSt); //converts string into double and stores in double variable
        }

        //skips to the end of line and ignores the remaining columns  
        fin.ignore(INT_MAX, '\n'); 
        
    }
    //cosing file
    fin.close();
    return storage;
}

//returns the minimum 
double get_min_east()
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
    std::string edate; //variable for date 
    std::string eastSt; //variable for east storage 

    //sets it to the max number 
    double m= INT_MAX;
    //sets variable to store in 
    double number;

    while(fin >> edate >> eastSt) // this stores each line in the file into the variable by the order it's in 
    {
        
        number = std::stod(eastSt); 
        
        if(number < m)
        {
            m = number;
        }
        fin.ignore(INT_MAX, '\n'); //skips to the end of line and ignores the remaining columns  

    }
    fin.close(); 
    return m;
}

double get_max_east()
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
    std::string edate; //variable for date 
    std::string eastSt; //variable for east storage 

    //set variables to get max 
    double nm = INT_MIN; //sets the first number to the smallest 
    double maxn;

    //reading file and storing to fin variable line by line 
    while(fin >> edate>>eastSt)
    {
        //getting the eastst values 
        maxn = std::stod(eastSt); 

        //determining the max 
        if(maxn > nm)
        {
            nm = maxn;
        }

        //skipping to end of line & ignoring remaining columns 
        fin.ignore(INT_MAX, '\n');
    }
    //closing file 
    fin.close(); 
    return nm;
}

std::string compare_basins(std::string date)
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
    std::string edate; //variable for date 
    std::string eastSt; //variable for east storage 
    std::string eastEl; //variable for east elevation
    std::string westSt; //variablefor west storage

    //set variables for east storage and west storage based on date 
    double east_storage;
    double west_storage;
    std::string greatest;

    //reading file and storing to fin variable line by line 

    while(fin>>edate>>eastSt>>eastEl>>westSt)
    {
        //collecting east and west storage values based on date given 
        if(date == edate)
        {
            east_storage = std::stod(eastSt); 
            west_storage = std::stod(westSt);

            //determining which is greatest 
            if(east_storage > west_storage)
            {
                greatest = "East";
            }
            else if(west_storage >east_storage)
            {
                greatest = "West";
            }
            else
            {
                greatest = "Equal";
            }

        }
        //skipping to end of line, ignoring remaining columns
        fin.ignore(INT_MAX,'\n');
    }
    //close file 
    fin.close();
    return greatest;

}
