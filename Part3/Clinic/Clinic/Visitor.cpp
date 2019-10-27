#include "Visitor.h"
#include "Secretary.h"
void CallPatient::visit(Visitable* element)
{
	Secretary* secretary = dynamic_cast<Secretary*>(element);
	if (secretary)
		secretary->callPatient(*patient);
}