#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        stack<int> s;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = s.top();
            }

            s.push(nums2[i]);
        }

        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}