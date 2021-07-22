/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int n = s.length();

        vector<vector<bool> > f(n + 1, vector<bool>(n + 1, true));
    
        //预处理
        for(int i = n - 1; i >= 0; --i) {
            //[i...j]是否为回文串
            //for [i,i+1] ->[i,i+1,i+2] -> [i..j]
            for(int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        //最少分割次数
        vector<int > g(n+1, INT_MAX);
        for(int i = 0; i < n; ++i) {
            //全部能回文 那么就是0
            if(f[0][i])
            {
                g[i] = 0;
                continue;
            }

            for(int k = 0; k < i; ++k) {
                // 0->i 如果 k + 1 -> i 是回文..
                // 那么 0 -> k 的结果 + 1(一次回文) 就是当前可能的分割结果
                // 再判断是不是最小值, 如果是最小值那么更新
                if(f[k + 1][i])
                    g[i] = std::min(g[i], g[k] + 1);
            }
        }
    

        return g[n - 1];
    }
};
// @lc code=end

