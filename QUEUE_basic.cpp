#include <iostream>
#include <queue> // Required for using std::queue

using namespace std;

int main() {
    // 1. Declare a queue of integers
    queue<int> myQueue;

    // 2. Add elements to the back of the queue (Enqueue)
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // 3. Access elements
    cout << "Front element: " << myQueue.front() << endl; // Outputs 10
    cout << "Back element: " << myQueue.back() << endl;   // Outputs 30

    // 4. Remove element from the front (Dequeue)
    myQueue.pop(); // Removes 10

    // 5. Check size and if empty
    cout << "New front: " << myQueue.front() << endl;     // Outputs 20
    cout << "Queue size: " << myQueue.size() << endl;     // Outputs 2

    if (!myQueue.empty()) {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}
