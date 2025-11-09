#include<iostream>
using namespace std;
// Design a class Employee with the following specifications:
class Employee {
private:
	// dynamically created data members for name, id, and salary
	// for deep copy constructor
	string* name;
	int* id;
	double* salary;
	const string company_name;
	static int employee_count;
public:
	//default constructor
	Employee() :company_name("TechSolutions") {
		name = new string("Unknown");
		id = new int(0);
		salary = new double(0.0);
		employee_count++;
	}
	//parameterized constructor and constructor intializer list to initialize company_name
	Employee(const string name, int id, double salary) :company_name("TechSolutions") {
		//this pointer to resolve the naming conflict
		this->name = new string(name);
		this->id = new int(id);
		this->salary = new double(salary);
		employee_count++;
	}
	//deep copy constructor
	Employee(const Employee& emp) : company_name(emp.company_name) {
		name = new string(*(emp.name));
		id = new int(*(emp.id));
		salary = new double(*(emp.salary));
		employee_count++;
	}
	/*shallow copy constructor(commented out to avoid confusion)
	Employee(const Employee& emp) : company_name(emp.company_name) {
		name = emp.name;
		id = emp.id;
		salary = emp.salary;
		employee_count++;
	}*/
	//constant member function to display employee details
	void display()const {
		cout << "The Employee name is:" << *name << endl;
		cout << "The Employee Id is:" << *id << endl;
		cout << "The Employee salary is:" << *salary << endl;
		cout << "The company name is:" << company_name << endl;
		cout << endl;
	}
	//static member function to display total number of employees
	static void displayCount() {
		cout << "The Total Employees in the company are: " << employee_count << endl;
	}
	//returning an object from a member function making it static so it can be called without an object
	static Employee createEmployee() {
		Employee e1("fatima", 102, 45000);
		return e1;
	}
	//passing object as an argument
	void updateSalary( Employee& emp, double increment) {
		*(emp.salary) += increment;
		cout << "The updated salary of " << *(emp.name) << " is: " << *(emp.salary) << endl;
	}
	//set id 
	void setID(int newID) {
		*(this->id) = newID;
	}
	//destructor to free dynamically allocated memory
	~Employee() {
		delete name;
		delete id;
		delete salary;
		employee_count--;
	}
};
int Employee::employee_count = 0;
int main() {
	cout << "The Employee details are:" << endl;
	cout << endl;
	//creating object by returning object function
	Employee e1=Employee::createEmployee();
	e1.display();
	e1.updateSalary(e1, 5000);
	cout << endl;
	//creating object using parameterized constructor
	Employee e2("Ali", 101, 60000);
	e2.display();
	cout << endl;
	//creating object using copy constructor
	Employee e3 = e2;
	e3.display();
	cout << endl;
	//creating object using dynamic memory allocation
	Employee* e4 = new Employee("Sara", 103, 70000);
	e4->display();
	e4->updateSalary(*e4, 8000);
	cout << endl;
	//modifying e2's id using setID function
	e2.setID(202);
	e2.display();
	//after modifying e2's id
	//there is no change in e3's id proving deep copy
	cout << "After modifying e2's id:" << endl;
	e3.display();
	Employee::displayCount();
	delete e4;
	return 0;
}