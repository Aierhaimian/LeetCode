#include <iostream>
#include <vector>

using namespace std;

// Time Limit Exceeded
/// Time Complexity: O(m^n)
/// Space Complexity: O(1)
/*
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> answer;
        for (size_t i=0; i<queries.size(); i++) {
            A[queries[i][1]] += queries[i][0];
            int sum = 0;
            for (size_t j=0; j<A.size(); j++) {
                if (A[j]%2 == 0)
                    sum += A[j];
            }
            answer.push_back(sum);
        }
        return answer;
    }
};*/

/// Maintain sum
/// Time Complexity: O(n + q)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (int i: A) {
            if (abs(i)%2 == 0)
                sum += i;
        }

        vector<int> res;
        for (const vector<int>& q: queries) {
            int x = A[q[1]];
            if (abs(x)%2 == 0) sum -= x;
            A[q[1]] += q[0];
            if (abs(A[q[1]])%2 == 0)
                sum += A[q[1]];
            res.push_back(sum);
        }
        return res;
    }
};

int main()
{
    vector<int> A = {1,2,3,4};
    vector<vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
    vector<int> res = Solution().sumEvenAfterQueries(A, queries);
    for (int i: res)
        cout << i << " ";
    cout << endl;

    return 0;
}

