#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if(s.empty()) return res;
        generateIp(s, 0);
        return res;
    }
    
private:
    vector<int> ip;
    vector<string> res;
    void generateIp(const string &s, size_t index) {
        if(index == s.size()) {
            if(ip.size() == 4)
                res.push_back(get_string());
            return;
        }

        if(index == 0) {
            ip.push_back(s[0] - '0');
            generateIp(s, index+1);
        }
        else {
            int next = ip.back()*10 + (s[index] - '0');
            if(next <= 255 && ip.back() != 0) {
                ip.back() = next;
                generateIp(s, index+1);
                ip.back() /= 10;
            }
            if(ip.size() < 4) {
                ip.push_back(s[index] - '0');
                generateIp(s, index+1);
                ip.pop_back();
            }
        }
    }

    string get_string() {
        string str = to_string(ip[0]);
        for(size_t i=1; i<ip.size(); i++)
            str += "." + to_string(ip[i]);
        return str;
    }
};
    
void print_res(const vector<string> &res) {
    for(const string &e: res)
        cout << e << " ";
    cout << endl;
}

int main()
{
    string s1 = "25525511135";
    print_res(Solution().restoreIpAddresses(s1));
    string s2 = "1";
    print_res(Solution().restoreIpAddresses(s2));
    string s3 = "010010";
    print_res(Solution().restoreIpAddresses(s3));
    return 0;
}

