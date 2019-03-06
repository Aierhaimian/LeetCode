#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        res.clear();
        if(s.empty()) return res;
        generatePalindrome(s);
        return res;
    }
private:
        vector<vector<string>> res;
        vector<string> vs;
        void generatePalindrome(const string &s)
        {
            if(s.size() == 0) {
                if(vs.size() > 0) {
                    res.push_back(vs);
                }
                return;
            }

            for(size_t i=0; i<=s.size(); i++) {
                auto subStr = s.substr(0, i);
                if(isPalindrome(subStr)) {
                    vs.emplace_back(subStr);
                    auto rem = s.substr(i, string::npos);
                    generatePalindrome(rem);
                    vs.pop_back();
                }
            }
            return;
        }

        bool isPalindrome(const string str)
        {
            if(str.size() == 0) return false;

            int i = 0;
            int j = str.size() - 1;

            if(i == j) return true;
            
            while(i < j) {
                if(str[i] != str[j]) return false;
                ++i;
                --j;
            }
            return true;
        }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

