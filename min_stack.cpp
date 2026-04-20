#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);


        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {
        int x = st.top();
        st.pop();

        if (x == minSt.top()) {
            minSt.pop();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main() {
    MinStack* myStack = new MinStack();

    myStack->push(-2);
    myStack->push(0);
    myStack->push(-3);

    cout << "Current Min: " << myStack->getMin() << endl; 

    myStack->pop();
    
    cout << "Top Element: " << myStack->top() << endl;   
    cout << "Current Min: " << myStack->getMin() << endl; 

    delete myStack; // Clean up memory
    return 0;
}