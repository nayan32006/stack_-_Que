#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
private:
    vector<int> buffer;
    int front;
    int rear;
    int count;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        buffer.resize(k);
        front = 0;
        rear = k - 1;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        buffer[front] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        buffer[rear] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        count--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        count--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return buffer[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return buffer[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

int main() {
    MyCircularDeque* myCircularDeque = new MyCircularDeque(3);

    cout << (myCircularDeque->insertLast(1) ? "true" : "false") << endl;
    cout << (myCircularDeque->insertLast(2) ? "true" : "false") << endl;
    cout << (myCircularDeque->insertFront(3) ? "true" : "false") << endl;
    cout << (myCircularDeque->insertFront(4) ? "true" : "false") << endl;
    cout << myCircularDeque->getRear() << endl;
    cout << (myCircularDeque->isFull() ? "true" : "false") << endl;
    cout << (myCircularDeque->deleteLast() ? "true" : "false") << endl;
    cout << (myCircularDeque->insertFront(4) ? "true" : "false") << endl;
    cout << myCircularDeque->getFront() << endl;

    delete myCircularDeque;
    return 0;
}