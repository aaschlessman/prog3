// Program 3
// Description: product program
// Programmer: Aaron Schlessman
// Class: CS 2020 - 9:30 AM, Spring 2018

#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

using namespace std;

/*~~~~~~~~ STRUCTURES ~~~~~~~~~*/
struct division
{
	string name;
	double q1sales;
	double q2sales;
	double q3sales;
	double q4sales;
};

struct corporation
{
	double q1totals;
	double q2totals;
	double q3totals;
	double q4totals;
	int num_of_divisions;
};

/*~~~~~~~ PROTOTYPES ~~~~~~~~*/



/*~~~~~~~ CONSTANTS ~~~~~~~*/



/*~~~~~~~ MAIN ~~~~~~~~*/
int main()
{
	ifstream infile;
	infile.open("prog3.txt");

	if (infile)
	{
		while (!infile.eof)
		{

		}
	}
	else
	{
		cout << "Invalid file.\n";
	}

	system("Pause");
	return 0;
}

// Function: getDivision
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 


// Function: printDivision
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 


// Function: addDivision
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 


// Function: printCorpSummary
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: 

