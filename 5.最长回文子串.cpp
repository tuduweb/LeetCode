/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
class Solution {
public:
    string longestPalindrome(string s) {
        #if 1
        /**
         * √ Accepted
            √ 103/103 cases passed (36 ms)
            √ Your runtime beats 74.47 % of cpp submissions
            √ Your memory usage beats 94.94 % of cpp submissions (8.7 MB)
         */
        if(s.length() < 1)
            return s;

        int leftP = 0,rightP = 1;
        int tempLength = 0,maxLength = 1;
        int startPos = 0;
        while(rightP < s.length())
        {
            tempLength = 0;

            while(s[leftP - tempLength] == s[rightP + tempLength])
            {
                ++tempLength;
                //eg s[0] == s[1] tempLength->1 break.
                if(leftP - tempLength < 0 || rightP + tempLength >= s.length())
                {
                    break;
                }
            }

            //std::cout << tempLength << " |";
            //tempLength = tempLength * 2 - (rightP == leftP);
            if (tempLength * 2 - (rightP == leftP) > maxLength)
            {
                maxLength = tempLength * 2 - (rightP == leftP);
                startPos = leftP - tempLength + 1;
                //std::cout << "[" << leftP << "," << rightP << "] " << tempLength << " "<< startPos << ">>>>" << maxLength << endl;
            }
            tempLength = 0;
            if (leftP < rightP)
                leftP++;
            else
                rightP++;

        }

        return s.substr(startPos,maxLength);

        #endif
    }
};

