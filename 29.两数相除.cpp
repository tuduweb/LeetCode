/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        #define ALG_TYPE 1

        #if ALG_TYPE == 1
        /**
         * √ Accepted
            √ 989/989 cases passed (0 ms)
            √ Your runtime beats 100 % of cpp submissions
            √ Your memory usage beats 79.73 % of cpp submissions (8.2 MB)
         */


        long divisorTemp = llabs(divisor);
        long dividendTemp = llabs(dividend);
        long divideCnt = 0,divideTemp = 1;

        while(dividendTemp >= divisorTemp)
        {
            while(dividendTemp >= divisorTemp)
            {
                divisorTemp <<=1;
                divideTemp <<=1;
            }
            divisorTemp >>=1;
            divideCnt += divideTemp>>1;

            dividendTemp -= divisorTemp;
            divisorTemp = llabs(divisor);
            divideTemp = 1;
        }


        
        std::cout << divideCnt << "|||" << dividend << "/" << divisor << "/" << (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

        int flag = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        if(!flag)
            divideCnt = -divideCnt;

        divideCnt = divideCnt > INT_MAX ? INT_MAX : divideCnt;
        divideCnt = divideCnt < INT_MIN ? INT_MIN : divideCnt;

        return divideCnt;

        #endif
    }
};

