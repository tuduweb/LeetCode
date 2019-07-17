/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        #define ALG_TYPE 1

        #if ALG_TYPE == 1
        /**
         * √ Accepted
            √ 265/265 cases passed (28 ms)
            √ Your runtime beats 8.04 % of cpp submissions
            √ Your memory usage beats 93.45 % of cpp submissions (8.5 MB)
         */
        if(nums.size() <= 1)
            return;

        int i,j;

        //从末尾开始 找头一个升序位置
        for(i = nums.size() - 1; i > 0;--i)
        {
            if(nums[i - 1] < nums[i])
            {
                break;
            }
        }
        
        if( i == nums.size() - 1)
        {
            swap(nums[i],nums[i - 1]);
            return;
        }

        if(i > 0)
        {
            //记下升序位置
            for(j = i + 1; j < nums.size();++j)
            {
                if(nums[i - 1] >= nums[j])
                    break;
            }

            swap(nums[i - 1],nums[j - 1]);

            //
        }

        vector<int>::const_iterator it = nums.begin();
        while( it != nums.end())
            std::cout << *it++ << "|";

        std::cout << " ~  " << *(nums.begin() + i);

        reverse(nums.begin() + i,nums.end());

        
        #endif

        /**
         * According to Wikipedia, a man named Narayana Pandita presented the following simple algorithm to solve this problem in the 14th century.
        Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
        Find the largest index l > k such that nums[k] < nums[l].
        Swap nums[k] and nums[l].
        Reverse the sub-array nums[k + 1:].
        class Solution {
        public:
            void nextPermutation(vector<int>& nums) {
                int n = nums.size(), k, l;
                for (k = n - 2; k >= 0; k--) {
                    if (nums[k] < nums[k + 1]) {
                        break;
                    }
                }
                if (k < 0) {
                    reverse(nums.begin(), nums.end());
                } else {
                    for (l = n - 1; l > k; l--) {
                        if (nums[l] > nums[k]) {
                            break;
                        }
                    } 
                    swap(nums[k], nums[l]);
                    reverse(nums.begin() + k + 1, nums.end());
                }
            }
        }; 
         */


    }
};

