#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Calculate the gcd of all frequency
// Time  Complexity: O(nlogn)
// Space Complexity: O(1)
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) return false;
        if (deck.size() == 2 && deck[0] == deck[1]) return true;
        
        unordered_map<int, int> record;
        for (int i: deck)
            record[i] += 1;

        int g = -1;
        for (const pair<int, int>& p: record)
            if (g == -1) g = p.second;
            else g = gcd(g, p.second);

        return g > 1;
    }
private:
    int gcd(int a, int b)
    {
        if (a < b) swap(a, b);

        if (a % b == 0) return b;

        return gcd(b, a%b);
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

