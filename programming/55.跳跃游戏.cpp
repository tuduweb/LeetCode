/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return solve3(nums);
    }

    /**
     * 调试了比较久..感觉还是有问题
     * Accepted
     * 165/165 cases passed (68 ms)
     * Your runtime beats 35.25 % of cpp submissions
     * Your memory usage beats 6.4 % of cpp submissions (47.2 MB)
     */
    bool solve1(vector<int>& nums) {
        int last = nums.size() - 1;
        int end = 0, maxPos = 0;
        int flag = 1;
        if(last > 0 && nums[0] == 0) return false;

        for(int i = 0; i < last; ++i)
        {
            if(i <= maxPos)
            {
                //更新最远位置
                maxPos = std::max(maxPos, i + nums[i]);
            }

            //到达了上一次的边界..那么就没有更好的情况了
            if(i == end)
            {
                //最远的位置都是到这里..那么可能无解?
                if(i > 0 && maxPos == end && end < last && nums[ end > last ? last : end] == 0)
                //if(i > 0 && end < last && nums[ end > last ? last : end] == 0)
                {
                    cout << "i" << i << " end" << end << " maxPos" << maxPos << endl;
                    flag = 0;
                    break;
                }
                end = maxPos;

                //step++;
            }
        }

        return flag;
    }

    /**
     * 怎么让这个解答正确呢?
     * I dont know!
     */
    bool solve2(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return true;
        if(nums[0] == 0) return false;

        int dis = len - 1, newdis;
        int k = 0;
        int flag = 1;
        vector<int> tmp(len + 1, 0);

        //int flag = 0;
        while(1)
        {
            //初始查找的位置 init = 0
            int i = tmp[k];
            for(; i < dis; ++i)
            {
                if(nums[i] >= dis - i)
                {
                    std::cout << i << " " << dis << std::endl;
                    newdis = i;
                    flag = 0;
                    k++;
                    break;
                }
            }
            //cant find ans, go to last step
            //遍历一圈 没有找到答案
            if(i == dis)
            {
                tmp[k] = 0;
                k--;
                if(dis == len - 1)
                {
                    flag = -1;
                    break;
                }
            }
            else
                dis = newdis;
            if(i == 0) break;
        }

        return flag > -1;
    }

    /**
     * 官方题解：https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode-solution/
     * 贪心：最远可以到达的位置
     * Accepted
     * 165/165 cases passed (72 ms)
     * Your runtime beats 29.14 % of cpp submissions
     * Your memory usage beats 21.5 % of cpp submissions (47.1 MB)
     */
    bool solve3(vector<int>& nums) {
    
        int n = nums.size();
        int rightMost = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i <= rightMost)
            {
                rightMost = std::max(rightMost, i + nums[i]);
                if(rightMost >= n - 1)
                    return true;
            }
        }

        return false;
    
    }

};
// @lc code=end

