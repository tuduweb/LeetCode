/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return solve1(prices);
    }

    /**
     * 自主
     */
    int solve1(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)  return 0;
        //初始状态可能又问题，但是对了
        int firstBuy = -prices[0];
        int firstSell = -INT_MAX;
        int secondBuy = -INT_MAX;
        int secondSell = -INT_MAX;

        //无论题目中是否允许「在同一天买入并且卖出」这一操作，最终的答案都不会受到影响，这是因为这一操作带来的收益为零。
        for(int i = 1; i < n; ++i) {
            firstBuy = std::max(firstBuy, -prices[i]);
            firstSell = std::max(firstSell, prices[i] + firstBuy);
            secondBuy = std::max(firstSell - prices[i], secondBuy);
            secondSell = std::max(secondSell, prices[i] + secondBuy);
        }
        return secondSell;
    }

    /**
     * 官方题解 带了注释
     * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-iii-by-wrnt/
     * Accepted
     * 214/214 cases passed (112 ms)
     * Your runtime beats 96.07 % of cpp submissions
     * Your memory usage beats 81.14 % of cpp submissions (73.4 MB)
     */
    int solve1_offical(vector<int>& prices) {
        int n = prices.size();
        /**
         * 无论题目中是否允许「在同一天买入并且卖出」这一操作，
         * 最终的答案都不会受到影响，这是因为这一操作带来的收益为零。
         * 
         * 那么可以得到初始状态
         * （虽然不符合题意 但是这样搞没有收益 所以不会影响结果）
         */
        int firstBuy = -prices[0];
        //第一天买了又卖了
        int firstSell = 0;
        //第一天买了卖了又买了
        int secondBuy = -prices[0];
        int secondSell = 0;

        for(int i = 1; i < n; ++i) {
            firstBuy = std::max(firstBuy, -prices[i]);
            firstSell = std::max(firstSell, firstBuy + prices[i]);
            secondBuy = std::max(secondBuy, firstSell - prices[i]);
            secondSell = std::max(secondSell, secondBuy + prices[i]);
        }
        return secondSell;
    }
};
// @lc code=end

