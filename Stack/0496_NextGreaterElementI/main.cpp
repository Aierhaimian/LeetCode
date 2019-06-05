#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Brute Froce
// Time  Complexity: O(n*m*m)
// Space Complexity: O(n)
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (nums1[i] == nums2[j]) {
                    int k;
                    for (k=j+1; k<n; k++) {
                        if (nums1[i] < nums2[k]) {
                            res.push_back(nums2[k]);
                            break;
                        }
                    }
                    if (k == n) {
                        res.push_back(-1);
                    }
                }
            }
        }
        return res;
    }
};

// stack + unordered_map
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s; // 栈中最后没有弹出的元素没有the next greater number
        unordered_map<int, int> m; // map[x]中存放x的the next greater number，没有即为-1
        for (int n: nums2) {
            while (!s.empty() && s.top() < n) {
                m[s.top()] = n; // 存s.top()对应的the next greater number
                s.pop();
            }
            s.push(n);
        }
        vector<int> res;
        for (int n: nums1) {
            res.push_back(m.count(n) ? m[n] : -1);
        }
        return res;
    }
};

int main()
{

    return 0;
}

