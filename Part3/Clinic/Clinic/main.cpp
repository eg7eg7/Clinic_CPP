//*****************************************************************************************
//***************************	    	PART 1				 ******************************
//***************************	Name :	Ali Khutaba          ******************************
//***************************	ID	 :	205817562		     ******************************
//***************************                                ******************************
//***************************	Name :	Naor David           ******************************
//***************************	ID	 :	039761465  		     ******************************
//*****************************************************************************************
//*****************************************************************************************
//***************************	    	PART 2&3			 ******************************
//***************************	Name :	EDEN DUPONT          ******************************
//***************************	ID	 :	204808596		     ******************************
//***************************                                ******************************
//***************************	Name :	INBAL AZAR           ******************************
//***************************	ID	 :	307943001  		     ******************************
//*****************************************************************************************

#pragma warning(disable: 4996)
#pragma warning(disable: 4290)

#include <iostream>
using namespace std;
#include "ClinicManager.h"

void populateClinic(Clinic& clinic);
void exceptionCatcher();

int main()
{
	set_terminate(exceptionCatcher);

	Clinic clinic("Macabbi", Address("Israel", "Tel-Aviv", "Ben Gurion", 13, 4, 14));

	populateClinic(clinic);

	clinic.getManager()->changeClinicName("Clalit");

	clinic.checkPatients();

	cout << clinic << endl;
	try
	{
		clinic.getManager()->fireStaff(clinic.getNurse());
		clinic.getManager()->fireStaff(clinic.getSecretary());
	}
	catch (const string msg)
	{
		cout << msg << endl;
	}
	cout << "---------------------------------END MAIN-------------------------------------------\n";
	return 0;
}

void exceptionCatcher()
{
	cout << "An error was caught during runtime, please debug!" << endl;
	exit(1);
}

