// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem300.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS_case1(vector<int>& nums)
    {
        int lis[nums.size()];
        int maxVal = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            lis[i] = 1;

            for(int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i])
                    lis[i] = nums[i] > nums[j] + 1 ? nums[i] : nums[j] + 1;
            }
            
            if(maxVal < lis[i])
                maxVal = lis[i];

        }

        return maxVal;
    }
    int lengthOfLIS(vector<int>& nums) {
        /**
         * DP问题
         */
        return lengthOfLIS_case1(nums);
    }
};
// @lc code=end

