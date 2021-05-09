/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	Bo Wen Hou
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/23  Preliminary release
2020/?/?  Debugged DMA
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
#include "IOAble.h"
using namespace std;
namespace sdds
{
	std::ostream& operator<<(std::ostream& os, const IOAble& D)
	{
		D.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, IOAble& D)
	{
		D.read(is);
		return is;
	}
}