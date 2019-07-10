/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        #if 1
        /**
         * √ Accepted
            √ 125/125 cases passed (28 ms)
            √ Your runtime beats 18.06 % of cpp submissions
            √ Your memory usage beats 99.86 % of cpp submissions (8.4 MB)
         */
        
        sort(nums.begin(),nums.end());
        if(nums.size() < 3) return {};
        vector<int>::iterator it = nums.begin();
        while(it != nums.end()) std::cout << *it++ <<" ";

        vector<int> result = {nums[0],nums[1],nums[2],INT_MAX};

        for(int k = 0; k < nums.size() ; ++k )
        {
            //if(nums[k] > target) break;//->脑残了吧我
            //if(k > 0 && nums[k - 1] == nums[k]) continue;
            int i = k + 1,j = nums.size() - 1;

            while(i < j)
            {
                int closedNum = nums[k] + nums[i] + nums[j] - target;
                if(abs(closedNum) < abs(result[3]))
                {
                    result[0] = nums[k];
                    result[1] = nums[i];
                    result[2] = nums[j];
                    result[3] = closedNum;
                }

                if(closedNum > 0){
                    j--;
                }else{
                    i++;
                }
            }
        
        
        }

        for(int p = 0;p < result.size();++p)
            std::cout << result[p] << "   ";

        return result[0] + result[1] + result[2];

        //如果数比上一次接近 那么是有效果的?
        // right-- left不动 那么这个数会减小 [k] [i] [j]
        // left++ right不动 那么这个数会增大 [k] [i] [j]
        // 肯定会有更接近的情况?

        #endif

        #if 0

        sort(nums.begin(),nums.end());
        int sub = INT_MAX;
        int sum = 0;

        for(int i = 0; i < nums.size(); ++i )
        {
            int lo = i + 1,hi = nums.size() - 1;
            while(lo < hi)
            {
                if(abs(nums[lo] + nums[hi] + nums[i] - target) < sub)
                {
                    sum = nums[lo] + nums[hi] + nums[i];
                    sub = abs(sum - target);
                }

                if(nums[lo] + nums[hi] + nums[i] > target)
                {
                    hi--;
                }else{
                    lo++;
                }
            }
        }

        return sum;

        #endif
    }
};

