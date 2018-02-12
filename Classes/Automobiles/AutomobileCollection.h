#ifndef EX5_2_AUTOMOBILECOLLECTION_H
#define EX5_2_AUTOMOBILECOLLECTION_H

#include<string>

using std::string;

//------------------------------------------------------------ automobile record class
class automobileRecord{
public:
    automobileRecord();
    automobileRecord(int newYear, string newManufacturer, string newModel);

    int year();
    void setYear(int newYear);

    string manufacturer();
    void setManufacturer(string newManufacturer);

    string model();
    void setModel(string newModel);


private:
    int _year;
    string _manufacturer;
    string _model;
};

//------------------------------------------------------------ automobile list class
class automobileCollection{
private:
    struct automobileNode{
        automobileRecord automobileData;
        automobileNode * next;
    };
public:
    automobileCollection();
    ~automobileCollection();
    automobileCollection(const automobileCollection& original);
    void addRecord(automobileRecord newAutomobile);
    automobileRecord recordWithModel(string model);
    string description(string model);
    void removeRecord(string model);
    int age(string model);
    automobileCollection& operator=(const automobileCollection & rhs);
private:
    typedef automobileNode * automobileList;
    automobileList _listHead;
    void deleteList(automobileList &listPtr);
    automobileList copiedList(const automobileList original);
};

#endif //EX5_2_AUTOMOBILECOLLECTION_H
