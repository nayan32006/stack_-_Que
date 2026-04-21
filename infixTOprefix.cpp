#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

// ऑपरेटर की प्राथमिकता (Priority) चेक करने के लिए
int priority(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Infix से Postfix बनाने का फंक्शन
string infixToPostfix(string s) {
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        // अगर ऑपरेंड (A-Z या a-z) है, तो सीधा आउटपुट में डालें
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            res += s[i];
        }
        // अगर '(' है, तो स्टैक में डालें
        else if (s[i] == '(') {
            st.push('(');
        }
        // अगर ')' है, तो '(' मिलने तक सब Pop करें
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        // अगर ऑपरेटर है
        else {
            while (!st.empty() && priority(st.top()) >= priority(s[i])) {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    // बचे हुए ऑपरेटर्स को निकालें
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res;
}

// मुख्य फंक्शन: Infix to Prefix
string infixToPrefix(string s) {
    int n = s.length();

    // Step 1: Reverse the Infix expression
    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }

    string postfix = infixToPostfix(s);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

int main() {
    string exp = "(A-B/C)*(A/K-L)";
    cout << "Infix: " << exp << endl;
    cout << "Prefix: " << infixToPrefix(exp) << endl;

    return 0;
}