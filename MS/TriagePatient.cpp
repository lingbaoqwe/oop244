/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author	Bo Wen Hou
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/30  Preliminary release
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
#include <iostream>
#include <string>
#include <cstring>
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	int nextTriageTicket = 1;
	TriagePatient::TriagePatient() :Patient(nextTriageTicket)
	{
		nextTriageTicket++;
		p = nullptr; //symptom
	}
	char TriagePatient::type() const
	{
		return 'T';
	}
	std::istream& TriagePatient::csvRead(std::istream& is)
	{
		delete[]p;
		Patient::csvRead(is);
		is.ignore();
		p = getcstr(nullptr,is);
		nextTriageTicket = number() + 1; //next in line
		return is;
	}
	std::ostream& TriagePatient::write(std::ostream& os) const
	{
		if (fileIO())
		{
			Patient::csvWrite(os);
			os << ',' << p;
		}
		else
		{
			os << "TRIAGE" << endl;
			Patient::write(os);
			os << endl;
			os << "Symptoms: " << p << endl;
		}
		return os;
	}
	std::istream& TriagePatient::read(std::istream& is)
	{
		if (fileIO())
		{
			csvRead(is);
		}
		else
		{
			delete[]p;
			Patient::read(is);
			p = getcstr("Symptoms: ");
		}
		return is;
	}
	std::ostream& TriagePatient::csvWrite(std::ostream& os) const
	{
		Patient::csvWrite(os);
		os << ',' << p; //symptom
		return os;
	}
	TriagePatient::~TriagePatient()
	{
		delete[]p;
	}
}