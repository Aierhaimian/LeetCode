#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        res.clear();
        generateTime(num, 0, 0, 0);
        return res;
    }
private:
    const vector<int> hours = {1, 2, 4, 8};
    const vector<int> minutes = {1, 2, 4, 8, 16, 32};
    vector<string> res;

    void generateTime(int num, int hour, int minute, int index) {
        if (num == 0 && hour >= 0 && hour <= 11 && minute >= 0 && minute <= 59) {
            if (minute < 10)
                res.push_back(to_string(hour) + ":0" + to_string(minute));
            else
                res.push_back(to_string(hour) + ":" + to_string(minute));

            return;
        }

        for (size_t i=index; i<(hours.size()+minutes.size()); i++) {
            if (i < hours.size()) {
                hour += hours[i];
                if (hour < 12)
                    generateTime(num-1, hour, minute, i+1);
                hour -= hours[i];
            }
            else {
                minute += minutes[i-hours.size()];
                if (minute < 60)
                    generateTime(num-1, hour, minute, i+1);
                minute -= minutes[i - hours.size()];
            }
        }

        return;
    }
};

int main(int args, char **argv)
{
    if (args < 2) {
        cerr << "pls input num." << endl;
        return -1;
    }
    vector<string> vec = Solution().readBinaryWatch(atoi(argv[1]));
    for (auto s: vec)
        cout << s << " ";
    cout << endl;
    
    return 0;
}

