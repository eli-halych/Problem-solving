
/*
 *
 * Use the function qsort() to sort an array of the student struct.
 * First sort it by grade, then sort it again using student ID.
 *
 */


#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct student{
    int grade;
    int studentID;
    string name;
};

int compareByGrade(const void * voidA, const void * voidB);
int compareByID(const void * voidA, const void * voidB);

int main() {

    const int ARRAY_SIZE = 10;
    student studentArray[ARRAY_SIZE] = {
            {87, 10001, "Fred"},
            {28, 10002, "Tom"},
            {100, 10003, "Alistair"},
            {78, 10004, "Sasha"},
            {84, 10005, "Erin"},
            {98, 10006, "Belinda"},
            {75, 10007, "Leslie"},
            {70, 10008, "Candy"},
            {81, 10009, "Aretha"},
            {68, 10010, "Veronica"}
    };


    // Initial array
    cout << "Initial array:" << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << studentArray[i].studentID << " | "
             << studentArray[i].name << " | "
             << studentArray[i].grade << endl;
    }cout << endl;


    // Sort by grade
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareByGrade);
    cout << "Sorted by grade:" << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << studentArray[i].studentID << " | "
             << studentArray[i].name << " | "
             << studentArray[i].grade << endl;
    }cout << endl;


    // Sort by ID
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareByID);
    cout << "Sorted by ID:" << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << studentArray[i].studentID << " | "
             << studentArray[i].name << " | "
             << studentArray[i].grade << endl;
    }cout << endl;

    return 0;
}

// compare function by grade for qsort()
int compareByGrade(const void * voidA, const void * voidB){

    student * studentA = (student *)(voidA);
    student * studentB = (student *)(voidB);

    return (studentA->grade - studentB->grade);

};

// compare function by ID for qsort()
int compareByID(const void * voidA, const void * voidB){

    student * studentA = (student *)(voidA);
    student * studentB = (student *)(voidB);

    return (studentA->studentID - studentB->studentID);

};
