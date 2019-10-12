//*****************************************************************************************
//*****************************************************************************************
//***************************	Name :	Ali Khutaba          ******************************
//***************************	ID	 :	205817562		     ******************************
//***************************                                ******************************
//***************************	Name :	Naor David           ******************************
//***************************	ID	 :	039761465  		     ******************************
//***************************                                ******************************
//***************************	version   1.0.0				 ******************************
//*************************** 	Update	27/08/2019 21:34     ******************************
//*****************************************************************************************
//*****************************************************************************************

#pragma warning(disable: 4996)
#include <iostream>
using namespace std;
#include "ClinicManager.h"
#include "Nurse.h"
int main()
{
	Clinic clinic("clinic", Address("Israel", "Tel-Aviv", "Hamoraim", 13, 4, 14));

	// Rooms
	Room room_1(101, 2, 120);
	Room room_2(102, 2, 150);
	Room room_3(103, 3, 190);
	Room room_4(104, 3, 80);
	Room room_5(105, 4, 250);
	Room room_6(106, 4, 100);
	Room room_7(107, 5, 90);
	Room room_8(108, 6, 30);
	Room room_9(109, 6, 90);
	Room room_10(110, 6, 90);

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
	Address address_1("Israel", "Tel-Aviv", "einstein", 43, 9, 18);
	Address address_2("Israel", "haifa", "karmel", 17, 12, 22);
	Address address_3("Israel", "Tel-Aviv", "bograshov", 64, 1, 2);
	Address address_4("Israel", "Bat-Yam", "balfour", 6, 8, 10);
	Address address_5("Israel", "Tel-Aviv", "yarkon", 5, 13, 14);
	Address address_6("Israel", "Herzliya", "bazel", 45, 1, 45);
	Address address_7("Israel", "Tel-Aviv", "dizengoff", 28, 19, 48);

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

	// Staff
	MedicalStaff doctor1_medical(person_1, 12412, 10000, 800, 1400, room_1);
	MedicalStaff doctor2_medical(person_2, 12413, 15000, 1000, 1800, room_2);

	Doctor doctor_1(doctor1_medical, "Oncologist");
	Doctor doctor_2(doctor2_medical, "Spine surgeon");

	MedicalStaff nurse1_medical(person_3, 12414, 8000, 900, 1500, room_3);
	MedicalStaff nurse2_medical(person_4, 12415, 7000, 1100, 1700, room_4);

	Nurse nurse_1(nurse1_medical, "Take blood samples");
	Nurse nurse_2(nurse2_medical, "Give infusion");

	//FIX OfficeStaff

	OfficeStaff staff1(person_5, 12416, 5000, room_5);
	OfficeStaff staff2(person_6, 12417, 6000, room_6);
	Secretary secretary_1(staff1);
	Secretary secretary_2(staff2);

	OfficeStaff manager_office(person_7, 12418, 20000, room_7);

	MedicalStaff manager_medical(person_7, 12412, 10000, 800, 1400, room_7);
	Doctor manager_doctor(manager_medical, "oncologist");
	ClinicManager manager(manager_office, manager_doctor);
	

	clinic.setClinicManager(&manager);

	manager.hireStaff(doctor_1);
	manager.hireStaff(doctor_2);
	manager.hireStaff(nurse_1);
	manager.hireStaff(nurse_2);
	manager.hireStaff(secretary_1);
	manager.hireStaff(secretary_2);

	// Patients
	Patient patient_1(person_8, doctor_1);
	Patient patient_2(person_9, doctor_2, true);
	Patient patient_3(person_10, doctor_1, true);

	clinic.addPatient(patient_1);
	clinic.addPatient(patient_2);
	clinic.addPatient(patient_3);

	// Turns

	Secretary* secretary = clinic.getSecretary();
	if (secretary != nullptr)
		secretary->callPatient(patient_1);

	//Turn turn_1(doctor_1, patient_1, 1000, 200);
	//Turn turn_2(doctor_2, patient_2, 1200, 100);
	//Turn turn_3(doctor_1, patient_3, 1400, 130);
	//Turn turn_4(doctor_1, patient_1, 1400, 130);

	//clinic.addTurn(turn_1);
	//clinic.addTurn(turn_2);
	//clinic.addTurn(turn_3);

	//clinic.updateTurn(turn_1, turn_4);
	//clinic.removeTurn(turn_3);
	//clinic.updateTurn(turn_1, turn_4);
	cout << "----------------------------------------------------------------------------\n";
	cout << clinic << endl;

	manager.fireStaff(secretary_1);

	clinic.removePatient(patient_2);

	clinic.removeRoom(room_5);

	clinic.removeRoom(room_6);

	return 0;
}

//Add virtual to destructors and functions?

//fix inheritance

//add const where missing

//camelCase vs camel_case

//add virtual to functions

//add "this" to constructors

//ref to pointer in classes

//name(NULL) add to classes

//check TODO

//Clinic should create turns

//add getters to clinic

//check which functions need to return refs

//move defines to class as static

//improve prints

//remove unneccassary comments

//implement dates in turns, add pointer array for turns in medical staff, medical staff should return next available turn
//sort array by date/time

//add more move ctors

//add more operators? [optional]

//copy ctor - use = operator (page 26, operators)

//add mutables??