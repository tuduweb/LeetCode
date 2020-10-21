/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        #if 0
        /* 暴力法 
        √ Accepted
        √ 62/62 cases passed (12 ms)
        √ Your runtime beats 81.55 % of cpp submissions
        √ Your memory usage beats 77.22 % of cpp submissions (8.9 MB)
        */
        int pos = 0;
        for(; pos < nums.size(); ++pos)
        {
            if(target < nums[pos])
            {
                break;
            }
        }
        //防止越界
        /*
        if(pos > 0)
        {
            if(target == nums[pos - 1])
                return pos - 1;
            else
                return pos;
        }
        return 0;*/
        //return pos > 0 ? (target == nums[pos - 1] ? pos - 1 : pos) : 0;
        return pos > 0 ? pos - (target == nums[pos - 1]) : pos;
        #endif

        #if 1
        /* 二分法 */
        int leftPos = 0,rightPos = nums.size();

        if(target < nums[0])
            return 0;

        for(int temp;;)
        {
            temp = (leftPos + rightPos) / 2;
            if(target < nums[temp])
            {
                rightPos = temp;
            }else{
                //>=
                leftPos = temp;
            }

            if(rightPos - leftPos <= 1)
                break;
        }

        /*if(target == nums[leftPos])
        {
            return leftPos;
        }else{
            return leftPos + 1;
        }*/
        return leftPos + (target == nums[leftPos]);

        #endif

    }
};

