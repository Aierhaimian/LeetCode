#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for (int &i: A) {
            pow(i, 2);
        }

        sort(A.begin(), A.end());

        return A;
    }
};*/

/*
 * 在STL中，无论什么数据类型，size()函数返回的类型是一个无符号
 * 整形（unsigned） ，当size()为0时，
 * 返回值是00000000 00000000 00000000 00000000（32位，32个0），
 * 而该值减1时，由计算机组成的原理知，CPU的ALU没有减法器，只有
 * 加法器，所以变成+（-1）运算，可是-1在内存中的
 * 值为11111111 11111111 11111111 11111111（32位，32个1，补码），
 * 而一个无符号数加一个有符号数，CPU直接把它们当两个无符号数，相
 * 加的结果为11111111 11111111 11111111 11111111（32位，32个1，无
 * 符号整数），转为10进制是4294967295，所以0-1没有变成-1，而是变成
 * 了一个很大的数。
 * */

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        res = vector<int>(A.size(), 0);
        size_t start = 0, end = A.size() - 1;
        for (int i=(n-1); i>=0; --i) { // 此处不能直接求 i=A.size()-1 具体原因见上注释
            if (abs(A[start]) > abs(A[end])) {
                res[i] = A[start]*A[start];
                start ++;
            }
            else {
                res[i] = A[end]*A[end];
                end --;
            }
        }
        return res;
    }
private:
    vector<int> res;
};

int main()
{
    vector<int> A = {-4, -1, 0, 3, 10};
    vector<int> res = Solution().sortedSquares(A);
    for(int i: res)
        cout << i << " ";
    cout << endl;
    return 0;
}

