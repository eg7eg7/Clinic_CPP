#include "ClinicManager.h"

void ClinicManager::setClinic(Clinic* new_clinic)
{
	if (clinic != new_clinic)
	{
		clinic = new_clinic;
		if (clinic != nullptr)
			clinic->setClinicManager(this);
	}
}