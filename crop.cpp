#include <iostream>
#include <cstring>
using namespace std;

/* ====================== CROP MODULE (ARRAY) ====================== */

class Crop {
private:
    int id;
    char name[50];
    char season[20];        // e.g., "Kharif", "Rabi"
    float expectedYield;    // in quintals
    float actualYield;
    int area;               // in acres

    // Array to store up to 100 crops
    static Crop cropList[100];
    static int cropCount;   // how many crops are actually stored

public:
    // Constructor (default)
    Crop() {
        id = 0;
        name[0] = '\0';
        season[0] = '\0';
        expectedYield = 0;
        actualYield = 0;
        area = 0;
    }

    // Take crop details from user
    void input() {
        cout << "Enter Crop ID: ";
        cin >> id;

        cout << "Enter Crop Name: ";
        cin.ignore();  // ignore newline left in buffer
        cin.getline(name, 50);

        cout << "Enter Season (Kharif/Rabi): ";
        cin.getline(season, 20);

        cout << "Enter Expected Yield (quintals): ";
        cin >> expectedYield;

        cout << "Enter Area (acres): ";
        cin >> area;

        actualYield = 0;  // initially no actual yield
    }

    // Display one crop's details
    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Season: " << season
             << " | Exp. Yield: " << expectedYield
             << " | Act. Yield: " << actualYield
             << " | Area: " << area << " acres\n";
    }

    // Add a new crop to the array
    static void addCrop() {
        if (cropCount >= 100) {
            cout << "Crop list is full.\n";
            return;
        }

        cropList[cropCount].input();
        cropCount++;

        cout << "Crop added successfully.\n";
    }

    // Show all crops
    static void listCrops() {
        if (cropCount == 0) {
            cout << "No crops available.\n";
            return;
        }

        for (int i = 0; i < cropCount; i++) {
            cropList[i].display();
        }
    }

    // Search crop by ID, return pointer if found
    static Crop* searchCropById(int id) {
        for (int i = 0; i < cropCount; i++) {
            if (cropList[i].id == id) {
                return &cropList[i];
            }
        }
        return nullptr;  // not found
    }

    // Update an existing crop by ID
    static void updateCrop() {
        int id;
        cout << "Enter Crop ID to update: ";
        cin >> id;

        Crop* c = searchCropById(id);
        if (!c) {
            cout << "Crop not found.\n";
            return;
        }

        cout << "Enter new details for this crop:\n";
        c->input();  // re-enter all details

        cout << "Crop updated.\n";
    }

    // Delete a crop by ID
    static void deleteCrop() {
        int id;
        cout << "Enter Crop ID to delete: ";
        cin >> id;

        int idx = -1;  // to store index of crop to delete

        // Find the crop in the array
        for (int i = 0; i < cropCount; i++) {
            if (cropList[i].id == id) {
                idx = i;
                break;
            }
        }

        if (idx == -1) {
            cout << "Crop not found.\n";
            return;
        }

        // Shift all elements after idx one step left
        for (int i = idx; i < cropCount - 1; i++) {
            cropList[i] = cropList[i + 1];
        }

        cropCount--;
        cout << "Crop deleted.\n";
    }
};

Crop Crop::cropList[100];
int Crop::cropCount = 0;