// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "math.h"
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
/**
 * 方法一：动态规划法
 * 来源：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
 */
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
                    lis[i] = lis[i] > lis[j] + 1 ? lis[i] : lis[j] + 1;

            }
            
            if(maxVal < lis[i])
                maxVal = lis[i];

        }

        return maxVal;
    }
/**
 * 方法二：贪心+二分查找
 * 来源：官方题解
 * 思路：考虑一个简单的贪心，如果我们要使上升子序列尽可能的长，则我们需要让序列上升得尽可能慢，因此我们希望每次在上升子序列最后加上的那个数尽可能的小。
 * 
 */
    int lengthOfLIS_case2(vector<int>& nums) {
        int len = 1;

        if(nums.size() == 0)
            return 0;

        vector<int > d(nums.size() + 1, 0);

        d[1] = nums[0];

        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > d[len])
            {
                d[++len] = nums[i];
            }else{
                //二分查找最合适更改的
                int l = 1, r = len, pos = 0;
                while( l <= r)
                {
                    int mid = (l + r) / 2;
                    if(d[mid] < nums[i]){
                        pos = mid;
                        l = mid + 1;//找最接近的,现在可能小了
                    }else{
                        r = mid - 1;//现在可能大了
                    }
                }
                //二分查找完毕,更新
                d[pos + 1] = nums[i];
            }
        }

        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        /**
         * DP问题
         */
        return lengthOfLIS_case2(nums);
    }
};
// @lc code=end

