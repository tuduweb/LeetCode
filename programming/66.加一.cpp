/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        #if 1
        /*
        √ Accepted
        √ 109/109 cases passed (4 ms)
        √ Your runtime beats 95.79 % of cpp submissions
        √ Your memory usage beats 45.76 % of cpp submissions (8.5 MB)
        */
        vector<int>::reverse_iterator it = digits.rbegin();

        while(it != digits.rend())
        {
            if((++*it)/10 == 0)
            {
                //如果为0 说明不需要进位.跳出去
                break;
            }
            *(it++) = 0;
        }

        //处理最高位.变成10需要进位的需求.
        if(*digits.begin() == 0)
        {
            //*digits.begin() = 0;
            digits.insert(digits.begin(),1);
        }

        return digits;

        #endif
    }
};

