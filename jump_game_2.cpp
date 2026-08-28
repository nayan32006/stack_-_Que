#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0; // Already at the end

        int jumps = 0;
        int currentEnd = 0; // End boundary of the current jump range
        int farthest = 0;   // Farthest reachable index from current range

        // We iterate up to n - 2 because if we reach n - 1, we are already at the destination
        for (int i = 0; i < n - 1; i++) {
            // Update the farthest index we can reach from the current index
            farthest = max(farthest, i + nums[i]);

            // GREEDY CHOICE JUSTIFICATION:
            // When we reach the end of the current jump's boundary, 
            // we MUST make a jump to extend our boundary to the farthest reachable point.
            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest; // Shift our boundary to the farthest point

                // Optimization: If current boundary already reaches or exceeds last index, stop
                if (currentEnd >= n - 1) break;
            }
        }

        return jumps;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    int res1 = sol.jump(nums1);

    // Test Case 2
    vector<int> nums2 = {2, 3, 0, 1, 4};
    int res2 = sol.jump(nums2);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 45: JUMP GAME II (GREEDY APPROACH) ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1: nums=[2,3,1,1,4] -> Minimum Jumps: " << res1 << endl;
    cout << "Test Case 2: nums=[2,3,0,1,4] -> Minimum Jumps: " << res2 << endl;

    return 0;
}