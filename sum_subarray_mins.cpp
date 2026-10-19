#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long mod = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        long long total_sum = 0;
        for (int i = 0; i < n; i++) {
            long long contribution = (1LL * arr[i] * left[i]) % mod;
            contribution = (contribution * right[i]) % mod;
            total_sum = (total_sum + contribution) % mod;
        }

        return total_sum;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 2, 4};

    int result = sol.sumSubarrayMins(arr);
    cout << "Sum of subarray minimums: " << result << endl;

    return 0;
}