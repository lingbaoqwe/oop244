/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Author	Bo Wen Hou
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/20  Preliminary release
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
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{
	Time& Time::setToNow()
	{
		m_min = getTime();
		return *this;
	}
	Time::Time(unsigned int minutes)
	{
		m_min = minutes;
	}
	ostream& Time::write(ostream& ostr) const
	{
		unsigned int hr = m_min / 60;
		unsigned int min = m_min % 60;
		if (hr <= 9)
		{
			ostr << "0";
		}
		ostr << hr;
		ostr << ":";
		if (min <= 9)
		{
			ostr << 0;
		}
		ostr << min;
		return ostr;
	}
	istream& Time::read(istream& istr)
	{
		int hr=0, min=0;
		istr >> hr;
		if (hr < 0)
		{
			istr.setstate(ios::failbit);
		}
		else if (istr.get() != ':')
		{
			istr.setstate(ios::failbit);
		}
		istr >> min;
		if (min < 0)
		{
			istr.setstate(ios::failbit);
		}
		m_min = hr * 60 + min;
		return istr;
	}
	Time& Time::operator-=(const Time& D)
	{
		while (m_min < D.m_min)
		{
			m_min += 24 * 60; //24 hr til bigger
		}
		m_min -= D.m_min;
		return *this;
	}
	Time Time::operator-(const Time& D)const
	{
		Time temp = *this;
		while (temp.m_min < D.m_min)
		{
			temp.m_min += 24 * 60; //24 hr til bigger
		}
		temp.m_min -= D.m_min;
		return temp;
	}
	Time& Time::operator+=(const Time& D)
	{
		m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D)const
	{
		Time temp = *this;
		temp.m_min += D.m_min;
		return temp;
	}
	Time& Time::operator=(unsigned int val)
	{
		m_min = val;
		return *this;
	}
	Time& Time::operator *= (unsigned int val)
	{
		m_min *= val;
		return *this;
	}
	Time Time::operator *(unsigned int val)const
	{
		Time temp = *this;
		temp.m_min *= val;
		return temp;
	}
	Time& Time::operator /= (unsigned int val)
	{
		m_min /= val;
		return *this;
	}
	Time Time::operator /(unsigned int val)const
	{
		Time temp = *this;
		temp.m_min /= val;
		return temp;
	}
	Time::operator int()const
	{
		return(int)m_min;
	}
	Time::operator unsigned int()const
	{
		return(unsigned int)m_min;
	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D)
	{
		D.write(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, Time& D)
	{
		D.read(istr);
		return istr;
	}
}