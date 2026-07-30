#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } else {
                st.push_back(token);
            }
        }

        string result = "";
        for (const string& dir : st) {
            result += "/" + dir;
        }

        return result.empty() ? "/" : result;
    }
};

int main() {
    Solution sol;

    cout << sol.simplifyPath("/home/") << endl;
    cout << sol.simplifyPath("/home//foo/") << endl;
    cout << sol.simplifyPath("/home/user/Documents/../Pictures") << endl;
    cout << sol.simplifyPath("/../") << endl;
    cout << sol.simplifyPath("/.../a/../b/c/../d/./") << endl;

    return 0;
}