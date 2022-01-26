#define _CRT_SECURE_NO_WARNINGS
#include "IOAble.h"
using namespace std;
namespace sdds
{
	std::ostream& operator<<(std::ostream& os, const IOAble& D)
	{
		D.write(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, IOAble& D)
	{
		D.read(is);
		return is;
	}
}
