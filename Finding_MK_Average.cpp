#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class MKAverage {
private:
    int m, k;
    queue<int> q; // Sliding window (size m) को मैनेज करने के लिए
    multiset<int> left, mid, right; // तीन हिस्सों में डेटा बांटने के लिए
    long long midSum = 0; // बीच के एलिमेंट्स का टोटल सम

    // Helper: Mid set से Sum मैनेज करते हुए एलिमेंट्स को बैलेंस करना
    void balance() {
        // Left को k एलिमेंट्स तक भरें
        while (left.size() < k && !mid.empty()) {
            int val = *mid.begin();
            midSum -= val;
            left.insert(val);
            mid.erase(mid.begin());
        }
        while (left.size() > k) {
            int val = *left.rbegin();
            mid.insert(val);
            midSum += val;
            left.erase(prev(left.end()));
        }
        // Right को k एलिमेंट्स तक भरें
        while (right.size() < k && !mid.empty()) {
            int val = *mid.rbegin();
            midSum -= val;
            right.insert(val);
            mid.erase(prev(mid.end()));
        }
        while (right.size() > k) {
            int val = *right.begin();
            mid.insert(val);
            midSum += val;
            right.erase(right.begin());
        }
    }

public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        // 1. नया एलिमेंट Queue में डालें
        q.push(num);

        // 2. एलिमेंट को सही सेट में डालें (Temporary logic)
        if (!left.empty() && num <= *left.rbegin()) {
            left.insert(num);
        } else if (!right.empty() && num >= *right.begin()) {
            right.insert(num);
        } else {
            mid.insert(num);
            midSum += num;
        }

        // 3. अगर विंडो m से बड़ी हो गई, तो front वाला एलिमेंट हटाएं
        if (q.size() > m) {
            int old = q.front();
            q.pop();

            if (left.find(old) != left.end() && old <= *left.rbegin()) {
                left.erase(left.find(old));
            } else if (right.find(old) != right.end() && old >= *right.begin()) {
                right.erase(right.find(old));
            } else {
                mid.erase(mid.find(old));
                midSum -= old;
            }
        }

        // 4. हर ऑपरेशन के बाद बैलेंस करें ताकि sizes (k, m-2k, k) रहें
        balance();
    }

    int calculateMKAverage() {
        if (q.size() < m) return -1;
        // Average = sum / (m - 2*k)
        return midSum / (m - 2 * k);
    }
};

int main() {
    MKAverage* obj = new MKAverage(3, 1);
    obj->addElement(3);        // Queue: [3]
    obj->addElement(1);        // Queue: [3, 1]
    cout << "Avg 1: " << obj->calculateMKAverage() << endl; // -1
    obj->addElement(10);       // Queue: [3, 1, 10]
    cout << "Avg 2: " << obj->calculateMKAverage() << endl; // 3
    obj->addElement(5);        // Queue: [1, 10, 5], 3 removed
    cout << "Avg 3: " << obj->calculateMKAverage() << endl; // 5
    return 0;
}