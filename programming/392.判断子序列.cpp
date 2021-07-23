/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        return solve1(s, t);
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
};
// @lc code=end

