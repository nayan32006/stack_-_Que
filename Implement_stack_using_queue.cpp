#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> q1, q2;

    MyStack() {
    }
    
    void push(int x) {
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q1.push(x);

        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        cout << "Pushed: " << x << endl;
    }
    
    int pop() {
        if (q1.empty()) return -1;
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int peek() {
        if (q1.empty()) return -1;
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack s;

    cout << "--- Standard stack (Push Costly Approach) ---" << endl;
    
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Front Element: " << s.peek() << endl; // 10
    cout << "Popped: " << s.pop() << endl;        // 10
    cout << "Next Front: " << s.peek() << endl;   // 20
    
    if(s.empty()) {
        cout << "stack is empty" << endl;
    } else {
        cout << "stack is not empty" << endl;
    }

    return 0;
}