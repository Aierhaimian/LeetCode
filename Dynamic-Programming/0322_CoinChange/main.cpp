#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Recrusive
// Time  Complexity: O(coins_size * amount)
// Space Complexity: O(1)
class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        max_amount = amount + 1;
        int res = coinSearch(coins, amount);
        return res == max_amount ? -1 : res;
    }
private:
    int max_amount; // 组成x元的硬币数量不可能超过x
    int coinSearch(const vector<int> &coins, int amount) {
        if (amount == 0) return 0;

        int res = max_amount;
        for (int coin: coins) {
            if (amount - coin >= 0)
                res = min(res, 1 + coinSearch(coins, amount - coin));
        }

        return res;
    }
};

// Memory Search
// Time  Complexity: O(coins_size * amount)
// Space Complexity: O(amount)
class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        max_amount = amount + 1;
        memo = vector<int>(amount+1, -1);
        int res = coinSearch(coins, amount);
        return res == max_amount ? -1 : res;
    }
private:
    int max_amount; // 组成x元的硬币数量不可能超过x
    vector<int> memo; 
    int coinSearch(const vector<int> &coins, int amount) {
        if (amount == 0) return 0;

        if (memo[amount] != -1) return memo[amount];

        int res = max_amount;
        for (int coin: coins) {
            if (amount - coin >= 0)
                res = min(res, 1 + coinSearch(coins, amount - coin));
        }

        return memo[amount] = res;
    }
};

// Dynamic Programming
// 0-1 knapsack problem
// Time  Complexity: O(coins_size * amount)
// Space Complexity: O(amount)
class Solution3 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, amount + 1);
        memo[0] = 0;

        for (int coin: coins)
            for (int j=coin; j<= amount; j++)
                memo[j] = min(memo[j], 1 + memo[j - coin]);
        return memo[amount] == amount + 1 ? -1 : memo[amount];
    }
};

int main()
{
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout<< Solution1().coinChange(coins1, amount1) << endl;
    // 3

    // ---

    vector<int> coins2 = {2};
    int amount2 = 1;
    cout << Solution2().coinChange(coins2, amount2) << endl;
    // -1

    // ---

    vector<int> coins3 = {2};
    int amount3 = 3;
    cout << Solution3().coinChange(coins3, amount3) << endl;
    // -1

    // ---

    vector<int> coins4 = {2, 5, 10, 1};
    int amount4 = 27;
    cout << Solution2().coinChange(coins4, amount4) << endl;
    // 4

    // ---

    vector<int> coins5 = {186, 419, 83, 408};
    int amount5 = 6249;
    cout << Solution3().coinChange(coins5, amount5) << endl;
    // 20
    return 0;
}

