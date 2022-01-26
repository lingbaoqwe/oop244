#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include "Patient.h"
using namespace std;
namespace sdds
{
	Patient::Patient(int num, bool io)
	{
		pname = nullptr;
		OHIP = 0;
		mticket = new Ticket(num);
		flag = io;
	}
	Patient::~Patient()
	{
		delete[]pname;
		pname = nullptr;
		delete mticket;
	}
	bool Patient::fileIO() const
	{
		return flag;
	}
	void Patient::fileIO(bool fla)
	{
		flag = fla;
	}
	bool Patient::operator==(char Ptype) const
	{
		bool tflag = false;
		if (this->type() == Ptype)
		{
			tflag = true;
		}
		return tflag;
	}
	bool Patient::operator==(const Patient& fii)const
	{
		bool tflag = false;
		if (this->type() == fii.type())
		{
			tflag = true;
		}
		return tflag;
	}
	void Patient::setArrivalTime()
	{
		mticket->resetTime();
	}
	Patient::operator Time() const
	{
		return Time(*mticket);
	}
	int Patient::number() const
	{
		return mticket->number();
	}
	ostream& Patient::csvWrite(ostream& os) const
	{
		os << type() << ',' << pname << ',' << OHIP << ',';
		mticket->csvWrite(os);
		return os;
	}
	istream& Patient::csvRead(istream& is)
	{
		delete[]pname;
		pname = getcstr(nullptr, is,',');
		if (pname != nullptr)
		{
			is >> OHIP;
			is.get();
			mticket->csvRead(is);
		}
		return is;
	}
	ostream& Patient::write(std::ostream& os) const
	{
		os << "Ticket No: ";
		os << mticket->number();
		os << ", Issued at: " << Time(*mticket) << endl;
		for (unsigned int i = 0; i < strlen(pname) && i < 25; i++)
		{
			os << pname[i];
		}
		os << ", OHIP: ";
		os << OHIP;
		return os;
	}
	istream& Patient::read(istream& is)
	{
		delete[]pname;
		pname = getcstr("Name: ");
		cout << "OHIP: ";
		OHIP = getInt(100000000, 999999999,nullptr, "Invalid OHIP Number, ", true);
		return is;
	}
}
