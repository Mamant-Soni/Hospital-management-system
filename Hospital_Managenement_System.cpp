#include <iostream>
using namespace std;

// Doctor Class
class Doctor {
private:
    int id;
    string name;
    string specialization;

public:
    // Default Constructor
    Doctor() {
        id = 0;
        name = "Unknown";
        specialization = "General";
    }

    // Parameterized Constructor
    Doctor(int i, string n, string s) {
        id = i;
        name = n;
        specialization = s;
    }

    void setDoctor() {
        cout << "Enter Doctor ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Specialization: ";
        cin >> specialization;
    }

    void displayDoctor() {
        cout << id << "\t" << name << "\t" << specialization << endl;
    }

    string getSpec() {
        return specialization;
    }

    string getName() {
        return name;
    }
};

// Patient Class
class Patient {
private:
    int id;
    string name;
    int age;
    string disease;
    string doctorName;

public:
    // Default Constructor hai 
    Patient() {
        id = 0;
        name = "Unknown";
        age = 0;
        disease = "None";
        doctorName = "Not Assigned";
    }

    // Parameterized Constructor hai 
    Patient(int i, string n, int a, string d, string doc) {
        id = i;
        name = n;
        age = a;
        disease = d;
        doctorName = doc;
    }

    void setPatient(Doctor d[], int dCount) {
        cout << "Enter Patient ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Disease: ";
        cin >> disease;

        // Doctor ke logic assign kiye h 
        doctorName = "Not Assigned";
        for (int i = 0; i < dCount; i++) {
            if (d[i].getSpec() == "General") {
                doctorName = d[i].getName();
                break;
            }
        }
    }
    //display kiya h 
    void displayPatient() {
        cout << id << "\t" << name << "\t" << age << "\t"
             << disease << "\t" << doctorName << endl;
    }
};
// main code yeh h jisme callinge wagera hui h 
int main() {
    Doctor doctors[10];
    Patient patients[10];

    int dCount = 0, pCount = 0;
    int choice;

    do {
        cout << "\n===== HOSPITAL MANAGEMENT =====\n";
        cout << "1. Add Doctor\n";
        cout << "2. View Doctors\n";
        cout << "3. Add Patient\n";
        cout << "4. View Patients\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                doctors[dCount].setDoctor();
                dCount++;
                break;

            case 2:
                cout << "\nDoctors List:\n";
                for (int i = 0; i < dCount; i++) {
                    doctors[i].displayDoctor();
                }
                break;

            case 3:
                patients[pCount].setPatient(doctors, dCount);
                pCount++;
                break;

            case 4:
                cout << "\nPatients List:\n";
                for (int i = 0; i < pCount; i++) {
                    patients[i].displayPatient();
                }
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}