/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        return solve1(nums);
    }

    /**
     * Accepted
     * 68/68 cases passed (0 ms)
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 15.82 % of cpp submissions (7.7 MB)
     */
    int solve1(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        else if(n == 1) return nums[0];
        else if(n == 2) return std::max(nums[1], nums[0]);

        vector<int > dp(n, 0);

        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for(int i = 2; i < n; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return std::max(dp[n - 2], dp[n - 1]);
    }

};
// @lc code=end

