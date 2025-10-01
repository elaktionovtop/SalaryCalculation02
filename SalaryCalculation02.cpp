#include <iostream>
using namespace std;

class Employee
{
public:
    void display() const
    {
        cout << "!!!" << endl;
    }

};

class Worker : public Employee
{
};

class SalaryWorker : public Employee
{
};

class Salesman : public SalaryWorker
{
};

class Manager : public SalaryWorker
{
};

int main()
{
    Employee* employees[7];
    employees[0] = new Worker();
    employees[1] = new Worker();
    employees[2] = new Salesman();
    employees[3] = new Salesman();
    employees[4] = new Manager();
    employees[5] = new Manager();
    employees[6] = new Manager();

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
