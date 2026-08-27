#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(const vector<int>& stones) {
        
        priority_queue<int> maxHeap;

        for (int stone : stones) {
            maxHeap.push(stone);
        }

        while (maxHeap.size() > 1) {
            int y = maxHeap.top(); 
            maxHeap.pop();
            
            int x = maxHeap.top();
            maxHeap.pop();

            if (y != x) {
                maxHeap.push(y - x);
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    int res1 = sol.lastStoneWeight(stones1);

    // Test Case 2
    vector<int> stones2 = {1};
    int res2 = sol.lastStoneWeight(stones2);

    cout << "=========================================================" << endl;
    cout << "--- LAST STONE WEIGHT (LEETCODE 1046) ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1 [2, 7, 4, 1, 8, 1] -> Result: " << res1 << endl;
    cout << "Test Case 2 [1]                -> Result: " << res2 << endl;

    return 0;
}