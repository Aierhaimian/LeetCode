#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        q.push(t);

        while (t-3000 > q.front())
            q.pop();
        return q.size();
    }
private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main()
{

    return 0;
}

