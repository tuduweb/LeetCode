/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        #if 1
        /***
         * 本题在做的过程中 范围没把握好!导致溢出了一个多小时 很是浪费时间!?
         * √ Accepted
            √ 15/15 cases passed (4 ms)
            √ Your runtime beats 94.15 % of cpp submissions
            √ Your memory usage beats 38.39 % of cpp submissions (8.7 MB)
         */
        vector<vector<int>> v(numRows);
        int i = 0,j;
        for(;i < numRows;++i)
        {
            v[i].resize(i + 1,1);
            //v[i].at(0) = v[i].at(numRows - 1) = 1;
            for(j = 1;j < i;++j)
                (v[i])[j] = (v[i - 1])[j - 1] + (v[i - 1])[j];
        }
        
        return v;
        #endif
    }
};

