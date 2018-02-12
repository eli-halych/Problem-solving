/*
 *
 *   For our automobile class from the previous exercise, add a support method that
 *   returns a complete description(I) of the automobile object as a formatted string,
 *   such as, "1957 Chevrolet Impala". Add a second support method that returns
 *   the age(II) of the automobile in years.
 *
 */

#include <iostream>
#include "AutomobileCollection.h"

int main() {

    // Create a list
    automobileCollection c1;
    //Create cars
    automobileRecord car1(2012, "Tesla", "Model S");
    automobileRecord car2(2015, "Tesla", "Model X");
    automobileRecord car3(2017, "Tesla", "Model 3");
    // Add the cars to the list
    c1.addRecord(car1);
    c1.addRecord(car2);
    c1.addRecord(car3);
    // Remove Model X
    c1.removeRecord("Model X");

    // Get the description of a model (I)
    std::cout << "Description of Model X: " << c1.description("Model X") << std::endl;
    std::cout << "Description of Model S: " << c1.description("Model S") << std::endl;

    // Find out the age of a model (II)
    std::cout << "Tesla Model X is " << c1.age("Model S")  << " years old" << std::endl;

    // Uses copy constructor
    automobileCollection s2(c1);

    return 0;
}
