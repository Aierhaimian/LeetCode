#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;
// 中位数：
// 如果有序数组长度为奇数，那么中位数就是最中间那个
// 如果是偶数，那么中位数就是最中间两个数字的平均值
//
// 此题严格限制时间复杂度为O(log(m+n))
// 因此无法先合并数组再求解
// 本应对数组长度是否为奇偶数分情况讨论，但为简化代码
// 使用trick：
// 分别找第(m+n+1)/2、(m+n+2)/2的数，然后求其平均值即可。
//
// 那么如何实现在不超出时间复杂度的情况下找到两个数组中的
// 第k个元素？
//
// 分别用i、j指向两个数组，分一般情况和特殊情况讨论：
// 一般情况：对k二分，分别查找两个数组中第k/2个元素
// 特殊情况：
// Time  Complexity: O(log(m+n))
// Space Complexity: O()
class Solution1 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int left = (m+n+1)/2, right = (m+n+2)/2;

        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
private:
    int findKth(const vector<int> &nums1, int i, const vector<int> &nums2, int j, ing k) {
        if (i >= nums1.size()) return nums2[j+k-1];
        if (j >= nums2.size()) return nums1[i+k-1];
        if (k == 1) return min(nums1[i], nums2[j]);

        int midVal1 = (i+k/2-1 < nums1.size()) ? nums1[i+k/2-1] : INT_MAX;
        int midVal2 = (j+k/2-1 < nums2.size()) ? nums2[j+k/2-1] : INT_MAX;

        if (midVal1 < midVal2) {
            return findKth(nums1, i+k/2, nums2, j, k-k/2);
        }
        else {
            return findKth(nums1, i, nums2, j+k/2, k-k/2);
        }
    }
};

class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size(), n = nums2.size();

        return (findKth(nums1, nums2, (m+n+1)/2) + findKth(nums1, nums2, (m+n+2)/2))/2.0;
    }
private:
    int m, n;
    int findKth(const vector<int> &nums1, const vector<int> &nums2, int k) {
        if (nums1.empty()) return nums2[k-1];
        if (nums2.empty()) return nums1[k-1];
        if (k == 1) return min(nums1[0], nums2[0]);

        int i = min(m, k/2), j = min(n, k/2);
        if (nums1[i-1] > nums2[j-1]) {
            return findKth(nums1, vector<int>(nums2.begin()+j, nums2.end()), k-j);
        }
        else {
            return findKth(vector<int>(nums1.begin()+i, nums1.end()), nums2, k-i);
        }
        return 0;
    }
};

class Solution3 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        if (n == 0) return ((double)nums1[(m - 1) / 2] + (double)nums1[m / 2]) / 2.0;
        int left = 0, right = n * 2;
        while (left <= right) {
            int mid2 = (left + right) / 2;
            int mid1 = m + n - mid2;
            double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
            double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
            if (L1 > R2) left = mid2 + 1;
            else if (L2 > R1) right = mid2 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};

int main()
{

    return 0;
}

