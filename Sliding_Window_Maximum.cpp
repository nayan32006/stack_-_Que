#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        // 1st window 1st step: पहली विंडो के लिए deque तैयार करना
        for(int i = 0; i < k; i++) {
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // 2nd step: बाकी की विंडो के लिए प्रोसेस करना
        for(int i = k; i < nums.size(); i++) {
            // पिछली विंडो का मैक्सिमम रिजल्ट में डालें
            res.push_back(nums[dq.front()]);

            // 1. वो इंडेक्स हटाएं जो अब इस विंडो का हिस्सा नहीं है
            while(dq.size() > 0 && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. छोटे वैल्यूज़ को हटाएं क्योंकि उनका काम खत्म हो गया
            while(dq.size() > 0 && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. नया इंडेक्स जोड़ें
            dq.push_back(i);
        }

        // आखिरी विंडो का मैक्सिमम रिजल्ट में डालें
        res.push_back(nums[dq.front()]);
        
        return res;
    }
};

// VS Code में रन करने के लिए ड्राइवर कोड
int main() {
    Solution sol;
    
    // Example Input
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    cout << "Input Array: ";
    for(int x : nums) cout << x << " ";
    cout << "\nWindow Size: " << k << endl;

    // फंक्शन कॉल
    vector<int> result = sol.maxSlidingWindow(nums, k);

    // रिजल्ट आउटपुट
    cout << "Sliding Window Maximum: ";
    for(int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}