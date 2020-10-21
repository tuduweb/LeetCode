/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        //Case 1:
        //使用数的翻转进行回文数的判断.
        //
        long reserve = 0;//数据类型大一号 防止溢出的情况.
        int temp = x;
        //if (( x < 0 || (x % 10 == 0)) && x != 0)
        //为负,必不是回文数.最低位为0,必不可能是回文数(与后面的翻转有漏) 仔细一想不可能.
        if( x < 0)
            return false;

        do{
            reserve *= 10;//第一次也是得0
            reserve += x % 10;//取最低位. 负数取余通过取模来判定..
        }while((x /= 10) != 0);
        
        return (reserve <= INT_MAX && ((int)reserve == temp));//综合判断..前面那个条件可能不需要
        
        //Case 2:
        //使用字符串..
        

    }
};

