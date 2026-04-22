#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
    }
    
    void push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        cout << "Pushed: " << x << endl;
    }
    
    int pop() {
        if (s1.empty()) return -1;
        int ans = s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        if (s1.empty()) return -1;
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;

    cout << "--- Standard Queue (Push Costly Approach) ---" << endl;
    
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front Element: " << q.peek() << endl; // 10
    cout << "Popped: " << q.pop() << endl;        // 10
    cout << "Next Front: " << q.peek() << endl;   // 20
    
    if(q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}