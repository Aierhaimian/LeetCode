#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Memory Search
// ERROR: Time Limit Exceeded
// Time  Complexity: O(|A| * |B|)
// Space Complexity: O(|A| * |B|)
class Solution1 {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        unordered_map<int, vector<int>> Apos, Bpos;
        for (int i=0; i<A.size(); i++)
            Apos[A[i]].push_back(i);
        for (int i=0; i<B.size(); i++)
            Bpos[B[i]].push_back(i);

        vector<vector<int>> memo(A.size(), vector<int>(B.size(), -1));
        return dfs(A, B, 0, 0, Apos, Bpos, memo);
    }
private:
    int dfs(const vector<int> &A, const vector<int> &B, int ai, int bj,
            unordered_map<int, vector<int>> &Apos,
            unordered_map<int, vector<int>> &Bpos,
            vector<vector<int>> memo) {
        if (ai >= A.size() || bj >= B.size())
            return 0;

        if (memo[ai][bj] != -1)
            return memo[ai][bj];

        int res = dfs(A, B, ai+1, bj, Apos, Bpos, memo);
        for (int j: Bpos[A[ai]])
            if (j >= bj)
                res = max(res, 1 + dfs(A, B, ai+1, j+1, Apos, Bpos, memo));
        return memo[ai][bj] = res;
    }
};

// Memory Search
// It's actualy The Longest Common Subsequence Problem
//
// Time  Complexity: O(|A| * |B|)
// Space Complexity: O(|A| * |B|)
class Solution2 {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        memo = vector<vector<int>>(A.size(), vector<int>(B.size(), -1));
        return dfs(A, B, 0, 0, memo);
    }
private:
    vector<vector<int>> memo;
    int dfs(const vector<int> &A, const vector<int> &B,
            int ai, int bj,
            vector<vector<int>> &memo) {
        if (ai >= A.size() || bj >= B.size())
            return 0;

        if (memo[ai][bj] != -1)
            return memo[ai][bj];

        int res = dfs(A, B, ai+1, bj, memo);
        for (int j = bj; j < B.size(); j++) {
            if (A[ai] == B[j])
                res = max(res, 1 + dfs(A, B, ai+1, j+1, memo));
        }
        return memo[ai][bj] = res;
    }
};

// Dynamic Programming
// It's actualy The Longest Common Subsequence Problem
// 2-D Dynamic Programming
// A = [1,2,4], B = [1,4,2]
// memo =
//     0 1 2 3
// -----------
// 0 | 0 0 0 0
// 1 | 0 1 1 1
// 2 | 0 1 1 2
// 3 | 0 1 2 2
//
// Time  Complexity: O(|A| * |B|)
// Space Complexity: O(|A| * |B|)
class Solution3 {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> memo(A.size()+1, vector<int>(B.size()+1, 0));

        for (int i=1; i<=A.size(); i++)
            for (int j=1; j<=B.size(); j++)
                memo[i][j] = max(max(memo[i-1][j], memo[i][j-1]), (A[i-1] == B[j-1])+memo[i-1][j-1]);
        for(int i = 0; i <= A.size(); i ++){
            for(int j = 0; j <= B.size(); j ++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        return memo[A.size()][B.size()];
    }
};

// Dynamic Programming
// It's actualy The Longest Common Subsequence Problem
// 1-D Dynamic Programming
// 
// Time  Complexity: O(|A| * |B|)
// Space Complexity: O(|A| * |B|)
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<int>memo(B.size()+1, 0);
        for (int i=1; i<=A.size(); i++) {
            for (int j=B.size(); j>=1; j--)
                if (A[i-1] == B[j-1])
                    memo[j] = 1 + memo[j-1];
            for (int j=1; j<=B.size(); j++)
                memo[j] = max(memo[j], memo[j-1]);
        }
        return memo[B.size()];
    }
};

int main()
{

    return 0;
}

