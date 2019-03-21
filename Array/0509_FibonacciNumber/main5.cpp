#include <iostream>
#include <vector>

// Binets Method
// Time  Complexity: O(logn)
// space Complexity: O(logn)
class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1) return 1;

        std::vector<std::vector<int>> base = {{1,1}, {1,0}};

        return matrix_pow(base, N-1)[0][0];

    }
private:
    std::vector<std::vector<int>> matrix_pow(const std::vector<std::vector<int>>& m, int n)
    {
        if (n == 1) return m;

        std::vector<std::vector<int>> t = matrix_pow(m, n/2);
        std::vector<std::vector<int>> res = matrix_multiply(t, t);
        if (n%2)
            return matrix_multiply(res, m);
        return res;

    }

    std::vector<std::vector<int>> matrix_multiply(const std::vector<std::vector<int>> &m1,
                                                  const std::vector<std::vector<int>> &m2)
    {
        std::vector<std::vector<int>> res(2, std::vector<int>(2,0));
        res[0][0] = m1[0][0]*m2[0][0] + m1[0][1]*m2[1][0];
        res[0][1] = m1[0][0]*m2[0][1] + m1[0][1]*m2[1][1];
        res[1][0] = m1[1][0]*m2[0][0] + m1[1][1]*m2[1][0];
        res[1][1] = m1[1][0]*m2[0][1] + m1[1][1]*m2[1][1];

        return res;
    }
};

int main(int args, char** argv)
{
    std::cout << Solution().fib(atoi(argv[1])) << std::endl;
    return 0;
}

