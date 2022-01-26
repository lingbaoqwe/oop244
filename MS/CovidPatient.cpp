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
