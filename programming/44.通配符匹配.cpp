/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        return solve1(s, p);
    }


    /**
     * 参考[10.正则表达式匹配]解法
     * Accepted
     * 1811/1811 cases passed (108 ms)
     * Your runtime beats 25.7 % of cpp submissions
     * Your memory usage beats 47.91 % of cpp submissions (11.1 MB)
     */
    bool solve1(string& s, string& p) {
        int m = s.length();
        int n = p.length();

        vector<vector<bool > > dp(m + 1, vector<bool>(n + 1, false));
        dp[m][n] = true;

        for(int i = m; i >= 0; --i) {
            for(int j = n; j >= 0; --j) {
                if(i == m && j == n) continue;
                bool currentMatched = (i < m && j < n && (p[j] == s[i] || p[j] == '?' || p[j] == '*'));
                if(p[j] == '*')
                {
                    dp[i][j] = dp[i][j + 1] || currentMatched && dp[i + 1][j];
                }else{
                    dp[i][j] = currentMatched && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];

    }

};
// @lc code=end

