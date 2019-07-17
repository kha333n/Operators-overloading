// Operators Overloading playing with Date class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
class Date
{
private:
	int day{};
	int month{};
	int year{};
	int verifyDay(int);
	int verifyMonth(int);
	int verifyYear(int);
public:
	Date(int, int, int);
	int setDay(int);
	int setDay(int, int);
	int setMonth(int);
	int setMonth(int, int);
	int setYear(int);
	int setYear(int, int);
	void displayDate();
	int getinput();
	Date operator +(Date);
};

int main()
{

	Date today(3, 8, 2017),d2(5,7,2019);
	today = today + d2;
	cout << "Default date." << endl;
	today.displayDate();
	while (today.getinput()==1)
	{
		cout << "Invalid input Please try again." << endl;
		today.getinput();
		system("pause");
	}
	cout << "After input." << endl;
	today.displayDate();
	int i, j, k;
	cout << "Enter Day: " << endl;
	cin >> i;
	while (today.setDay(i,1) == 1)
	{
		cout << "Enter Day: " << endl;
		cin >> i;
		today.setDay(i,1);
		system("pause");
	}
	cout << "Enter Month: " << endl;
	cin >> j;
	while (today.setMonth(j) == 1)
	{
		cout << "Enter Month: " << endl;
		cin >> j;
		today.setMonth(j);
		system("pause");
	}
	cout << "Enter year: " << endl;
	cin >> k;
	while (today.setYear(k) == 1)
	{
		cout << "Enter year: " << endl;
		cin >> k;
		today.setYear(k);;
		system("pause");
	}
	cout << "After separate inputs." << endl;
	today.displayDate();
	
}

Date::Date(int i = 1, int j = 1, int k = 2019)
{
	setDay(i);
	setMonth(j);
	setYear(k);
}
int Date::setDay(int i, int flag)
{
	if ((verifyDay(i)) != 1)
	{
		day = i;
		cout << "day entered successful." << endl;
	}
	else { return 1; }

}

int Date::setDay(int i)
{
	if ((verifyDay(i)) != 1)
	{
		day = i;
	}
	else { return 1; }

}

int Date::setMonth(int j,int flag)
{
	if ((verifyMonth(j)) != 1)
	{
		month = j;
		cout << "Month entered successful." << endl;
	}
	else { return 1; }
}

int Date::setMonth(int j)
{
	if ((verifyMonth(j)) != 1)
	{
		month = j;
	}
	else { return 1; }
}


int Date::setYear(int k, int flag)
{
	if ((verifyYear(k)) != 1)
	{
		year = k;
		cout << "Year entered successful." << endl;
	}
	else { return 1; }
	;

}
int Date::setYear(int k)
{
	if ((verifyYear(k)) != 1)
	{
		year = k;
	}
	else { return 1; }
	;

}

int Date::verifyDay(int i)
{
	if (i < 1 || i > 31)
	{
		cout << "Invalid Day. Please try again." << endl;
		return 1;
	}
}

int Date::verifyMonth(int j)
{
	if (j < 1 || j > 12)
	{
		cout << "Invalid Month. Please try again." << endl;
		return 1;
	}
}


int Date::verifyYear(int k)

{
	if (k < 1800 || k > 2050)
	{
		cout << "Invalid Year. Please try again." << endl;
		return 1;
	}
}

void Date::displayDate()
{
	cout << day << "-" << month << "-" << year << endl;
}

int Date::getinput()
{
	string i, j, k;
	cout << "Enter date: " << endl << "Formate for input: 30/12/2019" << endl;
	getline(cin, i, '/');
	getline(cin, j, '/');
	cin >> k;
	if (setDay(atoi(i.c_str()))==1)
	{
		return 1;
	}
	if (setMonth(atoi(j.c_str()))==1)
	{
		return 1;
	}
	if (setYear(atoi(k.c_str()))==1)
	{
		return 1;
	}
}

Date Date::operator +(Date d)
{
	int r[12];
	r[0] = 31; r[2] = 31; r[3] = 30; r[4] = 31; r[5] = 30; r[6] = 31; r[7] = 31; r[8] = 30;
	r[9] = 31; r[10] = 30; r[11] = 31;
	if ( (year%4) == 0 )
	{
		r[2] = 29;
	}
	else
	{
		r[2] = 28;
	}
	
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
