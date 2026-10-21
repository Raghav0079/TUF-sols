// Base class Employee
class Employee {
protected:
    string name;
    int id;

public:

    Employee(string name, int id) {
        this->name = name;
        this->id = id;
    }


    virtual void displayDetails() {
        cout << "Name : " << name << endl;
        cout << "Id : " << id << endl;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:

    Manager(string name, int id, int teamSize)
        : Employee(name, id) {
        this->teamSize = teamSize;
    }

    void displayDetails() override {
        Employee::displayDetails(); // Call to Employee displayDetails
        cout << "Team Size : " << teamSize << endl;
    }
};


class Engineer : public Employee {
private:
    string specialization;

public:

    Engineer(string name, int id, string specialization)
        : Employee(name, id) {
        this->specialization = specialization;
    }

    void displayDetails() override {
        Employee::displayDetails(); // Call to Employee displayDetails
        cout << "Specialization : " << specialization << endl;
    }
};