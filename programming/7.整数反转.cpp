/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
class Solution {
public:
    int reverse(int x) {
        long temp = 0;
        do{
            temp *= 10;//第一次也是我0

            temp += x % 10;//取最低位. 负数取余通过取模来判定..
            
        }while((x /= 10) != 0);

        if((temp > INT_MAX) || (temp < INT_MIN))
            return 0;

        return (int)temp;

    }
};
/*
INT_MAX + 1 = INT_MIN
INT_MIN - 1 = INT_MAX
*/
