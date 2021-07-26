/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return solve1(prices);
    }

    /**
     * 自主 dp
     * Accepted
     * 210/210 cases passed (4 ms)
     * Your runtime beats 79.6 % of cpp submissions
     * Your memory usage beats 46.34 % of cpp submissions (11.4 MB)
     */
    int solve1(vector<int>& prices) {
        
        int n = prices.size();
        if(n == 1) return 0;

        vector<vector<int > > dp(n, vector<int>(2));
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        dp[1][0] = std::max(0, dp[0][1] + prices[1]);
        dp[1][1] = std::max(-prices[0], -prices[1]);

        for(int i = 2; i < n; ++i) {
            dp[i][0] = std::max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            //昨天卖了，今天就不能买。所以买入股票后的最大利润不能算上昨天的状态，得算前天的
            //昨天的状态是：昨天or前天的最佳状态 但是昨天的不能算 也就是昨天卖了得到了一个最佳状态今天也是不能买的 但是今天买不买取决于今天会不会得到最佳的状态
            //昨天不持有：那么只能是昨天没买或者昨天卖了，昨天卖了今天是不能操作的 今天不操作状态就是=dp[i - 1][1]
            //昨天没买的话，最佳的状态是前天的 前天的最佳状态是前天卖了or前天未操作

            //!!!如果今天要买，只能是昨天没卖
            dp[i][1] = std::max(dp[i - 2][0] - prices[i], dp[i - 1][1]);
        }

        return dp[n - 1][0];

    }
};
// @lc code=end

