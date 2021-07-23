/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        return solve_dp_offical(s, t);
    }

    /**
     * 双指针 究极入门题
     * Accepted
     * 17/17 cases passed (0 ms)
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 98.47 % of cpp submissions (6 MB)
     */
    bool solve1(const string& s, const string& t) {
        int n = t.length();
        int m = s.length();
        int k = 0;
        for(int i = 0; i < n; ++i) {
            if(s[k] == t[i])
                ++k;
            if(k == m)
                break;
        }
        if(k == m)
            return true;

        return false;
    }

    /**
     * 官方题解：DP 用于解决大字符串的问题
     * Accepted
     * 17/17 cases passed (12 ms)
     * Your runtime beats 10.27 % of cpp submissions
     * Your memory usage beats 5.19 % of cpp submissions (11.3 MB)
     */
    bool solve_dp_offical(const string& s, string& t) {
        /**
         * 所以我们前期多做一点工作，将长字符串研究透彻，
         * 假如长字符串的长度n，建立一个 n∗26 大小的矩阵，
         * 表示每个位置上26个字符下一次出现的位置。实现如下：
         */
        t.insert(t.begin(), ' ');
        int len1 = s.length();
        int len2 = t.length();
        vector<vector<int> > dp(len2, vector<int>(26, 0));

        /**
         * 数据的构造 第一个下标是位置前 0<s1> 1<s2> 2<s3> 3<s4>
         * dp[-1][t[-1]] = .. (后续只有一个字符了 所以只有一个char取到了值)
         * dp[-2][..2] = .. (后续有两个字符 可能1~2个位置取值)
         * 
         * dp[0][..] = ..
         */
        //位置i后 第一次出现的位置
        //eg. f[1]['c'] = 2 下一次出现c的位置为2
        for(char c = 'a'; c <= 'z'; ++c) {
            int nextPos = -1;//表示接下来不会出现该字符'c'
            for(int i = len2 - 1; i >= 0; i--) {
                dp[i][c - 'a'] = nextPos;
                if(t[i] == c)
                    nextPos = i;
            }
        }
#if 0
        for(int i = 0; i < len2; ++i)
        {
            for(int j = 0; j < 26; ++j) {
                cout << dp[i][j] <<" ";
            }
            cout << "\n";
        }
#endif
        /**
         * 数据的利用 遍历字符串s // for <s> 0 -> len - 1
         * 1) index = 0; dp[index ~ 0][s[0]] -> nextPos => index
         */

        int index = 0;
        for(auto c : s) {
            //下一个位置 最近的 再找下一个要取得 最近的
            index = dp[index][c - 'a'];
            if(index == -1)
                return false;
        }
        return true;

    }

};
// @lc code=end

