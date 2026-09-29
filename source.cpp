#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
    string email;
};

int main() {
#ifdef PRE_RELEASE
    cout << "Running pre-release version" << endl;
    ifstream file("StudentData_Emails.txt");
#else
    cout << "Running standard version" << endl;
    ifstream file("StudentData.txt");
#endif

    vector<STUDENT_DATA> students;
    string line;

    while (getline(file, line)) {
        STUDENT_DATA student;
        stringstream ss(line);

        getline(ss, student.lastName, ',');
        ss >> ws;
        getline(ss, student.firstName, ',');
#ifdef PRE_RELEASE
        ss >> ws;
        getline(ss, student.email, ',');
#endif

        students.push_back(student);
    }

#ifdef _DEBUG
    for (const STUDENT_DATA& student : students) {
        cout << student.firstName << " " << student.lastName;
#ifdef PRE_RELEASE
        cout << " - " << student.email;
#endif
        cout << endl;
    }
#endif

    return 1;
}
