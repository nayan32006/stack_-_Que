#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int calPoints(vector<string>& operations) {
    stack<int> st;

    for (string op : operations) {
        if (op == "+") {
            int top1 = st.top();
            st.pop();
            int top2 = st.top();
            st.push(top1);
            st.push(top1 + top2);
        } 
        else if (op == "D") {
            st.push(2 * st.top());
        } 
        else if (op == "C") {
            st.pop();
        } 
        else {
            st.push(stoi(op));
        }
    }

    int totalSum = 0;
    while (!st.empty()) {
        totalSum += st.top();
        st.pop();
    }

    return totalSum;
}

int main() {
    vector<string> ops = {"5", "2", "C", "D", "+"};
    cout << "Total Points: " << calPoints(ops) << endl;
    return 0;
}