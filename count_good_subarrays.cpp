#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> last_zero(32, -1);

        for (int r = 0; r < n; ++r) {
            // Update last seen position of 0 for each bit
            for (int b = 0; b < 32; ++b) {
                if ((nums[r] & (1U << b)) == 0) {
                    last_zero[b] = r;
                }
            }

            if (nums[r] == 0) continue;

            // Find the smallest left index where Bitwise AND remains > 0
            int min_l = r;
            for (int b = 0; b < 32; ++b) {
                if ((nums[r] & (1U << b)) != 0) {
                    min_l = min(min_l, last_zero[b] + 1);
                }
            }

            ans += (r - min_l + 1);
        }

        return ans;
    }
};

int main() {
    int n;
    cout << "Enter array size: ";
    if (!(cin >> n) || n <= 0) return 0;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    long long ans = sol.countGoodSubarrays(nums);

    cout << "Number of Good Subarrays: " << ans << endl;

    return 0;
}