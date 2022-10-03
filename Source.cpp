#include <iostream>
#include<string>
using namespace std;
class employee {
protected:
	string name;
	int emp_id;
	float salary;
	employee() : name("unknown"), emp_id(0), salary(0.0) {
	}
	employee(string n, int id, float sal) {
		name = n;
		emp_id = id;
		salary = sal;
	}
	virtual double get_total_salary() = 0;
	virtual void print() {
		cout << " mr. " << name << endl << "employee id : " <<
			emp_id << endl << " salary : " << salary << endl;
	}
};
class sales : public employee {
	float Goss_sales;
	float commission_rate;
public:
	sales(string n, int id, float sal, float gs, float cs):
		employee(n, id, sal) {
		Goss_sales = gs;
		commission_rate = cs;
	}
	double get_total_salary() {
		return salary + (Goss_sales * commission_rate);
	}
	void print() {
		employee::print();
		cout << " Goss sales : " << Goss_sales << endl << " commission rate : " <<
			commission_rate << endl;
	}
};
class developer : public employee {
	string  specialty;
	int experiance;
	int over_time;
	float overtime_hour_rate;
public:
	developer(string  n, int id, float sal, string  sp, int ex, int ot, float ohr)
		:employee(n, id, sal) {
		specialty = sp;
		experiance = ex;
		over_time = ot;
		overtime_hour_rate = ohr;
	}
	double get_total_salary() {
		return salary + (over_time * overtime_hour_rate);
	}
	void print() {
		employee :: print();
		cout << " specialty : " << specialty << endl << " experiance : " <<
			experiance << endl << " over time : " << over_time <<
			endl << " over time hour rate : " << overtime_hour_rate << endl;
	}
};
int main() {

	employee* e1;
	developer s1("Abdulrhman", 100145007, 10000,"software engineer", 1,4,100);
	e1 = &s1;
	s1.get_total_salary();
	s1.print();



	return 0;
}