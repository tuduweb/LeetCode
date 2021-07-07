/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        return solve1_opt(triangle);
    }

    /**
     * 自主完成
     * Accepted
     * 43/43 cases passed (16 ms)
     * Your runtime beats 8.88 % of cpp submissions
     * Your memory usage beats 33.6 % of cpp submissions (8.5 MB)
     * 
     * 复杂度：时间 o(n^2); 空间 o(n^2);
     */
    int solve1(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int > > dp(n, vector<int >(n));

        dp[0][0] = triangle[0][0];
        for(int h = 1; h < n; ++h)
        {
            for(int i = 0; i <= h; ++i)
            {
                if(i == 0)
                {
                    dp[h][0] = dp[h - 1][0] + triangle[h][0];
                }else if(i == h)
                {
                    dp[h][h] = dp[h - 1][h - 1] + triangle[h][h];
                }else{
                    dp[h][i] = std::min(dp[h - 1][i - 1], dp[h - 1][i]) + triangle[h][i];
                }

            }
        }

        int ans = INT_MAX;
        for(int i = 0; i < n; ++i)
            ans = std::min(ans, dp[n - 1][i]);

        return ans;
    }

    /**
     * 官方优化题解:动态规划+空间优化
     * https://leetcode-cn.com/problems/triangle/solution/san-jiao-xing-zui-xiao-lu-jing-he-by-leetcode-solu/
     * 
     * 可以发现状态转移方程只与上一状态有关，那么可以对空间优化
     * 43/43 cases passed (4 ms)
     * Your runtime beats 93.14 % of cpp submissions
     * Your memory usage beats 95.71 % of cpp submissions (8 MB)
     */
    int solve1_opt(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(2, vector<int>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            int curr = i % 2;
            int prev = 1 - curr;
            f[curr][0] = f[prev][0] + triangle[i][0];
            for (int j = 1; j < i; ++j) {
                f[curr][j] = min(f[prev][j - 1], f[prev][j]) + triangle[i][j];
            }
            f[curr][i] = f[prev][i - 1] + triangle[i][i];
        }
        return *min_element(f[(n - 1) % 2].begin(), f[(n - 1) % 2].end());
    }

};
// @lc code=end

