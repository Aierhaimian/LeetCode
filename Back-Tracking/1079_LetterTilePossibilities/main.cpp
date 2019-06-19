#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Backtracking and Permutation, Sorting by Hash Set
// Time  Complexity: O(n! * n!)
// Space Complexity: O(n)
class Solution1 {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        unordered_set<string> set;
        dfs(tiles, 0, "", set);
        return set.size();
    }
private:
    void dfs(const string& tiles, int index, const string& cur_res, unordered_set<string>& set) {
        if (index == tiles.size()) {
            if (cur_res != "") {
                string t = cur_res;
                sort(t.begin(), t.end());
                do {
                    set.insert(t);
                }while(next_permutation(t.begin(), t.end()));
            }
            return ;
        }

        dfs(tiles, index + 1, cur_res + tiles[index], set);
        dfs(tiles, index + 1, cur_res, set);
    }
};

// Counting on the fly, based on frequency of characters
// Time  Complexity: O(n!)
// Space Complexity: O(n)
class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> freq;
        for(char c: tiles)
            freq[c] ++;

        return dfs(freq);
    }

private:
    int dfs(unordered_map<char, int>& freq) {
        int res = 0;
        for (char e = 'A'; e<= 'Z'; e++) {
            if (freq[e]) {
                res ++;
                freq[e] --;
                res += dfs(freq);
                freq[e] ++;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}

