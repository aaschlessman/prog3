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
void getDivision(division*, ifstream &);
void printDivision(division *, corporation *);
void addDivision(division *, corporation *);
void printCorpSummary(corporation *);

/*~~~~~~~ MAIN ~~~~~~~~*/
int main()
{
	//new new
	corporation* p2corp = nullptr;
	p2corp = new corporation;
	p2corp->q1totals = 0;
	p2corp->q2totals = 0;
	p2corp->q3totals = 0;
	p2corp->q4totals = 0;
	p2corp->num_of_divisions = 0;

	division* p2div = nullptr;
	p2div = new division;
	p2div->q1sales = 0;
	p2div->q2sales = 0;
	p2div->q3sales = 0;
	p2div->q4sales = 0;


	//infiles
	ifstream infile;
	infile.open("prog3.txt");

	if (infile)
	{
		while (!infile.eof())
		{
			getDivision(p2div, infile);
			printDivision(p2div, p2corp);
			addDivision(p2div, p2corp);
			infile.ignore();
		}
	}
	else
	{
		cout << "Invalid file.\n";
	}
	cout << endl;
	printCorpSummary(p2corp);

	//outfiles
	infile.close();

	//deallocation
	delete p2corp;
	p2corp = nullptr;
	delete p2div;
	p2div = nullptr;

	system("Pause");
	return 0;
}

// Function: getDivision
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: void
void getDivision(division *p2div, ifstream &infile)
{
	getline(infile, p2div->name);
	infile >> p2div->q1sales;
	infile >> p2div->q2sales;
	infile >> p2div->q3sales;
	infile >> p2div->q4sales;
}


// Function: printDivision
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: void
void printDivision(division *p2div, corporation *p2corp)
{
	cout << setprecision(2) << fixed;
	if (p2corp->num_of_divisions == 0)
	{
		cout << setw(25) << left << "Division" << setw(15) << left << "Q1" << setw(15) << left << "Q2" <<
			setw(15) << left << "Q3" << setw(15) << left << "Q4" << endl;
	}

	cout << setw(20) << left << p2div->name << setw(15) << p2div->q1sales << setw(15) <<
		p2div->q2sales << setw(15) << p2div->q3sales << setw(15) << p2div->q4sales << endl;
}


// Function: addDivision
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: void
void addDivision(division *p2div, corporation *p2corp)
{
	p2corp->q1totals += p2div->q1sales;
	p2corp->q2totals += p2div->q2sales;
	p2corp->q3totals += p2div->q3sales;
	p2corp->q4totals += p2div->q4sales;
	p2corp->num_of_divisions++;
}


// Function: printCorpSummary
// Description: 
// Programmer: Aaron Schlessman
// Class: CS 2020, Spring 2018
// Parameters:	
// Returns: void
void printCorpSummary(corporation *p2corp)
{
	double q1avg = 0;
	double q2avg = 0;
	double q3avg = 0;
	double q4avg = 0;
	double totals = 0;
	double qtrhigh = 0;
	double qtrlow = p2corp->q1totals;

	q1avg = (p2corp->q1totals / p2corp->num_of_divisions);
	q2avg = (p2corp->q2totals / p2corp->num_of_divisions);
	q3avg = (p2corp->q3totals / p2corp->num_of_divisions);
	q4avg = (p2corp->q4totals / p2corp->num_of_divisions);
	totals = (p2corp->q1totals + p2corp->q2totals + p2corp->q3totals + p2corp->q4totals);

	if (p2corp->q1totals > qtrhigh)
		qtrhigh = p2corp->q1totals;
	if (p2corp->q2totals > qtrhigh)
		qtrhigh = p2corp->q2totals;
	if (p2corp->q3totals > qtrhigh)
		qtrhigh = p2corp->q3totals;
	if (p2corp->q4totals > qtrhigh)
		qtrhigh = p2corp->q4totals;

	if (p2corp->q1totals < qtrlow)
		qtrlow = p2corp->q1totals;
	if (p2corp->q2totals < qtrlow)
		qtrlow = p2corp->q2totals;
	if (p2corp->q3totals < qtrlow)
		qtrlow = p2corp->q3totals;
	if (p2corp->q4totals < qtrlow)
		qtrlow = p2corp->q4totals;

	cout << setw(20) << left << "Corp Totals:" << setw(15) << p2corp->q1totals << setw(15) << p2corp->q2totals
		<< setw(15) << p2corp->q3totals << setw(15) << p2corp->q4totals << endl;
	cout << setw(20) << left << "Avg Qtr Sales:" << setw(15) << q1avg << setw(15) << q2avg << setw(15)
		<< q3avg << setw(15) << q4avg << endl;

	cout << setw(20) << left << "Total Sales:" << totals << endl;
	cout << setw(20) << left << "Corp High Qtr:" << qtrhigh << endl;
	cout << setw(20) << left << "Corp Low Qtr:" << qtrlow << endl << endl;
}
