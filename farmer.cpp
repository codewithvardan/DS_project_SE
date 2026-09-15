#include <iostream>
#include <cstring>
using namespace std;

/* ====================== FARMER MODULE (ARRAY) ====================== */

class Farmer {
private:
    int id;
    char name[50];
    char role[30];         // "Farmer", "Labor", "Supervisor"
    float wagePerDay;
    int daysWorked;

    // Array to store up to 50 farmers
    static Farmer farmerList[50];
    static int farmerCount;

public:
    Farmer() {
        id = 0;
        name[0] = '\0';
        role[0] = '\0';
        wagePerDay = 0;
        daysWorked = 0;
    }

    void input() {
        cout << "Enter Farmer ID: ";
        cin >> id;

        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);

        cout << "Enter Role: ";
        cin.getline(role, 30);

        cout << "Enter Wage Per Day: ";
        cin >> wagePerDay;

        cout << "Enter Days Worked: ";
        cin >> daysWorked;
    }

    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Role: " << role
             << " | Wage/Day: " << wagePerDay
             << " | Days Worked: " << daysWorked
             << " | Total Pay: " << (wagePerDay * daysWorked) << "\n";
    }

    static void addFarmer() {
        if (farmerCount >= 50) {
            cout << "Farmer list is full.\n";
            return;
        }

        farmerList[farmerCount].input();
        farmerCount++;

        cout << "Farmer added.\n";
    }

    static void listFarmers() {
        if (farmerCount == 0) {
            cout << "No farmers available.\n";
            return;
        }

        for (int i = 0; i < farmerCount; i++) {
            farmerList[i].display();
        }
    }

    static Farmer* searchFarmerById(int id) {
        for (int i = 0; i < farmerCount; i++) {
            if (farmerList[i].id == id)
                return &farmerList[i];
        }
        return nullptr;
    }

    static void updateFarmer() {
        int id;
        cout << "Enter Farmer ID to update: ";
        cin >> id;

        Farmer* f = searchFarmerById(id);
        if (!f) {
            cout << "Farmer not found.\n";
            return;
        }

        cout << "Enter new details for this farmer:\n";
        f->input();

        cout << "Farmer updated.\n";
    }

    static void deleteFarmer() {
        int id;
        cout << "Enter Farmer ID to delete: ";
        cin >> id;

        int idx = -1;

        for (int i = 0; i < farmerCount; i++) {
            if (farmerList[i].id == id) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            cout << "Farmer not found.\n";
            return;
        }

        // Shift elements left
        for (int i = idx; i < farmerCount - 1; i++) {
            farmerList[i] = farmerList[i + 1];
        }

        farmerCount--;
        cout << "Farmer deleted.\n";
    }
};

// Define static members for Farmer
Farmer Farmer::farmerList[50];
int Farmer::farmerCount = 0;