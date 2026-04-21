#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0); 
        stack<int> s; 
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top() - i; 
            }
            s.push(i);
        }
        
        return ans;
    }
};
void printResult(int exampleNum, vector<int>& input, vector<int>& output) {
    cout << "--- Example " << exampleNum << " ---" << endl;
    cout << "Input:  ";
    for(int x : input) cout << x << " ";
    cout << "\nOutput: ";
    for(int x : output) cout << x << " ";
    cout << "\n\n";
}

int main() {
    Solution sol;

    vector<int> temp1 = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res1 = sol.dailyTemperatures(temp1);
    printResult(1, temp1, res1);

    vector<int> temp2 = {30, 40, 50, 60};
    vector<int> res2 = sol.dailyTemperatures(temp2);
    printResult(2, temp2, res2);
    return 0;
}