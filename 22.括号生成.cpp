/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        #if 0
        stack<char> bracketStack;
        //头一个得是( 最后一个得是 )
        //123210
        //101010
        //121010
        //121210
        //101210

        //里面的 < n 那么可以选? 也可以不选 选的话 +1 不选的话 不变.?No.
        //里面的 

        for(int i = 1; i < 2*n - 2; ++i)
        {
            //
        }

        #endif


        #if 0

        vector<vector<string>> dp(n+1,vector<string>());
        dp[0].push_back("");
        //dp[i]='('+ dp[k]+')'+dp[i-1-k],k=0..i-i

        #endif

        #if 3
        /**
         * √ Accepted
            √ 8/8 cases passed (8 ms)
            √ Your runtime beats 90.19 % of cpp submissions
            √ Your memory usage beats 81.7 % of cpp submissions (17 MB)
         */
        vector<string> result;
        backtrack(result,"",0,0,n);
        return result;
        #endif
    }

    void backtrack(vector<string>& ans,string cur,int left,int right,int n)
    {
        if(cur.size() == n * 2)
        {
            //cout << cur << "|||";
            ans.push_back(cur);
            return;
        }

        if(left < n)
            backtrack(ans,cur + "(",left + 1,right, n);
        if(right < left)
            backtrack(ans,cur + ")",left,right + 1,n);
    }
};

