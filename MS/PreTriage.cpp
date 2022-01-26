#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<cstring>
#include "PreTriage.h"
#include "CovidPatient.h"
#include"TriagePatient.h"
#include"Ticket.h" 
using namespace std;
namespace sdds
{
	PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
	{
		if (dataFilename != nullptr)
		{
			m_dataFilename = new char[strlen(dataFilename) + 1];
			strcpy(m_dataFilename, dataFilename);
		}
		m_lineupSize = 0;
		load();
	}

	PreTriage::~PreTriage()
	{
		if (m_dataFilename != nullptr)
		{
			ofstream fout(m_dataFilename);
			if (fout)
			{
				fout << m_averCovidWait << ',' << m_averTriageWait << endl;
				for (int i = 0; i < m_lineupSize; i++)
				{
					m_lineup[i]->fileIO(true);
					fout << *m_lineup[i] << endl;
				}
			}
		}
		cout << "Saving Average Wait Times," << endl << "   COVID Test: " << m_averCovidWait << endl << "   Triage: " << m_averTriageWait << endl << "Saving m_lineup..." << endl;
		for (int i = 0; i < m_lineupSize; i++)
		{
			m_lineup[i]->fileIO(true);
			cout << i + 1 << "- " << *m_lineup[i] << endl;
		}
		for (int i = 0; i < m_lineupSize; i++)
		{
			delete m_lineup[i];
		}
		delete[]m_dataFilename;
		cout << "done!" << endl;
	}

	const Time PreTriage::getWaitTime(const Patient& p) const
	{
		unsigned int time = 0;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (*m_lineup[i] == p)
			{
				if (p == 'C')
				{
					time += (unsigned int)m_averCovidWait;
				}
				else if (p == 'T')
				{
					time += (unsigned int)m_averTriageWait;
				}
			}
		}
		return Time(time);
	}

	void PreTriage::setAverageWaitTime(const Patient& p)
	{
		unsigned int CT = 0, PTT = 0, AWT = 0, PTN = 0;
		if (p == 'C')
		{
			AWT = m_averCovidWait;
		}
		else if (p == 'T')
		{
			AWT = m_averTriageWait;
		}
		CT = Time().setToNow();
		PTT = Time(p);
		PTN = p.number();
		AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
		for (int i = 0; i < m_lineupSize; i++)
		{
			if (*m_lineup[i] == p)
			{
				if (p == 'C')
				{
					m_averCovidWait = AWT;
				}
				else if (p == 'T')
				{
					m_averTriageWait = AWT;
				}
			}
		}
	}

	void PreTriage::removePatientFromLineup(int index)
	{
		removeDynamicElement(m_lineup, index, m_lineupSize);
	}

	int PreTriage::indexOfFirstInLine(char type) const
	{
		int index = -1;
		for (int i = 0; index == -1 && i < m_lineupSize; i++)
		{
			if (*m_lineup[i] == type)
			{
				index = i;
			}
		}
		return index;
	}

	void PreTriage::load()
	{
		cout << "Loading data..." << endl;
		if (m_dataFilename != nullptr)
		{
			ifstream fin(m_dataFilename);
			if (fin.is_open() && fin.peek() != EOF)
			{
				fin >> m_averCovidWait;
				fin.get();
				fin >> m_averTriageWait;
				fin.get();
				Patient* ppointer = nullptr;
				for (int i = 0; fin && i < maxNoOfPatients && fin.peek() != EOF; i++)
				{
					char type = fin.get();
					if (type == 'C')
					{
						ppointer = new CovidPatient();
					}
					else if (type == 'T')
					{
						ppointer = new TriagePatient();
					}
					fin.get();
					if (ppointer != nullptr)
					{
						ppointer->fileIO(true); //file
						fin >> *ppointer;
						ppointer->fileIO(false);
						m_lineup[m_lineupSize] = ppointer;
						m_lineupSize++; //size up
					}
				}
				if (fin.peek() != EOF)
				{
					cout << "Warning: number of records exceeded " << maxNoOfPatients;
					cout << endl;
				}
				cout << m_lineupSize << " Records imported..." << endl << endl;
			}
			else
			{
				cout << "No data or bad data file!" << endl << endl;
			}
		}
	}

	void PreTriage::reg()
	{
		int selection = 0;
		if (m_lineupSize >= maxNoOfPatients)
		{
			cout << "Line up full!" << endl;
		}
		else
		{
			m_pMenu >> selection;
			if (selection != 0)
			{
				while (m_lineup[m_lineupSize] != nullptr && m_lineupSize < maxNoOfPatients) //check next available spot
				{
					m_lineupSize++;
				}
				switch (selection)
				{
				case 1:
					m_lineup[m_lineupSize] = new CovidPatient();
					break;
				case 2:
					m_lineup[m_lineupSize] = new TriagePatient();
					break;
				}
				m_lineup[m_lineupSize]->setArrivalTime();
				cout << "Please enter patient information: " << endl;
				m_lineup[m_lineupSize]->fileIO(false);
				cin >> *m_lineup[m_lineupSize];
				cout << endl << "******************************************" << endl;
				cout << *m_lineup[m_lineupSize];
				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]);
				cout << endl << "******************************************" << endl << endl;
				m_lineupSize++;
			}
		}
	}
	void PreTriage::admit()
	{
		int selection = 0, index = 0;
		char type = '0';
		m_pMenu >> selection;
		if (selection != 0)
		{
			switch (selection)
			{
			case 1:
				type = 'C';
				break;
			case 2:
				type = 'T';
				break;
			}
			index = indexOfFirstInLine(type);
			if (index != -1)
			{
				//cout << "index: " << index << endl;
				cout << endl << "******************************************" << endl;
				m_lineup[index]->fileIO(false);
				cout << "Calling for " << *m_lineup[index];
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[index]);
				removePatientFromLineup(index);
			}
		}
	}
	void PreTriage::run(void)
	{
		int selection = 0;
		bool flag = false;
		while (flag == false)
		{
			m_appMenu >> selection;
			if (selection == 1)
			{
				reg();
			}
			else if (selection == 2)
			{
				admit();
			}
			else //0
			{
				flag = true;
			}
		}
	}
}
