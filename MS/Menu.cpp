/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"
#include "utils.h"
#include <cstring>
using namespace std;
namespace sdds
{
	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}
	Menu::~Menu()
	{
		delete[]m_text;
	}
	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0,m_noOfSel,"> ","Invalid option ");
		return Selection;
	}
	Menu::Menu(const Menu& fii)
	{
		m_text = nullptr;
		m_noOfSel = 0;
		if (fii.m_text != nullptr)
		{
			m_text = new char[strlen(fii.m_text) + 1];
			strcpy(m_text, fii.m_text);
			m_noOfSel = fii.m_noOfSel;
		}
	}
	void Menu::display()const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}
}