//
// Created by zhengxx on 15/5/14.
//

/**
 * median of two sorted arrays
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 * time = O(log(m + n)), space = O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), total = m + n;
        if (total & 0x1) return find_kth(nums1, 0, m, nums2, 0, n, total/2 + 1);
        return (find_kth(nums1, 0, m, nums2, 0, n, total/2) + find_kth(nums1, 0, m, nums2, 0, n, total/2 + 1))/2.0;
    }
    int find_kth(vector<int> &nums1, int s1, int e1, vector<int> &nums2, int s2, int e2, int k)
    {
        int len1 = e1 - s1, len2 = e2 - s2;
        if (len1 > len2)
            return find_kth(nums2, s2, e2, nums1, s1, e1, k);
        if (len1 == 0)
            return nums2[s2 + k - 1];
        if (k == 1)
            return min(nums1[s1], nums2[s2]);
        int ia = min(k / 2, m), ib = k - ia;
        if (nums1[s1 + ia - 1] < nums2[s2 + ib - 1])
            return find_kth(nums1, s1 + ia, e1, nums2, s2, e2, k - ia);
        else if (nums1[s1 + ia - 1] > nums2[s2 + ib - 1])
            return find_kth(nums1, s1, e1, nums2, s2 + ib, e2, k - ib);
        else
            return nums1[s1 + ia - 1];
    }
};
