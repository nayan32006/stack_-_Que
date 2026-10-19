#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class StockSpanner {
private:
    stack<pair<int, int>> st;

public:
    StockSpanner() {}
    
    int next(int price) {
        int current_span = 1;

        while (!st.empty() && st.top().first <= price) {
            current_span += st.top().second;
            st.pop();
        }

        st.push({price, current_span});
        return current_span;
    }
};

int main() {

    StockSpanner stockSpanner;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    for (int price : prices) {
        cout << "Price: " << price << " \t--> Span: " << stockSpanner.next(price) << endl;
    }

    return 0;
}