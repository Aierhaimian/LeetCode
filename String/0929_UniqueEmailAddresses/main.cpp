#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> record;
        for (size_t i=0; i<emails.size(); i++)
        {
            string tmp;
            bool isDot = false;
            for (auto it = emails[i].begin(); it != emails[i].end(); ++it)
            {
                if (*it == '.' && !isDot)
                    continue;
                else if (*it == '+' && !isDot)
                {
                    while (!isDot)
                    {
                        if (*it != '@')
                            ++it;
                        else
                        {
                            tmp += *it;
                            isDot = true;
                        }
                    }
                }
                else
                    tmp += *it;
            }
            record.insert(tmp);
        }
        return record.size();
    }
};

int main()
{
    vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    int res = Solution().numUniqueEmails(emails);
    cout << res << endl;
    return 0;
}

