/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return solve1(prices);
    }

    /**
     * Accepted
     * 200/200 cases passed (12 ms)
     * Your runtime beats 28.82 % of cpp submissions
     * Your memory usage beats 6.66 % of cpp submissions (14.8 MB)
     */
    int solve1(vector<int>& prices) {
        vector<vector<int > > dp(prices.size() + 1, vector<int> (2));

        dp[0][0] = prices[0];
        dp[0][1] = 0;//max till current
        int ans = 0;

        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] - dp[i - 1][0] > dp[i - 1][1]) dp[i][1] = prices[i] - dp[i - 1][0];
            else dp[i][1] = dp[i - 1][1];

            if(prices[i] < prices[i - 1])
            {
                dp[i][0] = prices[i];
                ans += dp[i - 1][1];
                //当前最大清零
                dp[i][1] = 0;
            }
            else
            {
                dp[i][0] = dp[i - 1][0];
            }
        }

        if(prices.size() > 1 && prices[prices.size() - 1] >= prices[prices.size() - 2])
            ans += dp[prices.size() - 1][1];

        return ans;
    }
};
// @lc code=end

