/*
 *
 * The purpose of this is to create a template classes with general functions
 * which might be used elsewhere.
 * The case is about students and their records stored in simply linked lists.
 *
 * There're encapsulated get/set functions and data members, helper methods and
 * "factored out" methods such as isValidGrade(). Overload operator =, constructors,
 * destructors.
 *
 * The client code should be fine working with the lists, all memory (de)allocations are hidden
 * in the classes and are automated.
 *
 *
 */

#include <iostream>

using namespace std;


//------------------------------------------------------------ student record class
class studentRecord{
public:
    studentRecord();
    studentRecord(int newGrade, int newID, string newName);

    int grade();
    void setGrade(int newGrade);

    int studentID();
    void setStudentID(int newID);

    string name();
    void setName(string newName);

    string letterGrade();

private:
    int _grade;
    int _studentID;
    string _name;

private:
    bool isValidGrade(int grade);
};


//--------- constructors
studentRecord::studentRecord() {
    setGrade(0);
    setStudentID(-1);
    setName("");
}
studentRecord::studentRecord(int newGrade, int newID, string newName) {
    setGrade(newGrade);
    setStudentID(newID);
    setName(newName);
}

//--------- grade validation
bool studentRecord::isValidGrade(int grade) {
    return (grade >= 0) && (grade <= 100);
}

//--------- get/set grade
int studentRecord::grade() {
    return _grade;
}
void studentRecord::setGrade(int newGrade) {
    if (isValidGrade(newGrade))
        _grade = newGrade;
}

//--------- get/set studentID
int studentRecord::studentID() {
    return _studentID;
}
void studentRecord::setStudentID(int newID) {
    _studentID = newID;
}

//--------- get/set name
string studentRecord::name() {
    return _name;
}
void studentRecord::setName(string newName) {
    _name = newName;
}

//--------- convert grade to letter
string studentRecord::letterGrade() {

    if (!isValidGrade(_grade)) return "ERROR";

    const int NUMBER_CATEGORIES = 11;
    const string GRADE_LETTER[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};
    const int LOWEST_GRADE_SCORE[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};
    int category = 0;
    while(category < NUMBER_CATEGORIES && LOWEST_GRADE_SCORE[category] <= _grade)
        category++;

    return GRADE_LETTER[category - 1];
}


//------------------------------------------------------------ student list class
class studentCollection{
private:
    struct studentNode{
        studentRecord studentData;
        studentNode * next;
    };
public:
    studentCollection();
    ~studentCollection();
    studentCollection(const studentCollection& original);
    void addRecord(studentRecord newStudent);
    studentRecord recordWithNumber(int idNum);
    void removeRecord(int idNum);
    studentCollection& operator=(const studentCollection & rhs);
private:
    typedef studentNode * studentList;
    studentList _listHead;
    void deleteList(studentList &listPtr);
    studentList copiedList(const studentList original);
};


//--------- default constructor / destructor / copy constructor
studentCollection::studentCollection() {
    _listHead = NULL;
}
studentCollection::~studentCollection() {
    deleteList(_listHead);
}
studentCollection::studentCollection(const studentCollection &original) {
    _listHead = copiedList(original._listHead);
}

//--------- add a student record
void studentCollection::addRecord(studentRecord newStudent) {
    studentNode * newNode = new studentNode;
    newNode->studentData = newStudent;
    newNode->next = _listHead; //
    _listHead = newNode; // point head at the new node
}

//--------- find a student record by ID
studentRecord studentCollection::recordWithNumber(int idNum) {

    studentNode * loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum){
        loopPtr = loopPtr->next;
    }

    if (loopPtr == NULL){
        studentRecord dummyRecord(-1, -1, "");
        return dummyRecord;
    } else {
        return loopPtr->studentData;
    }
}

//--------- remove a student record by ID
void studentCollection::removeRecord(int idNum) {
    studentNode * loopPtr = _listHead; // current
    studentNode * trailing = NULL; // previous

    while (loopPtr != NULL && loopPtr->studentData.studentID() != idNum){
        trailing = loopPtr;
        loopPtr = loopPtr->next;
    }

    // special case: the searched element hasn't been found
    if (loopPtr == NULL) return;

    // special case: the searched element is the first
    if (trailing == NULL) _listHead = _listHead->next;
    else trailing->next = loopPtr->next;

    delete loopPtr;
}

//--------- delete student list
void studentCollection::deleteList(studentList &listPtr) {
    while (listPtr != NULL) {
        studentNode * temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

//--------- copy student list
studentCollection::studentList studentCollection::copiedList(const studentList original) {
    if (original == NULL) return NULL;

    // think about all before while loop as a pre-iteration through the new and old lists
    // in other words do some setups
    // focus on the references to the new allocated node(first create a node, then point to that)
    studentList newList = new studentNode;
    //copy first node's data, because for this node we to modify our new list's head pointer
    newList->studentData = original->studentData;

    studentNode * oldLoopPtr = original->next;
    studentNode * newLoopPtr = newList;

    while (oldLoopPtr != NULL) {
        newLoopPtr->next = new studentNode; // create a new node in memory
        newLoopPtr = newLoopPtr->next; // move the newLoopPtr to that new node
        newLoopPtr->studentData = oldLoopPtr->studentData; // copy the data from the node pointed by oldLoopPtr
        oldLoopPtr = oldLoopPtr->next; // move the oldLoopPtr to the next node int he old list
        // p.s. the oldLoopPtr is always a node ahead
    }
    newLoopPtr->next = NULL; // close newList
    return newList;
}

//--------- operator overloading (helps to copy lists)
studentCollection& studentCollection::operator=(const studentCollection &rhs) {
    // checking in case s1 = s1 or s2 = s1 = s1 etc., so we don't delete nodes at all
    if (this != &rhs) {
        // consider s1 = s2
        deleteList(_listHead); // delete s1
        _listHead = copiedList(rhs._listHead); // copy s2 to s1 starting from the head
    }
    return *this;
}


//------------------------------------------------------------
int main() {

    studentCollection s1;
    studentRecord stu3(84, 1152, "Sue");
    studentRecord stu2(75, 4875, "Ed");
    studentRecord stu1(98, 2938, "Todd");
    s1.addRecord(stu3);
    s1.addRecord(stu2);
    s1.addRecord(stu1);
    s1.removeRecord(4875);

    studentCollection s2(s1); // uses copy constructor

    return 0;
}