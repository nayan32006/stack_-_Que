#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int countLessEqual(const vector<vector<int>>& matrix, int mid, int n) {
        int count = 0;
        int row = n - 1;
        int col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += (row + 1);
                col++; 
            } else {
                row--; 
            }
        }
        return count;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];               
        int high = matrix[n - 1][n - 1];     
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countLessEqual(matrix, mid, n) >= k) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1; 
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<vector<int>> matrix1 = {
        {1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k1 = 8;
    int res1 = sol.kthSmallest(matrix1, k1);

    // Test Case 2
    vector<vector<int>> matrix2 = {
        {-5}
    };
    int k2 = 1;
    int res2 = sol.kthSmallest(matrix2, k2);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 378: KTH SMALLEST IN SORTED MATRIX ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1 (k=8) -> 8th Smallest Element: " << res1 << endl;
    cout << "Test Case 2 (k=1) -> 1st Smallest Element: " << res2 << endl;

    return 0;
}