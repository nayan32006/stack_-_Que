// ______________________________________________________________________________________________________________
// |//||  Feature,       ||    Stack,                    ||   Queue                      ||    Combo (Deque)     | 
// |_____________________________________________________________________________________________________________|_
// |//|| Logic,          ||    LIFO (Last-In First-Out), ||   FIFO (First-In First-Out), ||    Both LIFO & FIFO  |
// |_____________________________________________________________________________________________________________|_
// |//||  Main End,      ||    Top,                      ||   Front & Rear,              ||    Both Front & Rear | 
// |_____________________________________________________________________________________________________________|_
// |//||  C++ Header,    ||    <stack>,                  ||   <queue>,                   ||   <deque>            | 
// |_____________________________________________________________________________________________________________|_

// Logic:
// Queue से सारे एलिमेंट्स निकालो और Stack में push करो। (इससे ऑर्डर पलट जाएगा)।

// अब Stack से सारे एलिमेंट्स निकालो और वापस Queue में push करो।

// Full C++ Code Example:
// यह कोड दिखाता है कि कैसे Stack और Queue मिलकर एक टास्क पूरा करते हैं।

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void reverseQueue(queue<int>& q) {
    stack<int> s;

    // Step 1: Queue -> Stack (Transfer)
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Stack -> Queue (Reverse Transfer)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

void display(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Original Queue: ";
    display(q);

    reverseQueue(q);

    cout << "Reversed Queue: ";
    display(q);

    return 0;
}