#include <iostream>
#include <string>

using namespace std;

class Patient
{
public:
    string name;
    int priority;
    Patient(const string &name, int priority)
    {
        this->name = name;
        this->priority = priority;
    }
};

class PriorityQueue
{
public:
    vector<Patient> heap;
    int maxSize;

    int parent(int index) const
    {
        return (index - 1) / 2;
    }

    int left(int index) const
    {
        return (2 * index) + 1;
    }

    int right(int index) const
    {
        return (2 * index) + 2;
    }

public:
    PriorityQueue(int size)
    {
        maxSize = size;
    }

    bool isEmpty() const
    {
        return heap.empty();
    }

    void accept()
    {
        Patient patient;
        string s;
        cout << "Enter patient name: ";
        cin >> patient.name;
        cout << "Enter patient priority (S: Serious, NS: Non-Serious, GC: General Checkup): ";
        cin >> s;
        if (s == "S")
        {
            patient.priority = 1;
        }
        if (s == "NS")
        {
            patient.priority = 2;
        }
        if (s == "GC")
        {
            patient.priority = 3;
        }
        enqueue(patient);
        cout << "Patient added to queue." << endl;
    }

    void enqueu(const Patient &patient)
    {
        if (heap.size() == maxSize)
        {
            cout << "Priority queue is full. Cannot enqueue patient." << endl;
            return;
        }

        heap.push_back(patient);
        int index = heap.size() - 1;
        // heap Up
        while (index > 0 && heap[parent(index)].priority > heap[index].priority)
        {
            {
                swap(heap[parent(index)], heap[index]);
                index = parent(index);
            }
        }
    }

    Patient dequeue()
    {
        if (heap.empty())
        {
            cout << "Priority queue is empty. No patient to dequeue." << endl;
            return Patient("", -1); // Dummy patient        }
        }
        Patient patient = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        // Heapify Down
        int index = 0;
        while(true){
            int l = left(index);
            int r = right(index);
            int smallest = index;
            if(l < heap.size() && heap[l].priority < heap[smallest].priority)
                smallest = l;
            if(r < heap.size()  && heap[r].priority < heap[smallest].priority)
                smallest = r;
            if(smallest != index)
            {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }else{
                break;
            }
        }
        return patient;
    }
};