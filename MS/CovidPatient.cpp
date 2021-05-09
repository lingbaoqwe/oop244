/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.cpp
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
#include "CovidPatient.h"
using namespace std;
namespace sdds {
   int nextCovidTicket = 1;
   CovidPatient::CovidPatient():Patient(nextCovidTicket)
   {
	   nextCovidTicket++;
   }
   char CovidPatient::type() const
   {
	   return 'C';
   }
   std::istream& CovidPatient::csvRead(std::istream& is)
   {
	   Patient::csvRead(is);
	   nextCovidTicket = number() + 1; //next in line
	   is.ignore(1000, '\n');
	   return is;
   }
   std::ostream& CovidPatient::write(std::ostream& os) const
   {
	   if (fileIO())
	   {
		   Patient::csvWrite(os);
	   }
	   else
	   {
		   os << "COVID TEST" << endl;
		   Patient::write(os);
		   os << endl;
	   }
	   return os;
   }
   std::istream& CovidPatient::read(std::istream& is)
   {
	   if (fileIO())
	   {
		   csvRead(is);
	   }
	   else
	   {
		   Patient::read(is);
	   }
	   return is;
   }
}