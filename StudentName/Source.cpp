#include <iostream> // Preprocessor directive for cout object 
#include <string> // Preprocessor directive for reading string of characters
#include <fstream> // Preprocessor directive for file
#include <iomanip> // Preprocessor directive to manage format of output

using namespace std;
			// Global variables
ifstream inname, ingrade; 
int const row = 5; // num of rows
int const col = 4; // num of cols

//=========== Definition of Read function ============
void read_data(string studentsName[row], double studentsGrade[row][col])
{
	inname.open("Names.txt");
	ingrade.open("Grades.txt");

	int r;  // loop control variable 
	int c; // loop control variable for col
			// loop to read all 5 or as many names and grade you have in your files 

	for (r = 0; r < row; r++)
	{
		getline(inname, studentsName[r]); // Reads name and stores them in array of studentsName array
		for(c=0; c<col; c++)
		ingrade >> studentsGrade[r][c];	  // Reads grades and stores them in array of studentsGrade array
	}


}
//=========== Definition of Display function ============
void display_data(string studentsName[row], double studentsGrade[row][col])
{
	inname.open("Names.txt");
	ingrade.open("Grades.txt");
	int r;  // loop control variable 
	int c;
			// loop to read all 5 or as many names and grade you have in your files 
	cout << fixed << showpoint << setprecision(2);
	for(r = 0; r < row; r++)
		{
			cout<<left<< setw(20)<< studentsName[r]; // Reads name and stores them in array of studentsName array
			for (c = 0; c < col; c++)
				cout << right << setw(7) << studentsGrade[r][c];
			    cout<< endl;	  // Reads grades and stores them in array of studentsGrade array
		}
}
//=========== Main program ===========================
int main()
{
	double grade[row][col] = { {0}, {0} }; // Declaration of arguments
	string name[row] = {};

	read_data(name, grade); // calling read function , passing proper arguments
	display_data(name, grade);          
	
	inname.close();
	ingrade.close();

	system("pause");
	return 0;
}