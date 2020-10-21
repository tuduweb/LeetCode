/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
class Solution {
public:
    string convert(string s, int numRows) {
        #if 1
        /**
         * √ Accepted
            √ 1158/1158 cases passed (12 ms)
            √ Your runtime beats 95.66 % of cpp submissions
            √ Your memory usage beats 86.55 % of cpp submissions (10.3 MB)
         */
        string coverString;
        int pos = 0;
        if(numRows == 1)
            return s;
        for(int r = 0; r <numRows;++r)
        {
            int period = 2 * numRows - 2;//这么多个元素
            pos = r;

            while(pos < s.size())
            {
                coverString += s[pos];
                int secondPos = pos + period - 2 * r;
                if( r != 0 && r != numRows - 1 && secondPos < s.size())
                {
                    coverString += s[secondPos];
                }

                pos+= period;
            }

        }
        return coverString;

        #endif
    }
};

