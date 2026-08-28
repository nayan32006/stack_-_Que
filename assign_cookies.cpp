#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int childPtr = 0;  
        int cookiePtr = 0; 

        while (childPtr < g.size() && cookiePtr < s.size()) {
            if (s[cookiePtr] >= g[childPtr]) {
                
                childPtr++; 
            }
           
            cookiePtr++;
        }

        
        return childPtr;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> g1 = {1, 2, 3};
    vector<int> s1 = {1, 1};
    int res1 = sol.findContentChildren(g1, s1);

    // Test Case 2
    vector<int> g2 = {1, 2};
    vector<int> s2 = {1, 2, 3};
    int res2 = sol.findContentChildren(g2, s2);

    cout << "=========================================================" << endl;
    cout << "--- LEETCODE 455: ASSIGN COOKIES (GREEDY APPROACH) ---" << endl;
    cout << "=========================================================" << endl;

    cout << "Test Case 1: Children g=[1,2,3], Cookies s=[1,1]   -> Satisfied: " << res1 << endl;
    cout << "Test Case 2: Children g=[1,2],   Cookies s=[1,2,3] -> Satisfied: " << res2 << endl;

    return 0;
}