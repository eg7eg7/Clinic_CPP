#include "Doctor.h"

Doctor::Doctor(const Doctor && other): Staff(std::move(other)), MedicalStaff(std::move(other))
{
	profession = std::move(other.profession);
}

Doctor::Doctor(const MedicalStaff && medicalStaff, const char * profession) : Staff(std::move(medicalStaff)) ,MedicalStaff(std::move(medicalStaff))
{
	profession = strdup(profession);
}

Doctor::~Doctor()
{
	delete[]profession;
}

const Doctor& Doctor::operator=(const Doctor& doctor)
{
	if (this != &doctor)
	{
		MedicalStaff::operator=(doctor);
		delete[]profession;
		profession = strdup(doctor.getProfession());
	}
	return *this;
}

void Doctor::toOs(ostream & os) const
{
	os << "**Doctor**" << endl;
	MedicalStaff::toOs(os);
	os << "Profession: " << profession << endl;
}