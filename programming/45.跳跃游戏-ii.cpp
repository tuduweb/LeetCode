/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        return slove1(nums);
    }

    /**
     * Accepted
     * 104/104 cases passed (116 ms)
     * Your runtime beats 8.31 % of cpp submissions
     * Your memory usage beats 7.46 % of cpp submissions (16.4 MB)
     */
    int slove1(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return 0;
        int dis = len - 1, newdis;
        int k = 0;
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
                    k++;
                    break;
                }
            }
            //cant find ans, go to last step
            if(i == dis)
            {
                tmp[k] = 0;
                k--;
            }
            else
                dis = newdis;
            if(i == 0) break;
        }

        return k;
    }
};
// @lc code=end

