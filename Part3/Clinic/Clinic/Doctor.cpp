#include "Doctor.h"

Doctor::Doctor(const Doctor && other) : Staff(std::move(other)), MedicalStaff(std::move(other)), profession(std::move(other.profession))
{
	//nothing
}

Doctor::Doctor(const MedicalStaff && medicalStaff, const string& profession) : Staff(std::move(medicalStaff)), MedicalStaff(std::move(medicalStaff)), profession(profession)
{
	//nothing
}

Doctor::Doctor(const MedicalStaff & medicalStaff, const  string& profession) : Staff(medicalStaff), MedicalStaff(medicalStaff), profession(profession)
{
	//nothing
}


Doctor::Doctor(const Doctor & other) : Staff(other), MedicalStaff(other), profession(other.profession)
{ 
	//nothing
}

Doctor::~Doctor()
{
	//nothing
}

const Doctor& Doctor::operator=(const Doctor& doctor)
{
	if (this != &doctor)
	{
		MedicalStaff::operator=(doctor);
		this->profession = doctor.profession;
	}
	return *this;
}

void Doctor::toOs(ostream & os) const
{
	os << "**Doctor**" << endl;
	MedicalStaff::toOs(os);
	os << "Profession: " << profession << endl;
}