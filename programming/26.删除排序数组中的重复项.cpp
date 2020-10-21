/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        #if 1
        int len = 1;
        /*
        √ Accepted
        √ 161/161 cases passed (36 ms)
        √ Your runtime beats 82 % of cpp submissions
        √ Your memory usage beats 80.02 % of cpp submissions (9.9 MB)
        */
        //第一个元素[0] 肯定是没有问题的..
        if(nums.empty())
            return 0;

        for(int i = 1; i < nums.size();++i)
        {
            if(nums[i] > nums[len - 1])
                nums[len++] = nums[i];
        }

        return len;
        #endif

        #if 0
        /*
        ### Top Voted Solution
        √ Accepted
        √ 161/161 cases passed (36 ms)
        √ Your runtime beats 82 % of cpp submissions
        √ Your memory usage beats 73.9 % of cpp submissions (10 MB)
        */
        int i = !nums.empty();
        for (int n : nums)
            if (n > nums[i-1])
                nums[i++] = n;
        return i;

        #endif
    }
};

