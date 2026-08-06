#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int a : asteroids) {
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && a < 0) {
                if (abs(st.back()) < abs(a)) {
                    st.pop_back();
                } else if (abs(st.back()) == abs(a)) {
                    st.pop_back();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(a);
            }
        }

        return st;
    }
};

int main() {
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> asteroids2 = {8, -8};
    vector<int> asteroids3 = {10, 2, -5};

    Solution sol;

    vector<int> res1 = sol.asteroidCollision(asteroids1);
    vector<int> res2 = sol.asteroidCollision(asteroids2);
    vector<int> res3 = sol.asteroidCollision(asteroids3);

    auto printResult = [](const vector<int>& res) {
        cout << "[ ";
        for (int x : res) cout << x << " ";
        cout << "]\n";
    };

    printResult(res1);
    printResult(res2);
    printResult(res3);

    return 0;
}