#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA {
    string firstName;
    string lastName;
};

int main() {
    vector<STUDENT_DATA> students;
    ifstream file("StudentData.txt");
    string line;

    while (getline(file, line)) {
        STUDENT_DATA student;
        stringstream ss(line);

        getline(ss, student.lastName, ',');
        ss >> ws;
        getline(ss, student.firstName, ',');

        students.push_back(student);
    }

#ifdef _DEBUG
    for (const STUDENT_DATA& student : students) {
        cout << student.firstName << " " << student.lastName << endl;
    }
#endif

    return 1;
}
