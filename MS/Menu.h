/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_menu_H_
#define SDDS_menu_H_
#include <iostream>
namespace sdds
{
	class Menu
	{
		char* m_text; // holds the menu content dynamically
		int m_noOfSel;  // holds the number of options displayed in menu content
		void display()const;
	public:
		Menu(const char* MenuContent, int NoOfSelections);
		virtual ~Menu();
		int& operator>>(int& Selection);
		// add safe copying logic
		//copy constructor
		Menu(const Menu& fii);
		Menu& operator = (const Menu& fii)=delete;
	};
}
#endif
