#include <iostream>
#include <fstream>
using namespace std;

class Point {
private:
    char label; // from 'A' to 'Z'
    double x, y, z;

public:
    void InitPoint() {
        cout << "Enter point label (A-Z): ";
        cin >> label;
        cout << "Enter x, y, z coordinates: ";
        cin >> x >> y >> z;
    }

    void PrintPoint() const {
        cout << "Point: " << label << "(" << x << "; " << y << "; " << z << ")" << endl;
    }

    double DistanceTo(const Point& other) const {
        return sqrt(
            (x - other.x) * (x - other.x) +
            (y - other.y) * (y - other.y) +
            (z - other.z) * (z - other.z)
        );
    }

    // Getters
    char GetLabel() const { return label; }
    double GetX() const { return x; }
    double GetY() const { return y; }
    double GetZ() const { return z; }

    // Setters (interactive)
    void SetLabel() {
        cout << "Enter new label: ";
        cin >> label;
    }
    void SetX() {
        cout << "Enter new x coordinate: ";
        cin >> x;
    }
    void SetY() {
        cout << "Enter new y coordinate: ";
        cin >> y;
    }
    void SetZ() {
        cout << "Enter new z coordinate: ";
        cin >> z;
    }
};


int main() {
    Point point1, point2;

    cout << "Initialize first point:\n";
    point1.InitPoint();
    cout << "Initialize second point:\n";
    point2.InitPoint();

    int option = -1;

    do {
        cout << "\n";
        point1.PrintPoint();
        point2.PrintPoint();
        cout << "Distance: " << point1.DistanceTo(point2) << endl;

        cout << "\n============ MENU ============\n";
        cout << "1. Change label of point 1\n";
        cout << "2. Change coordinate of point 1\n";
        cout << "3. Change label of point 2\n";
        cout << "4. Change coordinate of point 2\n";
        cout << "5. Save to file\n";
        cout << "0. Exit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
        case 1:
            point1.SetLabel();
            break;

        case 2: {
            int coordOption;
            cout << "Select coordinate (1-x, 2-y, 3-z): ";
            cin >> coordOption;
            if (coordOption == 1) point1.SetX();
            else if (coordOption == 2) point1.SetY();
            else if (coordOption == 3) point1.SetZ();
            else cout << "Invalid coordinate!\n";
            break;
        }

        case 3:
            point2.SetLabel();
            break;

        case 4: {
            int coordOption;
            cout << "Select coordinate (1-x, 2-y, 3-z): ";
            cin >> coordOption;
            if (coordOption == 1) point2.SetX();
            else if (coordOption == 2) point2.SetY();
            else if (coordOption == 3) point2.SetZ();
            else cout << "Invalid coordinate!\n";
            break;
        }

        case 5: {
            ofstream outFile("points.txt");
            if (outFile.is_open()) {
                outFile << "Point 1: " << point1.GetLabel()
                    << "(" << point1.GetX() << "; "
                    << point1.GetY() << "; "
                    << point1.GetZ() << ")\n";

                outFile << "Point 2: " << point2.GetLabel()
                    << "(" << point2.GetX() << "; "
                    << point2.GetY() << "; "
                    << point2.GetZ() << ")\n";

                cout << "Saved to points.txt\n";
                outFile.close();
            }
            else {
                cout << "Error opening file!\n";
            }
            break;
        }

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid option! Try again.\n";
        }

    } while (option != 0);

    return 0;
}

