#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
    int id;
    string name, subject_names[4];
    float subject_scores[4], average;
} students[20];

bool sortByName(Student lhs, Student rhs) { return lhs.name > rhs.name; }

bool sortByScore(Student lhs, Student rhs) { return lhs.average > rhs.average; }

int main() {
    cout << "A. REGISTER STUDENTS" << endl << endl;
    for (int i = 0; i < 5; i++) {
        students[i].id = i + 1;
        cout << "Enter student's name" << endl;
        cin >> students[i].name;
        float sum = 0;
        for (int j = 0; j < 4; j++) {
            cout << "\tEnter subject " << j + 1 << endl << "\t";
            cin >> students[i].subject_names[j];
            cout << "\tEnter subject " << j + 1 << " score" << endl << "\t";
            cin >> students[i].subject_scores[j];
            sum += students[i].subject_scores[j];
        }
        students[i].average = (sum / 4); // C. CALCULATE AVERAGE
    }

    cout << endl << endl << "B. STUDENT'S REPORT" << endl << endl << "ID\tNAME\t:\tAVERAGE" << endl;
    for (int i = 0; i < 5; i++)
        cout << students[i].id << "\t" << students[i].name << "\t" << ":\t" << students[i].average << endl;

    sort(students, students + 20, sortByName);
    cout << endl << endl << "D. STUDENTS IN ALPHABETICAL ORDER" << endl << endl << "ID\tNAME\t:\tAVERAGE" << endl;
    for (int i = 4; i >= 0; i--)
        cout << students[i].id << "\t" << students[i].name << "\t" << ":\t" << students[i].average << endl;

    sort(students, students + 20, sortByScore);
    cout << endl << endl << "E. BEST AND POOREST STUDENTS" << endl;
    cout << "Best Student: " << students[0].name << endl << "\tAverage Score: " << students[0].average << endl << endl;
    cout << "Poorest Student: " << students[4].name << endl << "\tAverage Score: " << students[4].average << endl;

    return 0;
}