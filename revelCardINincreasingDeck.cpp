#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        
        // 1. सबसे पहले पत्तों को छोटे से बड़े क्रम में सॉर्ट करें
        sort(deck.begin(), deck.end());
        
        // 2. Deque का उपयोग करें क्योंकि इसमें दोनों तरफ से काम करना आसान है
        deque<int> dq;
        
        // 3. सबसे बड़ा कार्ड सबसे पहले डालें
        dq.push_front(deck[n - 1]);
        
        // 4. पीछे से शुरू करते हुए गेम को उल्टा (Reverse) सिमुलेट करें
        for (int i = n - 2; i >= 0; i--) {
            // पीछे वाले कार्ड को उठाकर आगे लाएं (Reverse of step 2 of game)
            dq.push_front(dq.back());
            dq.pop_back();
            
            // नया छोटा कार्ड आगे जोड़ें (Reverse of step 1 of game)
            dq.push_front(deck[i]);
        }
        
        // 5. Deque से डेटा निकालकर Vector में डालें
        vector<int> revealed(dq.begin(), dq.end());
        return revealed;
    }
};

// VS Code में टेस्ट करने के लिए Main function
int main() {
    Solution sol;
    
    // Example Input
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    
    vector<int> result = sol.deckRevealedIncreasing(deck);
    
    // Output प्रिंट करना
    cout << "Final Deck Order: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;

    return 0;
}