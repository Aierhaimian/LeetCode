#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution1 {
public:
    string toLowerCase(string str) {
        for (auto it = str.begin(); it != str.end(); ++it)
            *it = tolower(*it);
        return str;
    }
};

class Solution2 {
public:
    string toLowerCase(string str) {
        for (auto it = str.begin(); it != str.end(); ++it)
        {
            if (*it >= 65 && *it <= 90)
                *it += 32;
        }
        return str;
    }
};

int main()
{
    string res1 = Solution1().toLowerCase("BEST");
    cout << "BEST" << " " << res1 << endl;

    string res2 = Solution2().toLowerCase("BEST");
    cout << "BEST" << " " << res2 << endl;
    return 0;
}

