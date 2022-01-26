#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"
namespace sdds {
	class TriagePatient :public Patient
	{
		char* p; //symptom
	public:
		TriagePatient();
		virtual ~TriagePatient();
		char type()const;
		std::istream& csvRead(std::istream& is);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& is);
		std::ostream& csvWrite(std::ostream& os)const;
	};
}
#endif // !SDDS_TRIAGEPATIENT_H


