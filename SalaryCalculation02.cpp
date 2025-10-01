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
private:
    double salary;
    double bonus;
public:
    SalaryWorker(const string& firstName, const string& lastName)
        : Employee(firstName, lastName)
    { }

    SalaryWorker(const string& firstName, const string& lastName,
        double salary, double bonus)
        : Employee(firstName, lastName)
    {
        setSalary(salary);
        setBonus(bonus);
    }

    void setSalary(double salary)
    {
        this->salary = salary < 0.0 ? 0.0 : salary;
    }

    double getSalary() const
    {
        return salary;
    }

    void setBonus(double bonus)
    {
        this->bonus = bonus < 0.0 ? 0.0 : bonus;
    }

    double getBonus() const
    {
        return bonus;
    }

    virtual double calculateBonus() const = 0;

    double calculateSalary() const override
    {
        return getSalary() + calculateBonus();
    }
};

class Salesman : public SalaryWorker
{
private:
    double planPercentage;
public:
    Salesman(const string& firstName, const string& lastName,
        double salary, double bonus, double planPercentage)
        : SalaryWorker(firstName, lastName, salary, bonus)
    {
        setPercentage(planPercentage);
    }

    void setPercentage(double planPercentage)
    {
        this->planPercentage = planPercentage < 0.0 ? 0.0 : planPercentage;
    }

    double getPercentage() const
    {
        return planPercentage;
    }

    double calculateBonus() const override
    {
        return getBonus() * planPercentage / 100;
    }

    virtual void display() const override
    {
        Employee::display();
        cout <<
            "salary: " << getSalary() << ", bonus: " << getBonus() <<
            ", plan percentage: " << planPercentage <<
            ", month salary: " << calculateSalary() << endl;
    }
};

class Manager : public SalaryWorker
{
private:
    const int doubleBonusClients = 100;
    const int tripleBonusClients = 200;
    int clientCount;
public:
    Manager(const string& firstName, const string& lastName,
        double salary, double bonus, int clientCount)
        : SalaryWorker(firstName, lastName, salary, bonus)
    {
        setClientCount(clientCount);
    }

    void setClientCount(int clientCount)
    {
        this->clientCount = clientCount < 0 ? 0 : clientCount;
    }

    int getClientCount() const
    {
        return clientCount;
    }

    double calculateBonus() const override
    {
        if (clientCount > tripleBonusClients)
        {
            return getBonus() * 3;
        }

        if (clientCount > doubleBonusClients)
        {
            return getBonus() * 2;
        }

        return getBonus();
    }

    virtual void display() const override
    {
        Employee::display();
        cout <<
            "salary: " << getSalary() << ", bonus: " << getBonus() <<
            ", clients count: " << clientCount <<
            ", month salary: " << calculateSalary() << endl;
    }
};

int main()
{
    Employee* employees[7];
    employees[0] = new Worker("Kate", "Jordan", 30, 10);
    employees[1] = new Worker("Jack", "Peterson", 50, 10);
    employees[2] = new Salesman("Peter", "Brown", 800, 100, 80);
    employees[3] = new Salesman("Antony", "Norton", 1000, 100, 150);
    employees[4] = new Manager("David", "Flynn", 2000, 200, 50);
    employees[5] = new Manager("Marian", "Wood", 1800, 200, 120);
    employees[6] = new Manager("Brent", "Simpson", 2200, 200, 250);

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
