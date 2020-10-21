/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        #if 1
        /**
         * √ Accepted
            √ 25/25 cases passed (8 ms)
            √ Your runtime beats 62.97 % of cpp submissions
            √ Your memory usage beats 82.41 % of cpp submissions (8.5 MB)
         */
        if(digits.empty())  return {};
        //unordered_map<int,vector<char>> telMap;
        vector<int> telMap = {0,3,3,3,3,3,4,3,4};
        vector<int> telMapOffset(digits.size(),0);
        vector<string> result;

        for(int i = 1; i < telMap.size() ; ++i ) telMap[i] += telMap[i - 1];

        //for(auto &x : telMap) std::cout << x << ' ';

        //string.size() 层循环.

        int pos = 0;

        while(telMapOffset[0] < telMap[ digits[0] - '0' - 1] - telMap[ digits[0] - '0' - 2])
        {
            string oneRes;

            for(int onePos = 0; onePos < digits.size() ; ++onePos)
                //std::cout << (digits[onePos] - '0' - 2)<< "|" ;//<< telMapOffset[ digits[onePos] - '0' - 2 ] << "|";
                oneRes.push_back( telMap[ digits[onePos] - '0' - 2 ] + telMapOffset[ onePos ] + 'a' );
            
            result.push_back(oneRes);

            telMapOffset[digits.size() - 1]++;
            for(int onePos = digits.size() - 2;onePos >= 0; --onePos )
            {
                //std::cout << telMap[ digits[onePos + 1] - '0' - 2] - telMap[ digits[onePos] - '0' - 2];
                //break;
                //telMapOffset[onePos + 1] %= telMap[ digits[onePos + 1] - '0' - 1] - telMap[ digits[onePos + 1] - '0' - 2];
                
                if(telMapOffset[onePos + 1] /( telMap[ digits[onePos + 1] - '0' - 1] - telMap[ digits[onePos + 1] - '0' - 2]))
                {telMapOffset[onePos]++;}
                telMapOffset[onePos + 1] %= telMap[ digits[onePos + 1] - '0' - 1] - telMap[ digits[onePos + 1] - '0' - 2];
            }
        }

        return result;

        #endif
    }
};

