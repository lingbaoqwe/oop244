/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.0
Author	Bo Wen Hou
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/27  Preliminary release
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
#ifndef SDDS_patient_H
#define SDDS_patient_H
#include "Time.h"
#include "IOAble.h"
#include "Ticket.h"
#include"utils.h"
namespace sdds
{
	class Patient :public IOAble
	{
		char* pname;
		int OHIP;
		Ticket* mticket;
		bool flag;
	public:
		Patient(int num=0,bool io=false);
		virtual ~Patient();
		Patient(const Patient&) = delete;
		Patient& operator = (const Patient&) = delete;
		virtual char type()const= 0;
		bool fileIO()const;
		void fileIO(bool);
		bool operator==(char)const;
		bool operator==(const Patient&)const;
		void setArrivalTime();
		operator Time()const;
		int number()const;
		std::ostream& csvWrite(std::ostream& os)const;
		std::istream& csvRead(std::istream& is);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& is);
	};
}
#endif