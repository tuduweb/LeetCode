/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    /**
     * Lookup Table
     * 'A' -> 1
     * 'B' -> 2
     * ...
     * 'Z' -> 26
     */
    int numDecodings(string s) {
        return solve2(s);
    }

    int solve1(string& s) {
        #if 0
        auto n = s.length();
        vector<vector<int > > dp(n, vector<int >(3, 0));

        //前一个数为单个
        //前一个数是combined num.

        /**
         * 1
         * dp[0][0] = 1 dp[0][1] = 0 dp[0][2] = 0 ans = 1
         * 
         * 11
         * 1 1
         * 11
         * dp[1][0] = 1 dp[1][1] = 0 dp[1][2] = 1 ans = 2
         * 
         * 111(3)
         * 1 1 1
         * 11 1
         * 1 11
         * dp[2][0] = dp[1][0] + dp[1][2] = 2; dp[2][1] = 0; dp[2][2] = 1; ans = 3
         * 
         * 1111(5)
         * //111 有两种单个(1 1 1/ 11 1)每种情况能扩展一种组成
         * //1 1 1 -> (2)
         * //11 1 -> (2)
         * // (2) + (2) + 1
         * 1 1 1 1
         * 11 1 1
         * 1 11 1
         * 1 1 11
         * 11 11
         * dp[3][0] = dp[2][2] + dp[2][0] + . = 3; dp[3][1] = 0; dp[3][2] = dp[2][0] = 2; ans = sum = 5
         * 
         * 11111(8)
         * 1 1 1 1 -> (2)
         * 11 1 1 -> (2)
         * 1 11 1 -> (2)
         * 1 1 11 = (1)
         * 11 11 = (1)
         * 
         * 11113(8)
         * 1 1 1 1 -> (2)
         * 11 1 1 -> (2)
         * 1 11 1 -> (2)
         * 1 1 11 => (1)
         * 11 11 => (1)
         * 
         * dp[3][0] = 
         * 
         * 111132
         * 1 1 1 1 3
         * 1 1 1 13
         * 11 1 1 3
         * 11 1 13
         * 1 11 1 3
         * 1 11 13
         * 1 1 11 3
         * 11 11 3
         */

        if(s[0] == '0') return 0;
        int ans = 1;
        if(s[0] > '2') dp[0][2]++;//后续只能单个
        else if(s[0] == '1') dp[0][0]++;//后续 单个 && 合并
        else if(s[0] == '2') dp[0][1]++;//判断一下后续值 >'6'单个 <= '6' 单个 && 合并
        //else == '0' 往后但是单的

        for(int i = 1; i < n; ++i)
        {
            //dp[i][0] = dp[i - 1][2];//单个
            
            // if(s[i] > '6') dp[i][0] += dp[i - 1][1];//单个
            // else if(s[i] == '1') dp[i][0]+=;
            // else if(s[i] == '2') dp[i][1]+=
            // //else dp[i][];//combined
        

            // dp[3][0] = dp[2][2] + dp[2][0] = 3; dp[3][1] = 0; dp[3][2] = dp[2][0] = 2; ans = sum = 5

            if(s[i] > '6')
            {
                //>=20 + s[i] not in table
                //10 + s[i] in
                //00 + s[i] not in table
                dp[i][0] = 0;
                //dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
                dp[i][1] = 0;
                dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
            }else if(s[i] > '2')
                //>=20 + s[i] in table
                //10 + s[i] in
                //00 + s[i] not in table
                //dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];
                dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
            }else{
                //>=20 + s[i] in table
                //10 + s[i] in
                //00 + s[i] not in table
                dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2];//不管前方如何 单个都是有市场的?

            }


        }
        #endif

        return 0;
    }

    /**
     * 自主：很多次错误很麻烦的搞法还不知道搞法是不是正确的方向结果还这么可惜(???th)
     * Accepted
     * 269/269 cases passed (8 ms)
     * Your runtime beats 39.59 % of cpp submissions
     * Your memory usage beats 5.15 % of cpp submissions (6.6 MB)
     */
    int solve2(string& s) {
        auto n = s.length();
        //以*为结尾的个数..
        vector<vector<int > > dp(n, vector<int >(4, 0));//0 1 2 >2(包括combined)

        if(s[0] == '0') return 0;

        if(s[0] == '1') dp[0][1] = 1;
        else if(s[0] == '2') dp[0][2] = 1;
        else dp[0][3] = 1;

        cout << s[0] << ": " << dp[0][0] << " " << dp[0][1] << " " << dp[0][2] << " " << dp[0][3] << endl;


        for(int i = 1; i < n; ++i)
        {
            if(s[i] == '0')
            {
                //这种情况不combined就无了? 所以前面不能combined了?yea
                //那么只能是前面为1,2的情况下才继续推进,其他可能全部抛弃
                dp[i][3] = dp[i - 1][1] + dp[i - 1][2];
            }else if(s[i] == '1')
            {
                //21 1; 2 1 1; 2 2 1
                dp[i][1] = dp[i - 1][3] + dp[i - 1][1] + dp[i - 1][2];
                //2 11; 2 21
                dp[i][3] = dp[i - 1][1] + dp[i - 1][2];
            }else if(s[i] == '2')
            {
                //21 2; 2 2 2; 2 1 2
                dp[i][2] = dp[i - 1][3] + dp[i - 1][1] + dp[i - 1][2];
                //2 12; 2 22
                dp[i][3] = dp[i - 1][1] + dp[i - 1][2];
            }else if(s[i] > '6')
            {
                //21 7; 2 17
                dp[i][3] = dp[i - 1][3] + dp[i - 1][1] * 2 + dp[i - 1][2];
            }else{
                //21 6; 2 16; 2 26
                dp[i][3] = dp[i - 1][3] + dp[i - 1][1] * 2 + dp[i - 1][2] * 2;
            }
            cout << s[i] << ": " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
        }


        return dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] + dp[n - 1][3];
    }




};
// @lc code=end

