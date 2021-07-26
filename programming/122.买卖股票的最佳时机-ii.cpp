/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return solve2(prices);
    }

    /**
     * 自主：这是什么解法什么思路 我自己怎么看不懂了
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
            //如果在当前位置抛出大于之前抛出的profit
            if(prices[i] - dp[i - 1][0] > dp[i - 1][1])
                dp[i][1] = prices[i] - dp[i - 1][0];
            else dp[i][1] = dp[i - 1][1];//否则延续之前的买卖状态

            //如果现在的价格比上一天的低..下降状态 那么前一天就当卖出股票了(高抛低吸)
            if(prices[i] < prices[i - 1])
            {
                //今天买入
                dp[i][0] = prices[i];
                //结果累加
                ans += dp[i - 1][1];
                //当前最大清零
                dp[i][1] = 0;
            }
            else
            {
                //当前价格比之前的>= 那么延续这个购买价格
                dp[i][0] = dp[i - 1][0];
            }
        }

        //特殊处理最后一天 因为没遇到下降的情况
        if(prices.size() > 1 && prices[prices.size() - 1] >= prices[prices.size() - 2])
            ans += dp[prices.size() - 1][1];

        return ans;
    }

    /**
     * 题解：dpdpdp
     * 第三种方法：DP动态规划，第i天只有两种状态，不持有或持有股票，
     * 当天不持有股票的状态可能来自昨天卖出或者昨天也不持有，
     * 同理，当天持有股票的状态可能来自昨天买入或者昨天也持有中，
     * 取最后一天的不持有股票状态就是问题的解
     * 
     * Accepted
     * 200/200 cases passed (8 ms)
     * Your runtime beats 62.05 % of cpp submissions
     * Your memory usage beats 9.2 % of cpp submissions (14.8 MB)
     */
    int solve2(vector<int>& prices) {
        int n = prices.size();
        //state 0 当前无股票; state 1 当前持有股票
        vector<vector<int > > dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for(int i = 1; i < n; ++i) {
            //要想当前无股票 要么上一天没股票然后今天没买；或者上一天买了今天卖了
            //取无股票状态的最大值 反正两种搞法都是当前无股票嘛..
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);

            //要想当前有股票 要么是之前买了今天没卖；要么是今天买了
            //要保持的状态是，这个利润要最大，也就是当前的钱要多多的，因为买股票等于买了权益，肯定要买到低点才能赚更多钱的
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        //最大利润肯定是没股票时候产生的
        return dp[n - 1][0];

    }
};
// @lc code=end

