#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Patient {
public:
    string name;
    int priority; // 1: Serious, 2: Non-Serious, 3: General Checkup

    // Constructor
    Patient(const string& name, int priority) : name(name), priority(priority) {}
};

class PriorityQueue {
private:
    vector<Patient> heap;
public:
    PriorityQueue() {}

    bool isEmpty() const {
        return heap.empty();
    }

    void enqueue(const Patient& patient) {
        heap.push_back(patient);
        push_heap(heap.begin(), heap.end(), [](const Patient& a, const Patient& b) {
            return a.priority > b.priority;
        });
    }

    Patient dequeue() {
        if (isEmpty()) {
            cout << "Priority queue is empty. No patient to dequeue." << endl;
            return Patient("", -1); // Dummy patient
        }
        pop_heap(heap.begin(), heap.end(), [](const Patient& a, const Patient& b) {
            return a.priority > b.priority;
        });
        Patient topPatient = heap.back();
        heap.pop_back();
        return topPatient;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Priority queue is empty. No patients to display." << endl;
            return;
        }
        cout << "Patient List:" << endl;
        for (const Patient& patient : heap) {
            cout << "Name: " << patient.name << " | Priority: " << patient.priority << endl;
        }
    }
};

int main() {
    PriorityQueue pq;

    while (true) {
        cout << "\t\tPatient Management System" << endl;
        cout << "\t\t1. Add Patient" << endl;
        cout << "\t\t2. Serve Patient" << endl;
        cout << "\t\t3. Display Patient list" << endl;
        cout << "\t\t4. Exit" << endl;
        int choice;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name;
                int priority;
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter patient priority (1: Serious, 2: Non-Serious, 3: General Checkup): ";
                cin >> priority;
                pq.enqueue(Patient(name, priority));
                cout << "Patient added to the queue." << endl;
                break;
            }
            case 2: {
                if (!pq.isEmpty()) {
                    Patient currentPatient = pq.dequeue();
                    cout << "Serving patient: " << currentPatient.name << endl;
                } else {
                    cout << "No patients in the queue." << endl;
                }
                break;
            }
            case 3: {
                pq.display();
                break;
            }
            case 4:
                cout << "Thank you for using the Patient Management System." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
