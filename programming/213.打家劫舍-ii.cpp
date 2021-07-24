/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        return solve1(nums);
    }

    /**
     * 自主 根据198的dp方法 改成2次查找 避免连环的情况..
     * Accepted
     * 74/74 cases passed (4 ms)
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 38.26 % of cpp submissions (7.7 MB)
     */
    int solve1(vector<int>& nums) {
    
        int n = nums.size();
        if(n == 0) return 0;
        else if(n == 1) return nums[0];
        else if(n == 2) return std::max(nums[1], nums[0]);
        else if(n == 3) return std::max(std::max(nums[1], nums[0]), nums[2]);

        vector<int > dp(n, 0);

        {
            dp[1] = nums[1];
            dp[2] = std::max(nums[1], nums[2]);

            for(int i = 3; i < n; ++i) {
                dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
            }
        }

        {
            dp[0] = nums[0];
            dp[1] = std::max(nums[0], nums[1]);

            for(int i = 2; i < n - 1; ++i) {
                dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
            }
        }

        return std::max(dp[n - 2], dp[n - 1]);
    }

};
// @lc code=end

