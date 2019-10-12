#pragma message("Adding Secretary")
#ifndef __SECRETARY_H
#define __SECRETARY_H

#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include "OfficeStaff.h"
#include "Turn.h"


class Secretary : public OfficeStaff
{
	
public:
	Secretary(OfficeStaff & officeStaff) : Staff(officeStaff), OfficeStaff(officeStaff) {};
	Secretary(Secretary&& Secretary);	// move ctor
	Secretary(const Secretary& Secretary) : Staff(Secretary), OfficeStaff(Secretary) {
		*this = Secretary;
	};	// copy ctor
	virtual ~Secretary() {};
	// Methods
	void callPatient(Patient & patient);

	virtual void toOs(ostream& os) const override;
	const Secretary& operator=(const Secretary& other);
};

#endif // !__SECRETARY_H
