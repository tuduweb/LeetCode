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

    int solve1(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)  return 0;
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
};
// @lc code=end

