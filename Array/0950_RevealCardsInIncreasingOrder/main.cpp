#include <iostream>
#include <vector>
#include <deque>
#include <algorithm> // sort()
#include <functional> // greater<int>()

using namespace std;

// Simulation with queue
// Time  Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>()); // 将vector由大到小排序

        deque<int> q; // 双端队列
        q.push_back(deck[0]);
        for (size_t i=1; i<deck.size(); i++)
        {
            int back = q.back();
            q.pop_back();
            q.push_front(back);
            q.push_front(deck[i]);
        }

        return vector<int>(q.begin(), q.end());
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

