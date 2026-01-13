#include <iostream>
using namespace std;

class Student {
protected:
    string firstName;
    string lastName;
    int group;
public:
    Student() {
        firstName = "Unknown";
        lastName = "Unknown";
        group = 0;
    }
    Student(string fn, string ln, int gp): firstName{fn},lastName{ln}, group{gp}{}
    virtual void info() {
        cout << "Student\n";
    }
    virtual ~Student() {
        cout << "Student was deleted\n";
    }
};
class Aspirant :public Student {
private:
    string topic;
public:
    Aspirant(string fn, string ln, int gp, string topic) :Student(fn, ln, gp) {
        this->topic = topic;
    }
    void info() override {
        cout << "Aspirant\n";
    }
    ~Aspirant() override{
        cout << "Aspirant was deleted\n";
    }
};

class Passport {
protected:
    string firstName;
    string lastName;
    string dateOfBirth;
public:
    Passport() {
        firstName = "Unknown";
        lastName = "Unknown";
        dateOfBirth = "Unknown";
    }
    Passport(string fn, string ln, string dof) : firstName{ fn }, lastName{ ln }, dateOfBirth{ dof } {}
    virtual void info() {
        cout << "Passport\n";
    }
    virtual ~Passport() {
        cout << "Pasport was deleted\n";
    }
};
class ForeignPassport :public Passport {
private:
    string visa;
    string country;
public:
    ForeignPassport(string fn, string ln, string dof, string visa, string country) :Passport(fn, ln, dof) {
        this->visa = visa;
        this->country = country;
    }
    void info() override {
        cout << "ForeignPassport\n";
    }
    ~ForeignPassport() override {
        cout << "ForeignPassport was deleted\n";
    }
};

class Transport {
protected:
    double speed;
    double costKm;
public:
    Transport() {
        speed = 3.45;
        costKm = 56;
    }
    Transport(double v, double ck):speed{v},costKm{ck}{}
    virtual double calculateTime(double distance) const {
        return distance / speed;
    }
    virtual double calculateCost(double distance) const {
        return distance * costKm;
    }
    virtual void info() {
        cout << "Transport\n";
    }
    virtual ~Transport() {
        cout << "deleted\n";
    }
};
class Car : public Transport {
public:
    Car() : Transport(880, 587) {}
    Car(double v, double ck) : Transport(v, ck) {}
    void info() override {
        cout << "Car\n";
    }
    ~Car() override {
        cout << "Car was deleted\n";
    }
};

class Bicycle : public Transport {
public:
    Bicycle() : Transport(1567, 0.05) {}
    Bicycle(double v, double ck) : Transport(v, ck) {}
    void info() override {
        cout << "Bicycle\n";
    }
    ~Bicycle() override {
        cout << "Bicycle was deleted\n";
    }
};

class Cart : public Transport {
public:
    Cart() : Transport(1087, 3987) {}
    Cart(double v, double ck) : Transport(v, ck) {}
    void info () override {
        cout << "Cart\n";
    }
    ~Cart() override {
        cout << "Cart was deleted\n";
    }
};

int main() {
    Aspirant a1("John", "Snow", 789, "C++");
    a1.info();
    ForeignPassport fp1("Johan", "Lol", "575757", "5757567", "UK");
    Transport* transports[] = { new Car(), new Bicycle(), new Cart() };
    for (int i = 0; i < 3; i++) {
        Transport* t = transports[i];
        t->info();
        delete t;
        transports[i] = nullptr;
    }

    return 0;
}
