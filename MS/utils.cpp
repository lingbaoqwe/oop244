/* Citation and Sources...
Final Project Milestone 1
Module: utils
Filename: utils.cpp
Version 1.0
Author	Bo Wen Hou
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/20 Preliminary release
2020/3/27  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds
{
	bool debug = false;// made global in utils.h
	int getTime()
	{
		int mins = -1;
		if (debug)
		{
			Time t(0);
			cout << "Enter current time: ";
			do
			{
				cin.clear();
				cin >> t;   // needs extraction operator overloaded for Time
				if (!cin)
				{
					cout << "Invlid time, try agian (HH:MM): ";
					cin.clear();
				}
				else
				{
					mins = int(t);
				}
				cin.ignore(1000, '\n');
			} while (mins < 0);
		}
		else
		{
			time_t t = time(NULL);
			tm lt = *localtime(&t);
			mins = lt.tm_hour * 60 + lt.tm_min;
		}
		return mins;
	}
	int getInt(const char* prompt)
	{
		int x = -1;
		bool flag = false;
		if (prompt)
		{
			cout << prompt;
		}
		cin >> x;
		while (flag == false)
		{
			if (cin.fail())
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(2000, '\n');
				cin >> x;
			}
			else
			{
				while (cin.get() != '\n')
				{
					cin.clear();
					cin.ignore(2000, '\n');
					cout << "Enter only an integer, try again: ";
					cin >> x;
				}
				flag = true;
			}
		}
		return x;
	}
	int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
	{
		int x = -1;
		bool flag = false;
		if (prompt)
		{
			cout << prompt;
		}
		cin >> x;
		while (flag == false)
		{
			if (cin.fail())
			{
				cout << "Bad integer value, try again: ";
				cin.clear();
				cin.ignore(2000, '\n');
				cin >> x;
			}
			else
			{
				while (cin.get() != '\n')
				{
					cin.clear();
					cin.ignore(2000, '\n');
					cout << "Enter only an integer, try again: ";
					cin >> x;
				}
			}
			if (!(x >= min && x <= max))
			{
				if (errorMessage && showRangeAtError)
				{
					cout << errorMessage << "[" << min << " <= value <= " << max << "]: ";
				}
				else if (errorMessage)
				{
					cout << errorMessage;
				}
				cin.clear();
				cin >> x;
			}
			else
			{
				flag = true;
			}
		}
		return x;
	}
	char* getcstr(const char* prompt, std::istream& istr, char delimiter)
	{
		char* mm = nullptr;
		if (prompt!=nullptr)
		{
			cout << prompt;
		}
		string temp;
		if (getline(istr, temp, delimiter))
		{
			mm = new char[strlen(temp.c_str()) + 1];
			strcpy(mm, temp.c_str());
		}
		return mm;
	}
}