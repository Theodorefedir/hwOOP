#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Company {
public:
    string name;
    string owner;
    string phone;
    string address;
    string activity;

    Company() {
        name = "Unknown";
        owner = "Unknown";
        phone = "Unknown";
        address = "Unknown";
        activity = "Unknown";
    }
    Company(string n, string o, string p, string a, string act) : name(n), owner(o), phone(p), address(a), activity(act) {

    }

    void show() {
        cout << "Name: " << name << endl;
        cout << "Owner: " << owner << endl;
        cout << "Phone: " << phone << endl;
        cout << "Address: " << address << endl;
        cout << "Activity: " << activity << endl;
    }
};

class Directory {
private:
    vector<Company> companies;
public:
    void addCompany() {
        Company newCompany;
        cout << "Enter company name: ";
        getline(cin, newCompany.name);
        cout << "Enter owner: ";
        getline(cin, newCompany.owner);
        cout << "Enter phone: ";
        getline(cin, newCompany.phone);
        cout << "Enter address: ";
        getline(cin, newCompany.address);
        cout << "Enter type of activity: ";
        getline(cin, newCompany.activity);

        companies.push_back(newCompany);
        saveToFile();
    }
    void showAll() {
        if (companies.empty()) {
            cout << "Empty\n";
            return;
        }
        for (int i = 0; i < companies.size(); i++) {
            companies[i].show();
        }
    }
    void searchByName(string search) {
        bool found = false;
        for (int i = 0; i < companies.size(); i++) {
            if (companies[i].name == search) {
                companies[i].show();
                found = true;
            }
        }

        if (found == 0) {
            cout << "Nothing found!\n";
        }
    }
    void searchByPhone(string phoneNumber) {
        bool found = false;
        for (int i = 0; i < companies.size(); i++) {
            if (companies[i].phone == phoneNumber) {
                companies[i].show();
                found = true;
            }
        }

        if (found == 0) {
            cout << "Nothing found!\n";
        }
    }
    void saveToFile() {
        ofstream file("directory.txt");
        if (file.is_open()) {
            for (int i = 0; i < companies.size(); i++) {
                file << companies[i].name << endl;
                file << companies[i].owner << endl;
                file << companies[i].phone << endl;
                file << companies[i].address << endl;
                file << companies[i].activity << endl;
            }
            file.close();
        }
    }
};

int main() {
    Directory dr;
    dr.addCompany();
    dr.showAll();
}