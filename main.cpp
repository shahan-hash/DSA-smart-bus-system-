#include "BusSystem.h"

int main() {

    BusSystem bus;
    bus.loadFromFile("busdata.txt");

    int choice;
    string src, dest;

    while (true) {

        cout << "\n===== BUS SYSTEM =====\n";
        cout << "1. Show Stops\n";
        cout << "2. Find Route\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            bus.displayStops();
        }

        else if (choice == 2) {
            cout << "Source: ";
            getline(cin, src);
            cout << "Destination: ";
            getline(cin, dest);

            // convert spaces → underscore
            replace(src.begin(), src.end(), ' ', '_');
            replace(dest.begin(), dest.end(), ' ', '_');

            bus.shortestPath(src, dest);
        }

        else if (choice == 3) {
            cout << "Exiting... 🚪\n";
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}