#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Brute Force
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

        for (size_t i=2; i<deck.size(); i++)
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

