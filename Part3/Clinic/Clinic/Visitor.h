#ifndef __VISITOR
#define __VISITOR

class Visitable;
class Patient;

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

class CallPatient : public Visitor
{
public:
	CallPatient(Patient* patient) { this->patient = patient; };

	virtual void visit(Visitable* element);
private:
	Patient* patient;
};
#endif // !__VISITABLE
