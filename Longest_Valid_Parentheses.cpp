#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        // शुरुआत में -1 डालना जरूरी है ताकि पहली जोड़ी की लंबाई सही आए
        st.push(-1);
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                // '(' का इंडेक्स स्टैक में पुश करें
                st.push(i);
            } else {
                // ')' मिलने पर पिछले इंडेक्स को निकालें
                st.pop();

                if (st.empty()) {
                    // अगर खाली है, तो वर्तमान इंडेक्स को नया बेस/बैरियर बनाएं
                    st.push(i);
                } else {
                    // वर्तमान इंडेक्स और स्टैक के टॉप के बीच की दूरी ही लंबाई है
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    
    // टेस्ट केसेस
    string s1 = "(()";
    cout << "Input: " << s1 << " -> Output: " << sol.longestValidParentheses(s1) << endl; // Output: 2

    string s2 = ")()())";
    cout << "Input: " << s2 << " -> Output: " << sol.longestValidParentheses(s2) << endl; // Output: 4

    string s3 = "";
    cout << "Input: empty -> Output: " << sol.longestValidParentheses(s3) << endl; // Output: 0

    return 0;
}

// Time Complexity:  O(n) — हम स्ट्रिंग को सिर्फ एक बार स्कैन करते हैं।
// Space Complexity: O(n) — स्टैक में इंडेक्स स्टोर करने के लिए।