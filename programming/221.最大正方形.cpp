/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        return solve1(matrix);
    }

    /**
     * DP 自主 思路来自脑子里记得的求最大面积
     * Accepted
     * 73/73 cases passed (24 ms)
     * Your runtime beats 89.27 % of cpp submissions
     * Your memory usage beats 15.12 % of cpp submissions (11.6 MB)
     */
    int solve1(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        //if(m == 1) return *max_element(matrix[0].begin(), matrix[0].end()) - '0';
        int n = matrix[0].size();

        //m行 n列
        vector<vector<int > > dp(m, vector<int>(n, 0));
        
        for(int i = 0; i < m; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            for(int j = 1; j < n; ++j) {
                if(matrix[i][j] == '1')
                    dp[i][j] = dp[i][j - 1] + 1;
            }
        }

        //应用
        int ans = 0;
        for(int i = m - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                
                //从点 matrix[i][j]判断.
                int deep = dp[i][j];
                if(deep)
                    ans = std::max(ans, 1);
                for(int k = i - 1; k >= 0 && k >= i - deep + 1; --k) {
                    deep = std::min(deep, dp[k][j]);
                    if(k >= i - deep + 1)
                        ans = std::max(ans, (i - k + 1) * (i - k + 1));
                }
            }
        }

        return ans;
    }
};
// @lc code=end

