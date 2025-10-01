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

    virtual double calculateSalary() const = 0;

    virtual void display() const
    {
        cout << getFirstName() << " " << getLastName() << endl;
    }
};

class Worker : public Employee
{
private:
    const int hoursLimit = 40;
    int  hoursNumber;
    double hourlyRate;
public:
    Worker(const string& firstName, const string& lastName,
        int hoursNumber, double hourlyRate)
        : Employee(firstName, lastName)
    {
        setHoursNumber(hoursNumber);
        setHourlyRate(hourlyRate);
    }
    void setHourlyRate(double hourlyRate)
    {
        this->hourlyRate = hourlyRate < 0.0 ? 0.0 : hourlyRate;
    }

    double getHourlyRate() const
    {
        return hourlyRate;
    }

    void setHoursNumber(double hoursNumber)
    {
        this->hoursNumber = hoursNumber < 0.0 ? 0.0 : hoursNumber;
    }

    double getHoursNumber() const
    {
        return hoursNumber;
    }

    double calculateSalary() const override
    {
        double salary = getHourlyRate() * getHoursNumber();
        if (getHoursNumber() > hoursLimit)
        {
            salary += (getHoursNumber() - hoursLimit) * getHourlyRate();
        }
        return  salary;
    }

    void display() const override
    {
        Employee::display();
        cout << 
            "hours number: " << getHoursNumber() <<
            ", hourly rate: " << getHourlyRate() <<
            ", month salary: " << calculateSalary() << endl;
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

    double calculateSalary() const override
    {
        return 0;
    }
};

class Manager : public SalaryWorker
{
public:
    Manager(const string& firstName, const string& lastName)
        : SalaryWorker(firstName, lastName)
    {
    }

    double calculateSalary() const override
    {
        return 0;
    }
};

int main()
{
    Employee* employees[7];
    employees[0] = new Worker("Kate", "Jordan", 30, 10);
    employees[1] = new Worker("Jack", "Peterson", 50, 10);
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
