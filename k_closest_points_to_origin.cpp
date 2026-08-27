#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(const vector<vector<int>>& points, int k) {
        
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (const auto& point : points) {
            int x = point[0];
            int y = point[1];
            int distSq = x * x + y * y; 

            maxHeap.push({distSq, point});

            if (maxHeap.size() > k) {
                maxHeap.pop(); 
            }
        }

        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> points1 = {{1, 3}, {-2, 2}};
    int k1 = 1;
    vector<vector<int>> res1 = sol.kClosest(points1, k1);

    // Test Case 2
    vector<vector<int>> points2 = {{3, 3}, {5, -1}, {-2, 4}};
    int k2 = 2;
    vector<vector<int>> res2 = sol.kClosest(points2, k2);

    cout << "=========================================================" << endl;
    cout << "--- K CLOSEST POINTS TO ORIGIN (LEETCODE 973) ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1 [[1,3], [-2,2]], K = " << k1 << " -> Result: [ ";
    for (const auto& pt : res1) {
        cout << "[" << pt[0] << "," << pt[1] << "] ";
    }
    cout << "]" << endl;

    cout << "Test Case 2 [[3,3], [5,-1], [-2,4]], K = " << k2 << " -> Result: [ ";
    for (const auto& pt : res2) {
        cout << "[" << pt[0] << "," << pt[1] << "] ";
    }
    cout << "]" << endl;

    return 0;
}