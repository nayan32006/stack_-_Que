#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        // Step 1: Count frequency of each element
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }

        // Step 2: Min Heap to store pairs of {frequency, element}
        // Min Heap keeps the smallest frequency at the top
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for (auto& entry : freqMap) {
            int element = entry.first;
            int count = entry.second;

            minHeap.push({count, element});

            // Maintain heap size to K
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the element with the smallest frequency
            }
        }

        // Step 3: Extract top K elements from heap into result vector
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    vector<int> res1 = sol.topKFrequent(nums1, k1);

    // Test Case 2
    vector<int> nums2 = {1};
    int k2 = 1;
    vector<int> res2 = sol.topKFrequent(nums2, k2);

    cout << "=========================================================" << endl;
    cout << "--- TOP K FREQUENT ELEMENTS (LEETCODE 347) ---" << endl;
    cout << "=========================================================" << endl;
    
    cout << "Test Case 1 [1,1,1,2,2,3], K = " << k1 << " -> Result: [ ";
    for (int num : res1) cout << num << " ";
    cout << "]" << endl;

    cout << "Test Case 2 [1], K = " << k2 << "         -> Result: [ ";
    for (int num : res2) cout << num << " ";
    cout << "]" << endl;

    return 0;
}