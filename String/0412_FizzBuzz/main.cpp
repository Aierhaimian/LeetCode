#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res;
        if (n == 0) return res;
        for (int i=1; i<n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                res.push_back("FizzBuzz");
                continue;
            }
            if (i % 3 == 0) {
                res.push_back("Fizz");
                continue;
            }
            if (i % 5 == 0) {
                res.push_back("Buzz");
                continue;
            }
            res.push_back(to_string(i));
        }
        return res;
    }
};

int main()
{

    return 0;
}

