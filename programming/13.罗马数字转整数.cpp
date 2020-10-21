/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 * 题目分析:
 * 优先级上.看题目描述.为I,X,C与其他字符的右结合?
 * 大的数在前面.小的在后面..
 * 但是应该还是从右往左.比较合适,快捷..
 * 
 * /////////////以下摘自网络观点/////////////
 * 通常情况下，罗马数字中小的数字在大的数字的右边。那么我们需要处理的就是在左边的特殊情况..
 * 也就是小的数字在大的数字左边的情况..来进行减法...
 */
class Solution {
public:
    int romanToInt(string s) {
        //CASE 1:脑子里第一次想出来的解决办法
        int result = 0;
        string::iterator it = s.begin();
        //反转.序列 为了方便判断后续是否构成相减 (X) 正反皆可

        for(;it != s.end();++it)
        {
            switch (*it)
            {
            case 'I':
                if(*(it+1) == 'V')
                {
                    result += 4;
                    ++it;
                }else if(*(it+1) == 'X')
                {
                    result += 9;
                    ++it;
                }else{
                    result += 1;
                }
                break;

            case 'X':
                if(*(it+1) == 'L')
                {
                    result += 40;
                    ++it;
                }else if(*(it+1) == 'C')
                {
                    result += 90;
                    ++it;
                }else{
                    result += 10;
                }
                break;

            case 'C':
                if(*(it+1) == 'D')
                {
                    result += 400;
                    ++it;
                }else if(*(it+1) == 'M')
                {
                    result += 900;
                    ++it;
                }else{
                    result += 100;
                }
                break;

            case 'V':
                result += 5;
                break;
            case 'L':
                result += 50;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;

            
            default:
                break;
            }
        }

        return result;


        //CASE 2:参照网上给出的解决办法.比较大小的办法.


    }
};

