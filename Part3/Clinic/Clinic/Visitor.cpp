#include "Visitor.h"
#include "Secretary.h"
#include "ClinicManager.h"
void CallPatient::visit(Visitable* element)
{
	Secretary* secretary = dynamic_cast<Secretary*>(element);
	if (secretary)
		secretary->callPatient(*patient);
}

void FireStaff::visit(Visitable * element)
{
	ClinicManager* manager = dynamic_cast<ClinicManager*>(element);
	if (manager)
		manager->fireStaff(*staff);
}

void HireStaff::visit(Visitable * element)
{
	ClinicManager* manager = dynamic_cast<ClinicManager*>(element);
	if (manager)
		manager->hireStaff(*staff);
}