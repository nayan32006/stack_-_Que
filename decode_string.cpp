#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int currentNum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(currentNum);
                stringStack.push(currentString);
                currentNum = 0;
                currentString = "";
            } else if (c == ']') {
                int count = countStack.top();
                countStack.pop();

                string prevString = stringStack.top();
                stringStack.pop();

                string repeated = "";
                for (int i = 0; i < count; i++) {
                    repeated += currentString;
                }

                currentString = prevString + repeated;
            } else {
                currentString += c;
            }
        }

        return currentString;
    }
};

int main() {
    Solution sol;

    string s1 = "3[a]2[bc]";
    string s2 = "3[a2[c]]";
    string s3 = "2[abc]3[cd]ef";

    cout << sol.decodeString(s1) << endl;
    cout << sol.decodeString(s2) << endl;
    cout << sol.decodeString(s3) << endl;

    return 0;
}