/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
class Solution {
public:
    string intToRoman(int num) {
        #if 1
        string result;
        //vector<vector<char>> numDict;
        /**
         * Map
         * √ Accepted
            √ 3999/3999 cases passed (24 ms)
            √ Your runtime beats 54.17 % of cpp submissions
            √ Your memory usage beats 75.26 % of cpp submissions (10.9 MB)

        * unordered_map
            √ Accepted
            √ 3999/3999 cases passed (24 ms)
            √ Your runtime beats 54.17 % of cpp submissions
            √ Your memory usage beats 73.46 % of cpp submissions (11.4 MB)

        * hash_map 不是标准的std库
         */
        std::unordered_map<int,char> numMap;
        numMap[1000] = 'M';
        numMap[500] = 'D';
        numMap[100] = 'C';
        numMap[50] = 'L';
        numMap[10] = 'X';
        numMap[5] = 'V';
        numMap[1] = 'I';


        int divide = 1000;
        int quotient = 0;

        while(divide > 0)
        {
            if(quotient = num / divide)
            {
                std::cout << quotient << "  ";

                if(quotient == 9)
                {
                    result.append(1,numMap[divide]);
                    result.append(1,numMap[divide * 10]);
                    num -= divide * 9;
                }else if(quotient == 4)
                {
                    result.append(1,numMap[divide]);
                    result.append(1,numMap[divide * 5]);
                    num -= divide * 4;
                }else{
                    result.append(quotient / 5,numMap[divide * 5]);
                    result.append(quotient % 5,numMap[divide]);
                    num -= divide * quotient;
                }
            
            }
            divide /= 10;
        }
        return result;


        #endif
    }
};

