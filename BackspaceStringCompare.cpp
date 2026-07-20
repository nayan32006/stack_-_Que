#include <iostream>
#include <string>
#include <stack>

using namespace std;

string processString(string str) {
    stack<char> st;

    for (char ch : str) {
        if (ch != '#') {
            st.push(ch);
        } else if (!st.empty()) {
            st.pop();
        }
    }

    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

bool backspaceCompare(string s, string t) {
    return processString(s) == processString(t);
}

int main() {
    string s = "ab#c", t = "ad#c";
    
    if (backspaceCompare(s, t)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}