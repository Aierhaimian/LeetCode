#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Hashing Set
// Time  Complexity: O(len(A) + len(B))
// Space Complexity: O(len(A) + len(B))
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        unordered_set<int> Bset;
        int sumA = 0, sumB = 0;
        for (int a: A) {
            sumA += a;
        }

        for (int b: B) {
            Bset.insert(b);
            sumB += b;
        }

        int sum = (sumA + sumB) / 2;

        for (int a: A) {
            if (Bset.find(sum - (sumA - a)) != Bset.end())
                return {a, sum - (sumA - a)};
        }

        assert(false);

        return {};
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

