/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        /**
         * Accepted
         * 34/34 cases passed (0 ms)
         * Your runtime beats 100 % of cpp submissions
         * Your memory usage beats 22.28 % of cpp submissions (6.4 MB)
         */
        vector<vector<int > > dp(rowIndex + 1, vector<int>(rowIndex + 1));

        //需要注意边界条件
        if(rowIndex == 0) return {1};
        
        //row
        dp[0][0] = 1;
        dp[1][0] = dp[1][1] = 1;

        for(int i = 1; i < rowIndex + 1; ++i)
        {
            //col
            dp[i][0] = dp[i][i] = 1;
            for(int j = 1; j <= (i+1) / 2; ++j)
            {
                //std::cout << "i:" << i << "j:" << j << " " << dp[i - 1][j - 1] << " " << dp[i - 1][j] << std::endl;
                dp[i][j] = dp[i][i - j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }

        return dp[rowIndex];
    }
};
// @lc code=end

