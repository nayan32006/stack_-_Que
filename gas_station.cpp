#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        
        if (totalGas < totalCost) return -1;

        int totalCurrentTank = 0;
        int startIndex = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalCurrentTank += gas[i] - cost[i];

            if (totalCurrentTank < 0) {
                startIndex = i + 1;
                totalCurrentTank = 0;
            }
        }

        return startIndex;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    int res1 = sol.canCompleteCircuit(gas1, cost1);

    // Test Case 2
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    int res2 = sol.canCompleteCircuit(gas2, cost2);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 134: GAS STATION (GREEDY APPROACH) ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1: gas=[1,2,3,4,5], cost=[3,4,5,1,2] -> Start Index: " << res1 << endl;
    cout << "Test Case 2: gas=[2,3,4],     cost=[3,4,3]     -> Start Index: " << res2 << endl;

    return 0;
}