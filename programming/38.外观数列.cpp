/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        return solve1(n);
    }

    /**
     * Accepted
     * 30/30 cases passed (4 ms)
     * Your runtime beats 75.88 % of cpp submissions
     * Your memory usage beats 47.25 % of cpp submissions (6.5 MB)
     */
    string solve1(int n) {
        vector<string > f(2);
        f[0] = "1";
        for(int i = 1; i < n; ++i) {
            auto &sOld = f[1-i%2];
            auto &sNew = f[i%2];

            int k = 1, cnt = 1;
            while(k < sOld.length()) {
                if(sOld[k] == sOld[k - 1]) {
                    ++cnt;
                }else{
                    sNew.push_back((char)(cnt + '0'));
                    sNew.push_back(sOld[k - 1]);
                    cnt = 1;
                }
                ++k;
            }
            if(cnt > 0) {
                sNew.push_back((char)(cnt + '0'));
                sNew.push_back(sOld[sOld.length() - 1]);
                sOld.clear();
            }
        }
        return f[1 - n%2];
    }
};
// @lc code=end

