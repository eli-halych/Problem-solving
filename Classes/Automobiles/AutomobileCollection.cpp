#include<iostream>
#include<time.h>
#include "AutomobileCollection.h"

using std::to_string;





//------------------------------------------------------------ automobile record class

//--------- constructors
automobileRecord::automobileRecord() {
    setYear(-1);
    setManufacturer("");
    setModel("");
}
automobileRecord::automobileRecord(int newYear, string newManufacturer, string newModel) {
    setYear(newYear);
    setManufacturer(newManufacturer);
    setModel(newModel);
}

//--------- get/set year
int automobileRecord::year() {
    return _year;
}
void automobileRecord::setYear(int newYear) {
    _year = newYear;
}

//--------- get/set manufacturer
string automobileRecord::manufacturer() {
    return _manufacturer;
}
void automobileRecord::setManufacturer(string newManufacturer) {
    _manufacturer = newManufacturer;
}

//--------- get/set model
string automobileRecord::model() {
    return _model;
}
void automobileRecord::setModel(string newModel) {
    _model = newModel;
}







//------------------------------------------------------------ automobile list class

//--------- default constructor / destructor / copy constructor
automobileCollection::automobileCollection() {
    _listHead = NULL;
}
automobileCollection::~automobileCollection() {
    deleteList(_listHead);
}
automobileCollection::automobileCollection(const automobileCollection &original) {
    _listHead = copiedList(original._listHead);
}

//--------- add an automobile record
void automobileCollection::addRecord(automobileRecord newAutomobile) {
    automobileNode * newNode = new automobileNode;
    newNode->automobileData = newAutomobile;
    newNode->next = _listHead; //
    _listHead = newNode; // point head at the new node
}

//--------- find an automobile record by model
automobileRecord automobileCollection::recordWithModel(string model) {

    automobileNode * loopPtr = _listHead;
    while (loopPtr != NULL && loopPtr->automobileData.model() != model){
        loopPtr = loopPtr->next;
    }

    if (loopPtr == NULL){
        automobileRecord dummyRecord(-1, "", "");
        return dummyRecord;
    } else {
        return loopPtr->automobileData;
    }
}

//--------- remove an automobile record by model
void automobileCollection::removeRecord(string model) {
    automobileNode * loopPtr = _listHead; // current
    automobileNode * trailing = NULL; // previous

    while (loopPtr != NULL && loopPtr->automobileData.model() != model){
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

//--------- delete automobile list
void automobileCollection::deleteList(automobileList &listPtr) {
    while (listPtr != NULL) {
        automobileNode * temp = listPtr;
        listPtr = listPtr->next;
        delete temp;
    }
}

//--------- copy automobile list
automobileCollection::automobileList automobileCollection::copiedList(const automobileList original) {
    if (original == NULL) return NULL;

    // some setups
    automobileList newList = new automobileNode;
    newList->automobileData = original->automobileData;
    automobileNode * oldLoopPtr = original->next;
    automobileNode * newLoopPtr = newList;

    // actual copying
    while (oldLoopPtr != NULL) {
        newLoopPtr->next = new automobileNode; // create a new node in memory
        newLoopPtr = newLoopPtr->next; // move the newLoopPtr to that new node
        newLoopPtr->automobileData = oldLoopPtr->automobileData; // copy the data from the node pointed by oldLoopPtr
        oldLoopPtr = oldLoopPtr->next; // move the oldLoopPtr to the next node int he old list
        // p.s. the oldLoopPtr is always a node ahead
    }
    newLoopPtr->next = NULL; // close newList
    return newList;
}

//--------- operator overloading (helps to copy lists)
automobileCollection& automobileCollection::operator=(const automobileCollection &rhs) {
    // checking in case c1 = c1 or c2 = c1 = c1 etc., so we don't delete nodes at all
    if (this != &rhs) {
        // consider c1 = c2
        deleteList(_listHead); // delete c1
        _listHead = copiedList(rhs._listHead); // copy c2 to c1 starting from the head
    }
    return *this;
}

string automobileCollection::description(string model) {
    automobileRecord record = recordWithModel(model);

    if (record.year() == -1) return model+" not found.";
    else return to_string(record.year())+"   "+record.manufacturer()+"   "+record.model();
}

int automobileCollection::age(string model) {
    time_t t = time(0);
    struct tm* now = localtime(&t);

    return (now->tm_year + 1900) - recordWithModel(model).year();

}

