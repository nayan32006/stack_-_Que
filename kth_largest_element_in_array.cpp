#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(const vector<int>& nums, int k) {
        // Min Heap to maintain top K largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int num : nums) {
            minHeap.push(num);
            
            // Keep heap size exactly k
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element among top (k+1)
            }
        }

        // The root of minHeap contains the Kth largest element
        return minHeap.top();
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    int res1 = sol.findKthLargest(nums1, k1);

    // Test Case 2
    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    int res2 = sol.findKthLargest(nums2, k2);

    cout << "=========================================================" << endl;
    cout << "--- KTH LARGEST ELEMENT IN AN ARRAY (LEETCODE 215) ---" << endl;
    cout << "=========================================================" << endl;
    cout << "Test Case 1 [3, 2, 1, 5, 6, 4], K = 2        -> Result: " << res1 << endl;
    cout << "Test Case 2 [3, 2, 3, 1, 2, 4, 5, 5, 6], K = 4 -> Result: " << res2 << endl;

    return 0;
}