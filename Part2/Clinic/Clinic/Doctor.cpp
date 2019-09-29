#include "Doctor.h"

Doctor::~Doctor()
{
	delete[]profession;
}

const Doctor& Doctor::operator=(const Doctor& doctor)
{
	if (this != &doctor)
	{
		delete[]profession;
		profession = strdup(doctor.getProfession());
	}
	return *this;
}


void Doctor::toOs(ostream & os) const
{
	MedicalStaff::toOs(os);
	os << "**Doctor**" << endl
		<< "Profession: " << profession << endl;
}
