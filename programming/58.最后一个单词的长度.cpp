/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        #if 1
        /*
        √ Accepted
        √ 59/59 cases passed (8 ms)
        √ Your runtime beats 83.99 % of cpp submissions
        √ Your memory usage beats 88.94 % of cpp submissions (8.6 MB)
        */
        string::const_reverse_iterator ite = s.rbegin();//最后一个元素的位置
        int cnt = 0;
        while(ite != s.rend())//rend指向容器的第一个元素的前一个位置.
        {
            if(*ite == ' ' && cnt > 0)
            {
                break;
            }
            if(*ite != ' ')
                ++cnt;
            ++ite;//在反向迭代器里面++是往前一个元素
        }
        return cnt;
        #endif
    }
};

