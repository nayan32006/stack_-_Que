#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {
    }
    
    int ping(int t) {
        q.push(t);
        
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        return q.size();
    }
};

int main() {
    RecentCounter* obj = new RecentCounter();
    
    cout << "Ping at 1ms: " << obj->ping(1) << " call(s)" << endl;   
    cout << "Ping at 100ms: " << obj->ping(100) << " call(s)" << endl;
    cout << "Ping at 3001ms: " << obj->ping(3001) << " call(s)" << endl; 
    cout << "Ping at 3002ms: " << obj->ping(3002) << " call(s)" << endl; 

    return 0;
}