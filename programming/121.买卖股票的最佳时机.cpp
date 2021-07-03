/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return solve1(prices);
    }

    /**
     * Accepted
     * 211/211 cases passed (156 ms)
     * Your runtime beats 34.12 % of cpp submissions
     * Your memory usage beats 10.28 % of cpp submissions (95 MB)
     */
    int solve1(vector<int>& prices) {
        int size = prices.size();
        vector<int> dp(size + 1);
        
        dp[0] = prices[0];
        int ans = 0 , t;

        //无后续性

        //prices[i]
        for(int i = 1; i < size; ++i)
        {
            t = prices[i] - dp[i - 1];
            if(t > ans) ans = t;

            if(prices[i] < dp[i - 1]) dp[i] = prices[i];
            else dp[i] = dp[i - 1];
        }

        return ans;
    }
};

