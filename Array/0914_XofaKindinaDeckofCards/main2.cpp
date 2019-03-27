#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Brute Force
// But only iterate from 2 to the minFreq
// Time  Complexity: O(n^2)
// Space Complexity: O(1)
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) return false;
        if (deck.size() == 2 && deck[0] == deck[1]) return true;
        
        unordered_map<int, int> record;
        for (int i: deck)
            record[i] += 1;

        int minFreq = INT_MAX;
        for (const pair<int, int>& p: record)
            minFreq = min(minFreq, p.second);

        for (int i=2; i<=minFreq; i++)
        {
            bool ok = true;
            for (const pair<int, int>& p: record)
            {
                if (p.second%i)
                {
                    ok = false;
                    break;
                }
            }
            if (ok) return true;
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

