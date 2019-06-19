#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        istringstream ss(text);
        string prev1, prev2, word; 
        while (ss >> word) {
            if (prev1 == first && prev2 == second)
                res.push_back(word);
            prev1 = prev2;
            prev2 = word;
        }
        return res;
    }
};

int main()
{

    return 0;
}