void populateClinic(Clinic& clinic)
{
	cout << "Populating clinic " << clinic.getName() << "...." << endl << endl;
	// Rooms
	Room* room_1 = new Room(101, 2, 120);
	Room* room_2 = new Room(102, 2, 150);
	Room* room_3 = new Room(103, 3, 190);
	Room* room_4 = new Room(104, 3, 80);
	Room* room_5 = new Room(105, 4, 250);
	Room* room_6 = new Room(106, 4, 100);
	Room* room_7 = new Room(107, 5, 90);
	Room* room_8 = new Room(108, 6, 30);
	Room* room_9 = new Room(109, 6, 90);
	Room* room_10 = new Room(110, 6, 90);

	clinic.addRoom(room_1);
	clinic.addRoom(room_2);
	clinic.addRoom(room_3);
	clinic.addRoom(room_4);
	clinic.addRoom(room_5);
	clinic.addRoom(room_6);
	clinic.addRoom(room_7);
	clinic.addRoom(room_8);
	clinic.addRoom(room_9);
	clinic.addRoom(room_10);

	// Addresses
	Address address_1("Israel", "Tel-Aviv", "Einstein", 43, 9, 18);
	Address address_2("Israel", "Haifa", "Hakarmel", 17, 12, 22);
	Address address_3("Israel", "Tel-Aviv", "Bograshov", 64, 1, 2);
	Address address_4("Israel", "Bat-Yam", "Balfour", 6, 8, 10);
	Address address_5("Israel", "Tel-Aviv", "Yarkon", 5, 13, 14);
	Address address_6("Israel", "Herzliya", "Basel", 45, 1, 45);
	Address address_7("Israel", "Tel-Aviv", "Dizengoff", 28, 19, 48);
	Address address_8("Israel", "Eilat", "Habanim", 2, 19, 48);
	Address address_9("Israel", "Jaffa", "Bernoulli", 8, 3, 48);
	Address address_10("Israel", "Ashkelon", "Newton", 3, 29, 48);
	Address address_11("Israel", "Rehovot", "Cantor", 5, 69, 48);
	Address address_12("Israel", "Rishon-Letzion", "Leibniz", 7, 9, 48);

	// Persons
	Person person_1(1000, "Dr. Hopkins", "054-452-123", 34, address_1, Person::Male);
	Person person_2(2000, "Dr. Phil", "053-279-9012", 53, address_2, Person::Female);
	Person person_3(3000, "Nurse_1", "050-327-1289", 19, address_3, Person::Male);
	Person person_4(4000, "Nurse_2", "052-573-4379", 21, address_4, Person::Female);
	Person person_5(5000, "Secretary_1", "052-879-2132", 84, address_5, Person::Male);
	Person person_6(6000, "Secretary_2", "050-435-5676", 52, address_6, Person::Female);
	Person person_7(7000, "Dr. House", "054-684-3452", 2, address_7, Person::Male);

	Person person_8(3333, "patient_1", "050-231-4579", 92, address_3, Person::Male);
	Person person_9(4444, "patient_2", "054-782-4362", 18, address_2, Person::Female);
	Person person_10(5555, "patient_3", "052-451-0921", 54, address_4, Person::Female);

	Person person_11(3333, "patient_4", "052-231-4579", 17, address_7, Person::Male);
	Person person_12(4444, "patient_5", "051-782-4362", 13, address_6, Person::Female);
	Person person_13(5555, "patient_6", "053-451-0921", 104, address_9, Person::Female);

	Person person_14(3333, "patient_7", "054-231-4579", 3, address_10, Person::Male);
	Person person_15(4444, "patient_8", "055-782-4362", 21, address_11, Person::Female);
	Person person_16(5555, "patient_9", "056-451-0921", 36, address_12, Person::Female);

	// Staff
	MedicalStaff doctor1_medical(person_1, 12412, 10000, Time(8, 0), Time(14, 0), *room_1);
	MedicalStaff doctor2_medical(person_2, 12413, 15000, Time(10, 0), Time(18, 0), *room_2);

	Doctor* doctor_1 = new Doctor(doctor1_medical, "Oncologist");
	Doctor* doctor_2 = new Doctor(doctor2_medical, "Spine surgeon");

	MedicalStaff nurse1_medical(person_3, 12414, 8000, Time(9, 0), Time(15, 0), *room_3);
	MedicalStaff nurse2_medical(person_4, 12415, 7000, Time(11, 0), Time(17, 0), *room_4);

	Nurse* nurse_1 = new Nurse(nurse1_medical, "Take blood samples");
	Nurse* nurse_2 = new Nurse(nurse2_medical, "Give infusion");

	OfficeStaff staff1(person_5, 12416, 5000, *room_5);
	OfficeStaff staff2(person_6, 12417, 6000, *room_6);
	Secretary* secretary_1 = new Secretary(staff1);
	Secretary* secretary_2 = new Secretary(staff2);

	OfficeStaff manager_office(person_7, 12418, 20000, *room_7);

	MedicalStaff manager_medical(person_7, 12412, 10000, Time(8, 0), Time(14, 0), *room_7);
	Doctor manager_doctor(manager_medical, "oncologist");
	ClinicManager* manager = new ClinicManager(manager_office, manager_doctor);

	clinic.setClinicManager(manager);

	manager->hireStaff(*doctor_1);
	manager->hireStaff(*doctor_2);
	manager->hireStaff(*nurse_1);
	manager->hireStaff(*nurse_2);
	manager->hireStaff(*secretary_1);
	manager->hireStaff(*secretary_2);

	// Patients
	Patient* patient_1 = new Patient(person_8, *doctor_1);
	Patient* patient_2 = new Patient(person_9, *doctor_2, Patient::SICK);
	Patient* patient_3 = new Patient(person_10, *doctor_1, Patient::SICK);
	Patient* patient_4 = new Patient(person_11, *doctor_1, Patient::REQUIRE_TREATMENT);
	Patient* patient_5 = new Patient(person_12, *doctor_2, Patient::SICK);
	Patient* patient_6 = new Patient(person_13, *doctor_1, Patient::REQUIRE_TREATMENT);
	Patient* patient_7 = new Patient(person_14, *doctor_1, Patient::REQUIRE_TREATMENT);
	Patient* patient_8 = new Patient(person_15, *doctor_2);
	Patient* patient_9 = new Patient(person_16, *doctor_1, Patient::SICK);

	clinic.addPatient(patient_1);
	clinic.addPatient(patient_2);
	clinic.addPatient(patient_3);
	clinic.addPatient(patient_4);
	clinic.addPatient(patient_5);
	clinic.addPatient(patient_6);
	clinic.addPatient(patient_7);
	clinic.addPatient(patient_8);
	clinic.addPatient(patient_9);

	cout << "Populating clinic finished." << endl << endl;
}

//split LinkedList to cpp and h

//use setter getters instead of direct access in LinkedList to nodes

//finish implementing node

//catch exceptions

//review iterator at the end

//design patterns

//switch to strings

//in part2 and part3 - make getSecretary return a non-const object

//in part2, remove ref from catch in clinic.cpp and secretary.cpp
//this line catch (const char*& msg)

//add const to functions in LinkedList

//in part 2 - person.cpp - in operator= , other.address not included!

//add throws to setTime in part2 and part3

//remove in Time.h const bool& ---> change to bool

//remove empty dtor, copy ctor, operator=, also in part2

//remove copy c'tor for clinic

//add to part 2 #pragma warning(disable: 4290)

//remove printed variable in prints at clinic

//make printpatients, printstaff..etc a general func that gets a vector to print

//add is_heap http://www.cplusplus.com/reference/algorithm/

//go over TODO

//part 2 - in secretary cpp - (if (answer == Patient::eStatus::SICK || medical == nullptr))
//remove else before if

//part2 - make getNextFreeTime throw an error
//also change:

//timeDifference1 = Time::getTimeDifference(this->acceptHoursFrom, turns[0]->getStartTime());
//if (timeDifference1 >= sessionDurationMins)
//*****************return this->acceptHoursTo; TO return this->acceptHoursFrom

//indent all code