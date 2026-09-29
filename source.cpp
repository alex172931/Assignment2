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

        getline(ss, student.firstName, ',');
        getline(ss, student.lastName, ',');

        students.push_back(student);
    }

    return 1;
}
