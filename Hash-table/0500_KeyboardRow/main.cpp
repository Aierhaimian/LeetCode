#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> strs = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        unordered_map<char, int> record;
        for (int i=0; i<strs.size(); i++)
            for (const char &c: strs[i])
            {
                record[c] = i; //lower case
                record[c + 'a' - 'A'] = i; // upper case
            }

        vector<string> res;

        for (const string &word: words)
        {
            bool is_valid = true;
            for (int i=1; i<word.size(); i++)
            {
                if (record[word[i]] != record[word[i-1]])
                {
                    is_valid = false;
                    break;
                }
            }
            if (is_valid)
                res.emplace_back(word);
        }

        return res;
    }
};

int main()
{

    return 0;
}

