/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        #if 1
        /**
         * √ Accepted
            √ 1079/1079 cases passed (16 ms)
            √ Your runtime beats 25.23 % of cpp submissions
            √ Your memory usage beats 77.16 % of cpp submissions (8.6 MB)
         */

        int pos = 0,startPos = 0,posTemp;
        long result = 0;
        while(pos < str.length() && str[pos] == ' ') pos++;
        if(pos == str.length()) return 0;
        if(str[pos] == '+' || str[pos] == '-')
            startPos = ((str[pos++] == '-')?(-pos):(pos));
        else
            startPos = pos;

        while(pos < str.length() && str[pos] >= '0' && str[pos] <= '9') pos++;

        std::cout << startPos << " | " << pos << endl;
        
        posTemp = abs(startPos);

        while(posTemp < str.length() && str[posTemp] == '0') posTemp++;

        if(pos - posTemp <= 0)
            return 0;
        else if(pos - posTemp <= 10)
            while(posTemp < pos)
                result = (str[posTemp++] - '0') + result * 10;
        else
            return startPos >=0 ? INT_MAX : INT_MIN;
        
        if(startPos < 0)
            result = -result;
        
        if(result > INT_MAX)
            return INT_MAX;
        else if(result < INT_MIN)
            return INT_MIN;

        return (int)result;
        #endif
    }
};

