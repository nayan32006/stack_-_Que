#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty()) return false;
                
                char top = st.top();
                if ((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') || 
                    (ch == ']' && top == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
 
    string test1 = "()[]{}";
    string test2 = "(]";
    string test3 = "([{}])";

    cout << "Test 1 (Expected 1): " << sol.isValid(test1) << endl;
    cout << "Test 2 (Expected 0): " << sol.isValid(test2) << endl;
    cout << "Test 3 (Expected 1): " << sol.isValid(test3) << endl;

    return 0;
}