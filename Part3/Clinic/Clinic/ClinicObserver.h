#ifndef __CLINICOBSERVER
#define __CLINICOBSERVER
/*
Observer Design pattern for patient and medical staff
*/
class Turn;

class ClinicObserver
{
public:
	virtual void notify(Turn * turn) const = 0;
};

#endif