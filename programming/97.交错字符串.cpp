/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return solve1_offical(s1, s2, s3);
    }

    /**
     * 从S3中顺序抽S1，留下的跟S2比较。
     * for i = 0 -> s3.size
     *  in s1 or not in s1
     */
    bool solve1(const string& s1, const string& s2, const string& s3) {
        
        int h = s1.size();
        int w = s2.size();

        vector<vector<int > > dp(w, vector<int >(h));
        vector<vector<int > > map(w, vector<int >(h, 0));

        //如果绘map 那么不是由当前点的x,y取字符，而是下一步的?
    
        return false;
    }


    /**
     * 官方题解
     * 上一步能成行 && 当前也行
     * 时间、空间复杂度 o(nm) ~> 可以滚动优化
     */
    bool solve1_offical(const string& s1, const string& s2, const string& s3) {
    
        auto f = vector< vector<int > > (s1.size() + 1, vector<int >(s2.size() + 1, false) );

        int n = s1.size(), m = s2.size(), t = s3.size();

        if(n + m != t)
            return false;

        f[0][0] = true;
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                //当前 = 上一步ok + 可以从上一步到这一步
                //f[i][j] = (f[i - 1][j] && s1[i - 1] == s3[p]) or (f[i][j - 1] && s2[j - 1] == s3[p])
                if(i > 0){
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if(j > 0){
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }

            }
        }

        return f[n][m];    
    }


};
// @lc code=end

