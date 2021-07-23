/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        return solve1(grid);
    }

    /**
     * 自主(1st)
     * 61/61 cases passed (12 ms)
     * Your runtime beats 58.95 % of cpp submissions
     * Your memory usage beats 34.57 % of cpp submissions (9.8 MB)
     */

    int solve1(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int > > dp(n, vector<int >(m));

        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for(int i = 1; i < n; ++i)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
            for(int j = 1; j < m; ++j)
            {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[n - 1][m - 1];
    }
};
// @lc code=end

