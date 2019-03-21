#include <iostream>
#include <vector>

// Memory Search
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int fib(int N) {
        std::vector<int> record(N+1, -1);
        record[0] = 0;
        record[1] = 1;
        return dfs(N, record);
    }
private:
    int dfs(int N, std::vector<int>& record)
    {
        if (N <= 1) return N;
        if (record[N] >= 0) return record[N]; // 剪枝
        return record[N] = dfs(N-1, record) + dfs(N-2, record);
    }
};

int main(int args, char** argv)
{
    std::cout << Solution().fib(atoi(argv[1])) << std::endl;
    return 0;
}

