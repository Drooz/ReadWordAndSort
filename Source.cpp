#include <iostream>
#include "LinkedList.h"
#include <fstream>
using namespace std;

int main() {
	/* First we create a holder of linkedlist obj to hold the words */
	LinkedList holder; 
	/* Char will hold the file name */
	char filename[50];
	/* ifstream object which will hold the file source or text */
	ifstream obj;
	/* Ask for the value*/
	cout << "Write the file name : " << endl;
	/* Assign it to the char object */
	cin >> filename;
	/* Pass it as parameter for the open function */
	obj.open(filename);
	/*Check if it is open ! or otherwise we terminate the program */
	if (!obj.is_open())
	{
		cout << "File name error !!!" << endl;
		return 0;
	}
	/* Which will hold the word */
	string word;
	/* While we are not at the end of the file */
	while (obj.good())
	{
		/* Assign a word */
		obj >> word;
		/* Removing the special char using ASCII CODES */
		while (word.back() >= 33 && word.back() <= 47 || word.back() >= 91 && word.back() <= 96
			|| word.back() >= 123 && word.back() <= 126 || word.back() >= 58 && word.back() <= 63)
		{word.pop_back();}

		while (word.front() >= 33 && word.front() <= 47 || word.front() >= 91 && word.front() <= 96
			|| word.front() >= 123 && word.front() <= 126 || word.front() >= 58 && word.front() <= 63)
		{
			word.erase(0, 1);
			
		}
		/* Add the word  */
		holder.add(word);
	}
	/* Ask to sort */
	holder.sort();
	cout << "*****" << endl; 
	/* Print */
	holder.print();

	return 0;}