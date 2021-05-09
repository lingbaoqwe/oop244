/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.h
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
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"

namespace sdds {
	class CovidPatient:public Patient
	{
	public:
		CovidPatient();
		char type()const;
		std::istream& csvRead(std::istream& is);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& is);
	};
}
#endif // !SDDS_COVIDPATIENT_H_



