#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Using Custom Class and overloading < operator to sort
// Time  Complexity: O(nlogn)
// Space Complexity: O(n)
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<Log> arr;
        for (int i=0; i<logs.size(); i++) {
            arr.push_back(Log(logs[i], i));
        }

        sort(arr.begin(), arr.end());

        vector<string> res;
        for (const Log &e: arr)
            res.push_back(e.get_s());
        return res;
    }
private:
    class Log{
    public:
        Log(const string &log, int index)
            :s(log), index(index)
        {
            int space = s.find(' ');
            id = s.substr(0, space);
            after = s.substr(space + 1);
            is_letter = isalpha(after[0]);
        }

        bool operator<(const Log &anthor) {
            if (is_letter != anthor.is_letter)
                return is_letter;
            if (is_letter)
                return after == anthor.after ? id < anthor.id : after < anthor.after;
            return index < anthor.index;
        }

        string get_s() const {
            return s;
        }

    private:
        string s;
        int index;
        string id;
        string after;
        bool is_letter;
    };
};

// Using Sort and custom compare lambda function
// Time  Complexity: O(nlogn)
// Space ComplexityL O(1)
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        sort(logs.begin(), logs.end(), [logs](const string &log1, const string &log2) -> bool {
             int space1 = log1.find(' ');
             string id1 = log1.substr(0, space1);
             string after1 = log1.substr(space1+1);

             int space2 = log2.find(' ');
             string id2 = log2.substr(0, space2);
             string after2 = log2.substr(space2+1);

             if (isalpha(after1[0]) != isalpha(after2[0])) {
                return isalpha(after1[0]);
             }

             if (isalpha(after1[0]))
                return after1 == after2 ? id1 < id2 : after1 < after2;
             return find(logs.begin(), logs.end(), log1) < find(logs.begin(), logs.end(), log2);
        });
        return logs;
    }
};

class Solution {

public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        stable_sort(logs.begin(), logs.end(), [](const string& log1, const string& log2) -> bool{
            int space1 = log1.find(' ');
            string id1 = log1.substr(0, space1), after1 = log1.substr(space1 + 1);

            int space2 = log2.find(' ');
            string id2 = log2.substr(0, space2), after2 = log2.substr(space2 + 1);

            if(isalpha(after1[0]) != isalpha(after2[0]))
                return isalpha(after1[0]);

            return isalpha(after1[0]) &&
                   (after1 == after2 ? id1 < id2 : after1 < after2);
        });
        return logs;
    }
};

int main()
{

    return 0;
}

