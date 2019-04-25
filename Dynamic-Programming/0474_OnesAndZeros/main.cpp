#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// 将问题转化为0-1背包问题：
// 已知N个物品，每个物品包含两个部分，而背包的容量为m/n
// 求在装满背包的前提下能装物品的最大数量
// 动态规划：
// 状态：F(n(x,y), C(m,n)) 考虑将n个物品放入容量为C的背包，使得n最大
// 状态转移：
// F(i(x,y), c(m,n)) = max(F((i-1)(x,y), c(m,n)), 1+F(i(x,y), c(m,n) - i(x, y)))

// Recursive
// Time  Complexity: O(strsLen*abs(m-n)*(m-n > 0 ? m-n : n-m))
// Space Complexity: O(strsLen)
class Solution1 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strsLen = strs.size();

        vector<pair<int, int>> record(strsLen, make_pair(0, 0));
        for (int i=0; i<strsLen; i++) {
            for (int j=0; j<strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    record[i].first ++;
                else
                    record[i].second ++;
            }
        }
        return maxLen(record, strsLen-1, m, n);
    }
private:
    int maxLen(const vector<pair<int, int>> &record, int index, int m, int n) {
        if (index < 0 || (m <= 0 && n <= 0))
            return 0; // 物品装完了或者背包满了

        int res = maxLen(record, index-1, m, n);

        if (m >= record[index].first && n >= record[index].second)
            res = max(res, 1 + maxLen(record, index-1,  m-record[index].first, n-record[index].second));
        else if (m >= record[index].first && record[index].second == 0)
            res = max(res, 1 + maxLen(record, index-1,  m-record[index].first, n));
        else if (n >= record[index].second && record[index].first == 0)
            res = max(res, 1 + maxLen(record, index-1,  m, n-record[index].second));

        return res;
    }
};

// Memory Search
// Time  Complexity: O(strsLen*abs(m-n)*(m-n > 0 ? m-n : n-m))
// Space Complexity: O(strsLen*m*n)
class Solution2 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strsLen = strs.size();

        vector<pair<int, int>> record(strsLen, make_pair(0, 0));
        for (int i=0; i<strsLen; i++) {
            for (int j=0; j<strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    record[i].first ++;
                else
                    record[i].second ++;
            }
        }

        memo = vector<vector<vector<int>>>(strsLen, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        return maxLen(record, strsLen-1, m, n);
    }
private:
    vector<vector<vector<int>>> memo;
    int maxLen(const vector<pair<int, int>> &record, int index, int m, int n) {
        if (index < 0 || (m <= 0 && n <= 0))
            return 0; // 物品装完了或者背包满了

        if (m >= 0 && n >= 0 && memo[index][m][n] != -1)
            return memo[index][m][n];

        int res = maxLen(record, index-1, m, n);

        if (m >= record[index].first && n >= record[index].second)
            res = max(res, 1 + maxLen(record, index-1,  m-record[index].first, n-record[index].second));
        else if (m >= record[index].first && record[index].second == 0)
            res = max(res, 1 + maxLen(record, index-1,  m-record[index].first, n));
        else if (n >= record[index].second && record[index].first == 0)
            res = max(res, 1 + maxLen(record, index-1,  m, n-record[index].second));

        memo[index][m][n] = res;
        return res;
    }
};

// Dynamic Programming
// Time  Complexity: O(strsLen*abs(m-n)*(m-n > 0 ? m-n : n-m))
// Space Complexity: O(strsLen*m*n)
class Solution3 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strsLen = strs.size();

        vector<pair<int, int>> record(strsLen, make_pair(0, 0));
        for (int i=0; i<strsLen; i++) {
            for (int j=0; j<strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    record[i].first ++;
                else
                    record[i].second ++;
            }
        }

        vector<vector<vector<int>>> memo(strsLen, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for (int j=record[0].first; j<=m; j++)
            for (int k=record[0].second; k<=n; k++)
                memo[0][j][k] = 1;

        for (int i=1; i<strsLen; i++)
            for (int j=0; j<=m; j++)
                for (int k=0; k<=n; k++) {
                    memo[i][j][k] = memo[i-1][j][k];
                    if (j >= record[i].first && k >= record[i].second)
                        memo[i][j][k] = max(memo[i][j][k], 1 + memo[i-1][j-record[i].first][k-record[i].second]);
                }

        return memo[strsLen-1][m][n];
    }
};

// Dynamic Programming
// Space optimization
// Time  Complexity: O(strsLen*abs(m-n)*(m-n > 0 ? m-n : n-m))
// Space Complexity: O(2*m*n)
class Solution4 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strsLen = strs.size();

        vector<pair<int, int>> record(strsLen, make_pair(0, 0));
        for (int i=0; i<strsLen; i++) {
            for (int j=0; j<strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    record[i].first ++;
                else
                    record[i].second ++;
            }
        }

        vector<vector<vector<int>>> memo(2, vector<vector<int>>(m+1, vector<int>(n+1, 0)));
        for (int j=record[0].first; j<=m; j++)
            for (int k=record[0].second; k<=n; k++)
                memo[0][j][k] = 1;

        for (int i=1; i<strsLen; i++)
            for (int j=0; j<=m; j++)
                for (int k=0; k<=n; k++) {
                    memo[i%2][j][k] = memo[(i-1)%2][j][k];
                    if (j >= record[i].first && k >= record[i].second)
                        memo[i%2][j][k] = max(memo[i%2][j][k], 1 + memo[(i-1)%2][j-record[i].first][k-record[i].second]);
                }

        return memo[(strsLen-1)%2][m][n];
    }
};

// Dynamic Programming
// Space optimization
// Time  Complexity: O(strsLen*m*n)
// Space Complexity: O(m*n)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strsLen = strs.size();

        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));

        for (int i=0; i<strsLen; i++) {
            pair<int, int> record(make_pair(0, 0));
            for (int j=0; j<strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    record.first ++;
                else
                    record.second ++;
            }

            for (int j=m; j>=record.first; j--)
                for (int k=n; k>=record.second; k--) {
                    memo[j][k] = max (memo[j][k], 1 + memo[j-record.first][k-record.second]);
                }
        }

        return memo[m][n];
    }
};

int main()
{
    vector<string> arr1 = {"10", "0001", "111001", "1", "0"};
    int m1 = 5, n1 = 3;
    cout << Solution().findMaxForm(arr1, m1, n1) << endl;

    vector<string> arr2 = {"10", "0", "1"};
    int m2 = 1, n2 = 1;
    cout << Solution().findMaxForm(arr2, m2, n2) << endl;
    return 0;
}

