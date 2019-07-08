/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*
        √ Accepted
        √ 113/113 cases passed (8 ms)
        √ Your runtime beats 96.45 % of cpp submissions
        √ Your memory usage beats 73.19 % of cpp submissions (8.7 MB)
        */
        int len = nums.size();
        if(nums.empty())
            return 0;
        for(int i = 0; i < len; )
        {
            if(val == nums[i])
                nums[i] = nums[--len];
            else
                ++i;
        }
        return len;
    }
};

