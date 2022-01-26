#ifndef SDDS_pret_H_
#define SDDS_pret_H_
#include "Patient.h"
#include "Menu.h"

namespace sdds
{
	const int maxNoOfPatients = 100; //lineup size
	class PreTriage
	{
		Time
			m_averCovidWait,
			m_averTriageWait;
		Patient* m_lineup[maxNoOfPatients]{}; //array of patient pointers
		char* m_dataFilename = nullptr;
		int m_lineupSize = 0;
		Menu
			m_appMenu,  //manue interface
			m_pMenu;	//sub menu
		void reg();
		void admit();
		const Time getWaitTime(const Patient& p)const;
		void setAverageWaitTime(const Patient& p);
		void removePatientFromLineup(int index);
		int indexOfFirstInLine(char type) const;	//type of patient
		void load();	//load from datafile
	public:
		PreTriage(const char* dataFilename);
		virtual ~PreTriage();
		void run(void);	//entry way
	};
}
#endif 
