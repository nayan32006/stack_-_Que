#include <iostream>
#include <queue>

using namespace std;

class MovingAverage {
public:
    queue<int> q;
    int size;
    double sum = 0;

    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        // 1. अगर Queue फुल है, तो सबसे पुराने (front) को हटाओ
        if (q.size() == size) {
            sum -= q.front();
            q.pop();
        }
        
        // 2. नए नंबर को Queue में डालो और Sum में जोड़ो
        q.push(val);
        sum += val;
        
        // 3. (Current Sum / Current Elements) वापस करो
        return sum / q.size();
    }
};

int main() {
    // Window Size = 3
    MovingAverage* m = new MovingAverage(3);
    
    cout << m->next(1) << endl;  // Output: 1.0
    cout << m->next(10) << endl; // Output: 5.5
    cout << m->next(3) << endl;  // Output: 4.66
    cout << m->next(5) << endl;  // Output: 6.0 (Window ab [10, 3, 5] hai)
    
    return 0;
}