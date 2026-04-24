// Reverse Polish Notation (RPN), jise Postfix Notation bhi kaha jata hai, ek aisa mathematical notation hai jisme operators (jaise +, -, *, /) apne operands ke baad aate hain.

// Example: 3 + 4 (Infix) ko RPN mein 3 4 + likha jata hai.

// Isse evaluate karne ke liye Stack data structure sabse best application hai.

// 1. Algorithm (Logic)
// Ek empty Stack banayein.

// RPN expression ko left se right scan karein:

// Agar token ek Number hai, to use stack mein push karein.

// Agar token ek Operator hai:

// Stack se do numbers pop karein (pehla pop kiya gaya number b hoga aur doosra a).

// Un par wo operator apply karein (a operator b).

// Result ko wapas stack mein push karein.

// Ant mein, stack mein jo ek akela number bachega, wahi aapka final result hai.4


#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string s : tokens) {
            // Agar token operator hai
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top(); st.pop(); // Pehla pop b
                int a = st.top(); st.pop(); // Doosra pop a

                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else if (s == "/") st.push(a / b);
            } 
            else {
                // Agar number hai, to string se int mein convert karke push karein
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    
    // Example 1: ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) = 9
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Result 1: " << sol.evalRPN(tokens1) << endl;

    // Example 2: ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) = 6
    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Result 2: " << sol.evalRPN(tokens2) << endl;

    return 0;
}


// 3. Dry Run (Kaise kaam kar raha hai?)Input: ["4", "13", "5", "/", "+"]"4": Number hai -> Stack: [4]"13": Number hai -> Stack: [4, 13]"5": Number hai -> Stack: [4, 13, 5]"/": Operator hai:b = 5, a = 1313 / 5 = 2 (Integer division)Stack: [4, 2]"+": Operator hai:b = 2, a = 44 + 2 = 6Stack: [6]Final Result: 64. Complexity AnalysisTime Complexity: $O(n)$, kyunki hum tokens ke array ko sirf ek baar scan kar rahe hain.Space Complexity: $O(n)$, kyunki worst case mein hum saare numbers stack mein store kar sakte hain.