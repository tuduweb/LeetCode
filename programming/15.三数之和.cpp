/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        #if 1
        /**
         * √ Accepted
            √ 313/313 cases passed (220 ms)
            √ Your runtime beats 38.29 % of cpp submissions
            √ Your memory usage beats 87.76 % of cpp submissions (14.6 MB)
         */
        //是否存在三个不重复的元素 元素.
        vector<vector<int>> result;
        //merge two array -> find another.
        sort(nums.begin(),nums.end());
        //vector<int>::iterator it = nums.begin();
        //while(it != nums.end()) std::cout << *it++ <<"  ";

        if(nums.size() < 3 || nums.back() < 0 || nums.front() > 0) return {};

        for(int k = 0; k < nums.size() ; ++k )
        {
            if(nums[k] > 0) break;
            if(k > 0 && nums[k - 1] == nums[k]) continue;
            int target = 0 - nums[k];//需要找这么大的数.
            int i = k + 1, j = nums.size() - 1;
            while(i < j)
            {
                if(target == nums[i] + nums[j])
                {
                    result.push_back({nums[k],nums[i],nums[j]});
                    while(i < j && nums[i] == nums[i + 1]) ++i;
                    while(i < j && nums[j] == nums[j - 1]) --j;
                    ++i;--j;
                }else if(nums[i] + nums[j] > target) --j;
                else ++i;
            }
        }

        return result;

        #endif
    }
};

