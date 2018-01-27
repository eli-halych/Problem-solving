/*
 *
 * Find 3 quartiles for students' grades and their medians
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// make a type definition of size_type = vectorSize for ease of access
typedef vector<int>::size_type vectorSize;
int median(vectorSize sizeq, vector<int> q, vectorSize midq);

struct student{
    int grade;
    int studentID;
    string name;
};

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

    //declare vectors
    vector<int> q1;
    vector<int> q2;
    vector<int> q3;


    for (int i = 0; i < ARRAY_SIZE; ++i) {
        q2.push_back(studentArray[i].grade);
    }
    // sort the population
    sort(q2.begin(), q2.end());

    //find a middle
    vectorSize sizeq2 = q2.size();
    vectorSize midq2 = sizeq2/2;

    double medianq1, medianq2, medianq3;

    // make sure the middle is the median
    medianq2 = median(sizeq2, q2, midq2);

    // repeat for q1 and q3 vectors
    for (int p = 0; p < midq2; p++){
        q1.push_back(q2[p]);
    }

    //q3
    int q2MidIfOdd;
    if (sizeq2 % 2 ==0){
        q2MidIfOdd = midq2;
    } else {
        q2MidIfOdd = midq2+1;
    }
    for (int q = q2MidIfOdd; q < sizeq2; q++){
        q3.push_back(q2[q]);
    }

    vectorSize sizeq1 = q1.size();
    vectorSize midq1 = sizeq1/2;
    vectorSize sizeq3 = q3.size();
    vectorSize midq3 = sizeq3/2;

    medianq1 = median(sizeq1, q1, midq1);
    medianq3 = median(sizeq3, q3, midq3);

    cout << medianq1 << endl << medianq2 << endl << medianq3 << endl;


    return 0;
}

int median(vectorSize sizeq, vector<int> q, vectorSize midq){
    return sizeq % 2 == 0 ? ((q[midq]+q[midq-1])/2) : q[midq];
}