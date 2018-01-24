
/*
 *
 * Find the agent with the highest median sales.
 * The median of a set of values is the "one in the middle", such the half
 * of the other values are higher and half of the other values are lower.
 * The median is the simple average of the two values in the middle. For
 * example, in the set 10, 6, 2, 14, 7, 9, the values in the middle are 7
 * and 9. The average of 7 and 9 is 8, so 8 is the median.
 *
 *
 */

#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

const int NUM_AGENTS = 3;
const int NUM_MONTHS = 12;

void printAgentsMonthlySales(int agents[NUM_AGENTS][NUM_MONTHS]);
int compareSales(const void * A, const void * B);
double findMedian(int monthlySales[], int MONTHS);

int main() {

    int agent[NUM_AGENTS][NUM_MONTHS] = {
            {1856, 498, 30924, 87478, 328, 2653, 387, 3754, 387587, 2873, 276, 32},
            {5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 2534},
            {23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
    };

    // Initial arrays
    printAgentsMonthlySales(agent);


    // Sort the arrays
    cout << "Sorting all agents' monthly sales:" << endl;
    for (int j = 0; j < NUM_AGENTS; ++j) {
        qsort(agent, NUM_MONTHS, sizeof(int), compareSales);
    }
    printAgentsMonthlySales(agent);


    // Find the highest median
    double highestMedian = findMedian(agent[0], NUM_MONTHS);
    int agentNum = 0;
    for (int i = 1; i < NUM_AGENTS; ++i) {
        double currentAgentsMedian = findMedian(agent[i], NUM_MONTHS);
        if (currentAgentsMedian > highestMedian) {
            highestMedian = currentAgentsMedian;
            agentNum = i;
        }
    }
    cout << "The highest median is " << highestMedian << "(agent #" << agentNum << ")" << endl;


    return 0;
}


void printAgentsMonthlySales(int agents[NUM_AGENTS][NUM_MONTHS]){
    for (int i = 0; i < NUM_AGENTS; ++i) {
        cout << "Agent #" << i << endl;
        for (int month = 0; month < NUM_MONTHS; ++month) {
            cout << agents[i][month] << " ";
        }
        cout << endl;
    }
    cout << endl;
};

int compareSales(const void * A, const void * B){
    int * agentA = (int *) A;
    int * agentB = (int *) B;
    return *agentA - *agentB;
}

double findMedian(int monthlySales[], int ARRAY_SIZE){

    if (ARRAY_SIZE % 2 == 0){

        int indexOne = ARRAY_SIZE / 2;
        int indexTwo = indexOne + 1;

        return (monthlySales[indexOne] + monthlySales[indexTwo]) / 2;

    }

    int index = (ARRAY_SIZE / 2) + 1;

    return monthlySales[index];
}