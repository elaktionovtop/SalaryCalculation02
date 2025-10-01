#include <iostream>
using namespace std;

class Employee
{
private:
    string firstName;
    string lastName;
public:
    Employee(const string& firstName, const string& lastName)
        : firstName(firstName), lastName(lastName)
    {
    }

    void setFirstName(const string& firstName)
    {
        this->firstName = firstName;
    }

    string getFirstName() const
    {
        return firstName;
    }

    void setLastName(const string& lastName)
    {
        this->lastName = lastName;
    }

    string getLastName() const
    {
        return lastName;
    }

    void display() const
    {
        cout << getFirstName() << " " << getLastName() << endl;
    }
};

class Worker : public Employee
{
public:
    Worker(const string& firstName, const string& lastName)
        : Employee(firstName, lastName)
    {
    }
};

class SalaryWorker : public Employee
{
public:
    SalaryWorker(const string& firstName, const string& lastName)
        : Employee(firstName, lastName)
    {
    }
};

class Salesman : public SalaryWorker
{
public:
    Salesman(const string& firstName, const string& lastName)
        : SalaryWorker(firstName, lastName)
    {
    }
};

class Manager : public SalaryWorker
{
public:
    Manager(const string& firstName, const string& lastName)
        : SalaryWorker(firstName, lastName)
    {
    }
};

int main()
{
    Employee* employees[7];
    employees[0] = new Worker("Kate", "Jordan");
    employees[1] = new Worker("Jack", "Peterson");
    employees[2] = new Salesman("Peter", "Brown");
    employees[3] = new Salesman("Antony", "Norton");
    employees[4] = new Manager("David", "Flynn");
    employees[5] = new Manager("Marian", "Wood");
    employees[6] = new Manager("Brent", "Simpson");

    for (auto item : employees)
    {
        item->display();
    }

    for (auto item : employees)
    {
        delete item;
    }

    cout << endl;
    cin.get();
    return 0;
}
