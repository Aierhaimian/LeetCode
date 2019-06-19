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
    string toGoatLatin(string S) {
        string res;
        istringstream ss(S);
        int index = 1;
        string word;
        while (ss >> word) {
            if (word[0] != 'a' && word[0] != 'A' &&
                word[0] != 'e' && word[0] != 'E' &&
                word[0] != 'i' && word[0] != 'I' &&
                word[0] != 'o' && word[0] != 'O' &&
                word[0] != 'u' && word[0] != 'U') {
                word.append(word, 0, 1);
                word.erase(word.begin(), word.begin()+1);
            }

            word.append("ma");
            for (int i=index; i>0; --i)
                word.append("a");

            if (index == 1)
                res = word;
            else {
                res.append(" ");
                res.append(word);
            }
            ++ index;
        }
        return res;
    }
};

int main()
{

    return 0;
}

