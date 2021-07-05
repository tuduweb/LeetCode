/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        return solve1_opt2(m, n);
    }

    /**
     * Accepted
     * 62/62 cases passed (0 ms)
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 48.42 % of cpp submissions (6.3 MB)
     */
    int solve1(int m, int n)
    {
        //好像行和列搞反了
        vector<vector<int > > dp(m + 1, vector<int >(n + 1));
        //每一个位置可以由上和左得到

        dp[0][0] = 0;
        // dp[1][0] = 1;
        // dp[0][1] = 1;
        for(int i = 0; i < m; ++i)
            dp[i][0] = 1;
        for(int j = 0; j < n; ++j)
            dp[0][j] = 1;

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    /**
     * 题解：https://leetcode-cn.com/problems/unique-paths/solution/dong-tai-gui-hua-by-powcai-2/
     * 优化：因为我们每次只需要 dp[i-1][j],dp[i][j-1]
     * 所以我们只要记录这两个数，直接看代码吧！
     * 
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 64.97 % of cpp submissions (6 MB)
     * 
     * o(2n)
     */
    int solve1_opt(int m, int n)
    {
        //只跟上一行和本行有关
        vector<vector<int > > dp(2, vector<int >(m));
        
        for(int i = 0; i < m; ++i) dp[0][i] = 1;
        dp[1][0] = 1;

        int k;
        for(int i = 0; i < n; ++i)
        {
            k = i % 2;
            for(int j = 1; j < m; ++j)
            {
                dp[k][j] = dp[1 - k][j] + dp[k][j - 1];
            }
        }

        return dp[k][m - 1];
    }

    /**
     * dp优化
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 69.43 % of cpp submissions (6 MB)
     * 空间复杂度：o(n)
     */
    int solve1_opt2(int m, int n)
    {
        vector<int > dp(m, 1);
        for(int j = 1; j < n; ++j)
        {
            for(int i = 1; i < m; ++i)
            {
                //=左边刚刚计算的 + 上一行时计算的相同列的值
                dp[i] = dp[i - 1] + dp[i];
            }
        }

        return dp[m - 1];
    }


    /**
     * 题解递归：https://leetcode-cn.com/problems/unique-paths/solution/san-chong-shi-xian-xiang-xi-tu-jie-62-bu-4jz1/
     * 从i,j 到 m, n的路径
     * result = dfs(i + 1, j) + dfs(i, j + 1)
     */

};
// @lc code=end

