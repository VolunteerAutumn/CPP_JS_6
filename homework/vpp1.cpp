#include <iostream>
#include <string>
using namespace std;

struct date {
	int day;
	int month;
	int year;
};

class Student {
private:
    string FullName;
    date BirthDate;
    string phoneNumber;
    string Country;
    string City;
    string SchoolName;
    int GroupNumber;

public:
    void InitStudent() {
        cout << "Enter full name (First, Middle, Last) >>> ";
        getline(cin, FullName);

        cout << "Enter birth date (day month year) >>> ";
        cin >> BirthDate.day >> BirthDate.month >> BirthDate.year;
        cin.ignore();

        cout << "Enter phone number >>> ";
        getline(cin, phoneNumber);

        cout << "Enter country >>> ";
        getline(cin, Country);

        cout << "Enter city >>> ";
        getline(cin, City);

        cout << "Enter school name >>> ";
        getline(cin, SchoolName);

        cout << "Enter group number >>> ";
        cin >> GroupNumber;
    }
    void DisplayStudent() {
        cout << "Full Name : " << FullName << endl;
        cout << "Birth Date : "
            << (BirthDate.day < 10 ? "0" : "") << BirthDate.day << "/"
            << (BirthDate.month < 10 ? "0" : "") << BirthDate.month << "/"
            << BirthDate.year << endl;

        cout << "Phone Number : " << phoneNumber << endl;
        cout << "Country : " << Country << endl;
        cout << "City : " << City << endl;
        cout << "School Name : " << SchoolName << endl;
        cout << "Group Number : " << GroupNumber << endl;
    }
	// Getters
	string GetFullName() const { return FullName; }
	date GetBirthDate() const { return BirthDate; }
	string GetPhoneNumber() const { return phoneNumber; }
	string GetCountry() const { return Country; }
	string GetCity() const { return City; }
	string GetSchoolName() const { return SchoolName; }
	int GetGroupNumber() const { return GroupNumber; }
	// Setters
	void SetFullName(const string& name) { FullName = name; }
	void SetBirthDate(int day, int month, int year) { BirthDate = { day, month, year }; }
	void SetPhoneNumber(string number) { phoneNumber = number; }
	void SetCountry(const string& country) { Country = country; }
	void SetCity(const string& city) { City = city; }
	void SetSchoolName(const string& school) { SchoolName = school; }
	void SetGroupNumber(int group) { GroupNumber = group; }
};

int main() {
    Student student;
    student.InitStudent();

    cout << "\nStudent Information:\n";
    student.DisplayStudent();

    int option = -1;

    do {
        cout << "\n----- MENU -----\n";
        cout << "1. Update information\n";
        cout << "2. View specific information\n";
        cout << "3. Show full student profile\n";
        cout << "0. Exit\n";
        cout << "Choose >>> ";
        cin >> option;
        cin.ignore();

        if (option == 1) {
            string field;
            cout << "Enter the field you want to update (name, birthdate, phone, country, city, school, group) >>> ";
            getline(cin, field);

            if (field == "name") {
                string name;
                cout << "Enter new full name >>> ";
                getline(cin, name);
                student.SetFullName(name);
            }
            else if (field == "birthdate") {
                int d, m, y;
                cout << "Enter new birth date (day month year) >>> ";
                cin >> d >> m >> y;
                cin.ignore();
                student.SetBirthDate(d, m, y);
            }
            else if (field == "phone") {
                string phone;
                cout << "Enter new phone number >>> ";
                getline(cin, phone);
                student.SetPhoneNumber(phone);
            }
            else if (field == "country") {
                string country;
                cout << "Enter new country >>> ";
                getline(cin, country);
                student.SetCountry(country);
            }
            else if (field == "city") {
                string city;
                cout << "Enter new city >>> ";
                getline(cin, city);
                student.SetCity(city);
            }
            else if (field == "school") {
                string school;
                cout << "Enter new school name >>> ";
                getline(cin, school);
                student.SetSchoolName(school);
            }
            else if (field == "group") {
                int group;
                cout << "Enter new group number >>> ";
                cin >> group;
                cin.ignore();
                student.SetGroupNumber(group);
            }
            else {
                cout << "Invalid field!\n";
            }

            cout << "\nUpdated Student Information:\n";
            student.DisplayStudent();
        }

        else if (option == 2) {
            string field;
            cout << "Enter field to view (name, birthdate, phone, country, city, school, group) >>> ";
            getline(cin, field);

            if (field == "name") {
                cout << "Full Name : " << student.GetFullName() << endl;
            }
            else if (field == "birthdate") {
                date bd = student.GetBirthDate();
                cout << "Birth Date : "
                    << (bd.day < 10 ? "0" : "") << bd.day << "/"
                    << (bd.month < 10 ? "0" : "") << bd.month << "/"
                    << bd.year << endl;
            }
            else if (field == "phone") {
                cout << "Phone Number : " << student.GetPhoneNumber() << endl;
            }
            else if (field == "country") {
                cout << "Country : " << student.GetCountry() << endl;
            }
            else if (field == "city") {
                cout << "City : " << student.GetCity() << endl;
            }
            else if (field == "school") {
                cout << "School Name : " << student.GetSchoolName() << endl;
            }
            else if (field == "group") {
                cout << "Group Number : " << student.GetGroupNumber() << endl;
            }
            else {
                cout << "Invalid field!\n";
            }
        }

        else if (option == 3) {
            cout << "\nFull Student Profile:\n";
            student.DisplayStudent();
        }

        else if (option == 0) {
            cout << "Exiting program... Byeee\n";
        }

        else {
            cout << "Invalid menu option!\n";
        }

    } while (option != 0);

    return 0;
}
