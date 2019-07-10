/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        #if 0
        /**
         * √ Accepted
            √ 447/447 cases passed (332 ms)
            √ Your runtime beats 23.67 % of cpp submissions
            √ Your memory usage beats 15 % of cpp submissions (15.3 MB)
         */

        //正则匹配..
        //递归求解?

        if(p.empty()) return s.empty();

        bool currentMatched = !s.empty() && (p[0] == '.' || s[0] == p[0]);

        //当前位置匹配 + 剩余位置是否匹配

        //剩余字符串
        if(p.length() >= 2 && p[1] == '*')
        {
            //两种情况 一种为正常情况 * 匹配0个字符?    另一种为匹配到了?
            // a* 重复匹配a 直到 a匹配完的情况.
            // .* 重复匹配任何字符… [这里会分支出很多种情况 但是所有情况都会被枚举出来?]
            // 匹配到 * 不能匹配字符串时候 直接跳过pattern中的x*这种东西.继续匹配以后的东西
            return isMatch( s , p.substr(2) ) || (currentMatched && isMatch( s.substr(1) , p ));
        }else{
            return currentMatched && isMatch( s.substr(1) , p.substr(1) );
        }

        #endif

        #if 2
        /**
         * 动态规划解法
         * √ Accepted
            √ 447/447 cases passed (12 ms)
            √ Your runtime beats 80.8 % of cpp submissions
            √ Your memory usage beats 84.25 % of cpp submissions (8.9 MB)
         */

        //初始化申请数组,多一唯空间是把最小的情况也放在for循环里面.
        int m = s.size(),n = p.size();
        vector<vector<bool>> dp(m + 1,vector<bool>(n + 1,false));
        dp[m][n] = true;
        
        for(int i = m; i >= 0;--i)
        {
            for(int j = n; j >= 0;--j)
            {
                if(i == m && j == n) continue;
                bool currentMatched = (i < m && j < n && (p[j] == s[i] || p[j] == '.'));

                if(j + 1 < n && p[j + 1] == '*')
                {
                    dp[i][j] = dp[i][j + 2] || currentMatched && dp[i + 1][j];
                }else{
                    dp[i][j] = currentMatched && dp[i + 1][j + 1];
                }
            }
        }

        return dp[0][0];


        #endif
    }
};

