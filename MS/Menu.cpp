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
