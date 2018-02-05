/*
 *
 * Write a function removeRecord that takes a pointer to a studentCollection and a
 * student number and that removes the record with that student number from
 * the collection.
 *
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

struct listNode {
    int studentNum;
    int grade;
    listNode * next;
};
typedef listNode * studentCollection;

void addRecord(studentCollection& sc, int stuNum, int gr);
void removeRecord(studentCollection& sc, int stuNum);
void outputLinkedList(studentCollection& sc);


int main() {

    studentCollection sc;

    outputLinkedList(sc);

    addRecord(sc, 0001, 5);
    addRecord(sc, 0002, 4);
    addRecord(sc,0003, 3);
    outputLinkedList(sc);

    removeRecord(sc, 0002); //PROBLEM
    outputLinkedList(sc);

    return 0;
}

void addRecord(studentCollection& sc, int stuNum, int gr) {

    listNode * newNode = new listNode;
    newNode->studentNum = stuNum;
    newNode->grade = gr;
    newNode->next = sc;
    sc = newNode;

    cout << "The student " << sc->studentNum << " with the grade " << sc->grade << " has been added." << endl;

}

void removeRecord(studentCollection& sc, int stuNum){


    listNode * current = sc;
    listNode * next; // aka previous visited

    while (current != NULL){
        if (current->studentNum == stuNum){
            cout << "The student " << current->studentNum << " will be removed." << endl;
            next->next = current->next;
            break;
        }
        else {
            next = current;
            current = current->next;
        }
    }


}

void outputLinkedList(studentCollection& sc){

    listNode * ptr = sc;

    while (ptr != NULL){
        cout << "Student " << ptr->studentNum << endl;
        cout << "Grade " << ptr->grade << endl;
        cout << endl;

        ptr = ptr->next;
    }
}