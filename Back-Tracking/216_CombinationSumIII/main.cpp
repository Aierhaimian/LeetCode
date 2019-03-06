#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        generateRes(k, n, 0);
        return res;
    }
private:
    const vector<int> numbers = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> res;
    vector<int> currRes;
    void generateRes(int k, int n, size_t index) {
        if(n == 0 && k == 0) {
            res.push_back(currRes);
            return;
        }

        if(k == 0)
            return;

        for(size_t i=index; i<numbers.size(); i++) {
            if(n>=numbers[i] && k>0) {
                currRes.push_back(numbers[i]);
                generateRes(k-1, n-numbers[i], i+1);
                currRes.pop_back();
            }
        }
        return;
    }
};

void print_vec(const vector<int> &vec) {
    for(auto i: vec)
        cout << i << " ";
    cout << endl;
}


int main(int argc, char **argv)
{
    if(argc < 3) {
        cerr << "Please input k and n" << endl;
        return -1;
    }
    vector<vector<int>> res = Solution().combinationSum3(atoi(argv[1]), atoi(argv[2]));
    
    for(const vector<int> &i: res)
        print_vec(i);
    
    return 0;
}

