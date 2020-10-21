/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        #if 1
        /**
         * √ Accepted
            √ 59/59 cases passed (4 ms)
            √ Your runtime beats 99.06 % of cpp submissions
            √ Your memory usage beats 88.49 % of cpp submissions (8.6 MB)
         */
        //倒序合并.
        int pos = m + n - 1, i = m - 1, j = n - 1;
        while(j >= 0)//需要把nums2(j)中的元素全部放到nums1中.
        {
            nums1[pos--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
        }

        #endif
        
    }
};


