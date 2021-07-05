/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return solve1_opt1(obstacleGrid);
    }

    /**
     * 原始第一遍方法(4th)
     * 41/41 cases passed (4 ms)
     * Your runtime beats 73.72 % of cpp submissions
     * Your memory usage beats 56.42 % of cpp submissions (7.6 MB)
     */
    int solve1(vector<vector<int>>& obstacleGrid) {//obstacleGrid[row][col]
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int > > dp(n + 1, vector<int >(m + 1, 0));

        if(obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;
        for(int i = 1; i < m; ++i)
        {
            if(obstacleGrid[0][i] == 0) dp[0][i] = 1;
            else break;
        }

        for(int j = 1; j < n; ++j)
        {
            if(obstacleGrid[j][0] == 0) dp[j][0] = 1;
            else break;
        }

        for(int j = 1; j < n; ++j)
        {
            for(int i = 1; i < m; ++i)
            {
                //j行i列
                if(obstacleGrid[j][i] == 0)
                    dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
                //else = 0
            }
        }

        return dp[n - 1][m - 1];
    }

    /**
     * 使用[#62]中学习的方法 对空间进行优化
     * 
     * 41/41 cases passed (0 ms)
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 80.91 % of cpp submissions (7.4 MB)
     */
    int solve1_opt1(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<int > dp(m, 0);
        if(obstacleGrid[0][0] == 1) return 0;

        for(int i = 0; i < m; ++i)
        {
            if(obstacleGrid[0][i] == 0)
                dp[i] = 1;
            else
                break;
        }

        for(int i = 1; i < n; ++i)
        {
            if(obstacleGrid[i][0] == 1)
                dp[0] = 0;

            for(int j = 1; j < m; ++j)
            {
                if(obstacleGrid[i][j] == 0)
                    dp[j] = dp[j] + dp[j - 1];
                else
                    dp[j] = 0;
            }
        }

        return dp[m - 1];
    }
};
// @lc code=end

