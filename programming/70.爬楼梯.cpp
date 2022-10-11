/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
class Solution {
public:
    int climbStairs(int n) {
        /*
            k 个 2
            n - 2k 个 1
            排列组合

            Top Voted 斐波那契数列
         */

        #if 0
        /* */
        int result = 0;
        for(int k = n / 2; k > 0; --k)
        {
            result += 
        }
        #endif

        return solve1(n);
        
    }

    /**
     * n 可以分解为 n 个 1
     * 任意两个 1 可以合并成 2
     */
    int solve1(int n) {
        if(n == 0) return 0;
        int ans = 0;

        //最多有 n / 2 个2
        vector<int> dp(n + 2);
#if 0
        //假设第i个为2 那么dp[i - 1]有多少种搞法?
        dp[0] = 1;// [2] 1 1 1 ..
        dp[1] = 1;// 1 [2] 1 1 1 ...
        dp[2] = 2;// 1 1 (2) [2] 1 1 1 ..
        dp[3] = 3;// 1 1 1 (1 2 / 2 1) [2] 1 1 ..
        dp[4] = 5;// 1 1 1 1 (2 1 1 / 1 2 1 / 1 1 <2> / 2 <2>) [2] 1 1 ..
        dp[5] = 8;// 1 1 1 1 1 = 1
                  // 1 1 1 2 / 1 2 2 / 2 1 2 = dp[3]
                  // 1 1 2 1 / 2 2 1 = dp[2]
                  // 1 2 1 1 = dp[1]
                  // 2 1 1 1 = dp[0]
                  // = 1 + dp[0] + dp[1] + dp[2] + dp[3]
                  // = dp[4] + dp[3]
    #endif
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i < n - 1; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        for(int i = 0; i < n - 1; ++i)
        {
            ans += dp[i];
        }
        
        return ans + 1;
    }


    /**
     * 第n个台阶只能从第n-1或者n-2个上来。
     * 到第n-1个台阶的走法 + 第n-2个台阶的走法 = 到第n个台阶的走法，
     * 已经知道了第1个和第2个台阶的走法，一路加上去。
     */
};

