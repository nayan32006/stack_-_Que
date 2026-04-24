// Circular Queue (जिसे Ring Buffer भी कहा जाता है) एक एडवांस Queue है जो साधारण Queue की सबसे बड़ी समस्या को हल करती है: मेमोरी का वेस्टेज।

// साधारण Queue में, एक बार pop करने के बाद आगे की जगह खाली हो जाती है लेकिन हम उसे दोबारा इस्तेमाल नहीं कर पाते। Circular Queue में, आखिरी पोजीशन वापस पहली पोजीशन से जुड़ी होती है।

// 1. Circular Queue का लॉजिक (The Concept)
// इसमें हम दो पॉइंटर्स (Pointers) का इस्तेमाल करते हैं:

// Front: यह पहले एलिमेंट को ट्रैक करता है।

// Rear: यह आखिरी एलिमेंट को ट्रैक करता है।

// Circular Movement का जादुई फॉर्मूला:
// इंडेक्स को गोल घुमाने के लिए हम Modulo Operator (%) का उपयोग करते हैं:

// Rear = (Rear + 1) % Size

// Front = (Front + 1) % Size



#include <iostream>
#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int size;
    int count; // वर्तमान में कितने एलिमेंट्स हैं, यह ट्रैक करने के लिए

public:
    // 1. Queue को Initialize करें (Size k के साथ)
    MyCircularQueue(int k) {
        data.resize(k);
        head = 0;
        tail = -1;
        size = k;
        count = 0;
    }
    
    // 2. पीछे से एलिमेंट जोड़ें (Enqueue)
    bool enQueue(int value) {
        if (isFull()) return false;
        
        // Tail को सर्कुलर तरीके से आगे बढ़ाएं
        tail = (tail + 1) % size;
        data[tail] = value;
        count++;
        return true;
    }
    
    // 3. आगे से एलिमेंट हटाएं (Dequeue)
    bool deQueue() {
        if (isEmpty()) return false;
        
        // Head को सर्कुलर तरीके से आगे बढ़ाएं
        head = (head + 1) % size;
        count--;
        return true;
    }
    
    // 4. सबसे आगे का एलिमेंट देखें (Front)
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    // 5. सबसे पीछे का एलिमेंट देखें (Rear)
    int Rear() {
        if (isEmpty()) return -1;
        return data[tail];
    }
    
    // 6. चेक करें क्या Queue खाली है
    bool isEmpty() {
        return count == 0;
    }
    
    // 7. चेक करें क्या Queue फुल है
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 */
int main() {
    MyCircularQueue* myCircularQueue = new MyCircularQueue(3);
    
    cout << boolalpha; // true/false प्रिंट करने के लिए
    cout << "enQueue(1): " << myCircularQueue->enQueue(1) << endl; // return True
    cout << "enQueue(2): " << myCircularQueue->enQueue(2) << endl; // return True
    cout << "enQueue(3): " << myCircularQueue->enQueue(3) << endl; // return True
    cout << "enQueue(4): " << myCircularQueue->enQueue(4) << endl; // return False (Full hai)
    
    cout << "Rear: " << myCircularQueue->Rear() << endl;           // return 3
    cout << "isFull: " << myCircularQueue->isFull() << endl;       // return True
    
    cout << "deQueue: " << myCircularQueue->deQueue() << endl;     // return True
    cout << "enQueue(4): " << myCircularQueue->enQueue(4) << endl; // return True
    cout << "Rear: " << myCircularQueue->Rear() << endl;           // return 4

    return 0;
}




// Queue Empty: front == -1

// Queue Full:

// या तो front == 0 और rear == size - 1 हो।

// या फिर rear == front - 1 हो (जब rear घूमकर front के ठीक पीछे आ जाए)।

// Circular Increment: सीधा rear++ करने के बजाय (rear + 1) % size का सोचना चाहिए।

// 4. इसका फायदा क्या है? (Applications)
// Memory Efficiency: साधारण Queue में pop करने के बाद जो जगह खराब हो जाती थी, यहाँ उसे दोबारा इस्तेमाल किया जा सकता है।

// CPU Scheduling: Round Robin Scheduling में इसका इस्तेमाल होता है जहाँ हर प्रोसेस को बराबर समय मिलता है और फिर वे वापस लाइन में लग जाते हैं।

// Traffic System: ट्रैफिक लाइट का टाइमर एक सर्कुलर तरीके से चलता है (Red -> Green -> Yellow -> Red)।