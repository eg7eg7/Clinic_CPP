#ifndef __VISITOR
#define __VISITOR

/*
Classes created for the Visitor design pattern
*/
class Visitable;
class Patient;
class Staff;

class Visitor
{
public:
	virtual void visit(Visitable* visitable) = 0;
};
class Visitable
{
public:
	virtual void accept(Visitor* visitor) = 0;
};

//To be used by secretary to call patients
class CallPatient : public Visitor
{
public:
	CallPatient(Patient* patient) { this->patient = patient; };

	virtual void visit(Visitable* element);
private:
	Patient* patient;
};

//to be used by clinic manager
class FireStaff : public Visitor
{
public:
	FireStaff(Staff* staff) { this->staff = staff; };

	virtual void visit(Visitable* element);
private:
	Staff* staff;
};

//to be used by clinic manager
class HireStaff : public Visitor
{
public:
	HireStaff(Staff* staff) { this->staff = staff; };

	virtual void visit(Visitable* element);
private:
	Staff* staff;
};
#endif // !__VISITABLE
