/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 * 回溯
 */

// @lc code=start
class Solution {
    /**
     * 官方题解
     * 回溯 + dp预处理
     * 考虑使用搜索 + 回溯的方法枚举所有可能的分割方法并进行判断。
     * 假设已经搜索到了第i个字符，且s[0, i - 1]位置的所有字符已经被分割成若干个回文串
     * 那么我们需要枚举下一个回文串的右边界j，使得s[i..j]是一个回文串
     * 
     * 假设我们已经搜索完了字符串的最后一个字符，那么就找到了一种满足要求的分割方法。
     * 
     * 细节：动态规划
     * 例如对于 s = aaba时
     * 对于前2个字符aa，有两种分割方法[aa]和[a,a]。
     * 当我们每一次搜索到字符串的第i=2个字符b时，对于s[i..j]使用双指针判断是否为回文串，产生了重复的计算。
     */

public:
    vector<vector<string>> partition(string s) {
        return solve2(s);
    }


#if 0
private:
    vector<vector<int > > f;
    vector<vector<string > > ret;
    vector<string > ans;
    int n;
    void dfs(const string& s, int i) {
        //边界条件 切到底了 那么这个答案合格了
        if(i == n) {
            ret.push_back(ans);
            return;
        }
        for(int j = i; j < n; ++j) {
            //切出的子串符合回文特征，那么将它加入解数组，并递归（继续切）
            if(f[i][j]) {
                ans.push_back(s.substr(i, j - i + 1));//位置, 长度
                dfs(s, j + 1);
                ans.pop_back();
            }
        }
    }

    vector<vector<string>> solve1(string& s) {
        n = s.size();
        f.assign(n, vector<int >(n, true));

        //预处理
        for(int i = n - 1; i >= 0; --i) {
            //[i...j]是否为回文串
            //for [i,i+1] ->[i,i+1,i+2] -> [i..j]
            for(int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cout << f[i][j] << " ";
            }
            cout << "\n";
        }

        dfs(s, 0);
        return ret;
    }

#elif 1


private:
    int n;
    vector<vector<string > > ans;
    vector<string > item;
    vector<vector<bool> > dp;

    void dfs2(string& s, int start) {
        //边界处理
        if(start == n) {
            ans.push_back(item);
            //item.clear();
            return;
        }

        for(int k = start; k < n; ++k) {
            if(dp[start][k]) {
                item.push_back(s.substr(start, k - start + 1));
                dfs2(s, k + 1);

                //因为"abb" "a" 能引申出两种情况 所以不能使用clear 但是可以使用pop_back
                item.pop_back();
            }
        }
        // //该项不可分
        // if(dp[start][n - 1] == false) {
        //     item.clear();
        // }

    }

    /**
     * Accepted
     * 32/32 cases passed (124 ms)
     * Your runtime beats 83.89 % of cpp submissions
     * Your memory usage beats 80.69 % of cpp submissions (73.8 MB)
     */
    vector<vector<string>> solve2(string& s) {
        n = s.length();

        //start, end
        dp.assign(n, vector<bool>(n, true));

        for(int i = 1; i < n; ++i) {
            for(int k = i - 1; k >= 0; --k) {
                //转移条件
                dp[k][i] = dp[k + 1][i - 1] && (s[k] == s[i]);
            }
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        
        //从0开始dfs
        dfs2(s, 0);

        return ans;
    }


#endif


};
// @lc code=end

