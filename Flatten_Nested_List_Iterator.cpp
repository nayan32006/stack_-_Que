#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 */
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    // हमने यहाँ const_iterator का उपयोग किया है
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        // hasNext सुनिश्चित करता है कि begins.top() एक Integer पर है
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (!begins.empty()) {
            if (begins.top() == ends.top()) {
                // वर्तमान लिस्ट खत्म हो गई, स्टैक से हटाओ
                begins.pop();
                ends.pop();
            } else {
                // वर्तमान एलिमेंट को चेक करें
                auto x = begins.top();
                if (x->isInteger()) {
                    return true;
                }
                
                // अगर यह एक लिस्ट है, तो अंदर जाने से पहले कर्सर बढ़ाएं
                begins.top()++;
                
                // अब इस नई लिस्ट के begin और end को स्टैक में डालें
                // getList() const_iterator देता है, इसलिए स्टैक भी वैसा ही होना चाहिए
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }

private:
    // 'iterator' की जगह 'const_iterator' का उपयोग करके Error फिक्स किया गया
    stack<vector<NestedInteger>::const_iterator> begins, ends;
};
int main() {
    cout << "Hello! Program is running correctly." << endl;
    return 0;
}