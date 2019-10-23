#include "Doctor.h"

Doctor::Doctor(const MedicalStaff && medicalStaff, const string& profession) : Staff(std::move(medicalStaff)), MedicalStaff(std::move(medicalStaff)), profession(profession)
{
	//nothing
}

Doctor::Doctor(const MedicalStaff & medicalStaff, const  string& profession) : Staff(medicalStaff), MedicalStaff(medicalStaff), profession(profession)
{
	//nothing
}




void Doctor::toOs(ostream & os) const
{
	os << "**Doctor**" << endl;
	MedicalStaff::toOs(os);
	os << "Profession: " << profession << endl;
}