#include <iostream>
#include <string>
#include <vector>

using namespace std;

int myAdder(string);
vector<string> split(const string&, char);

void main() 
{
	string input;
	cout << "Welcome to the calculator" << endl;
	cout << "> ";
	while (input != "exit")
	{
		getline(cin, input);
		cout << input << endl;
		cout << myAdder(input) << ">";
	}
}

int myAdder(string input) 
{
	double answer;
	vector<string> splitString;
	splitString = split(input, '+');
	return splitString.size();//returns an int of the size of the string vector (arraylist in Java)
}

vector<string> split(const string& strValue, char separator) //fucntion to split a string on a given char
{
    vector<string> vecstrResult;
    int startpos=0;
    int endpos=0;

    endpos = strValue.find_first_of(separator, startpos);
    while (endpos != -1)
    {       
        vecstrResult.push_back(strValue.substr(startpos, endpos-startpos)); // add to vector
        startpos = endpos+1; //jump past sep
        endpos = strValue.find_first_of(separator, startpos); // find next
        if(endpos==-1)
        {
            //lastone, so no 2nd param required to go to end of string
            vecstrResult.push_back(strValue.substr(startpos));
        }
    }
	//TODO add a case for returning the full string if the split char does not exist.

    return vecstrResult;
}