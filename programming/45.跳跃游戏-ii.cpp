/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        return solve2(nums);
    }

    /**
     * Accepted
     * 104/104 cases passed (116 ms)
     * Your runtime beats 8.31 % of cpp submissions
     * Your memory usage beats 7.46 % of cpp submissions (16.4 MB)
     */
    int solve1(vector<int>& nums) {
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


    /**
     * 看了题解，尝试优化掉"cant find ans"的情况
     * 
     * Accepted
     * 104/104 cases passed (72 ms)
     * Your runtime beats 9.88 % of cpp submissions
     * Your memory usage beats 10.52 % of cpp submissions (16 MB)
     */
    int solve2(vector<int>& nums) {
        int last = nums.size() - 1;
        int k = 0;
        while(last > 0)
        {
            for(int i = 0; i < last; ++i)
            {
                if(nums[i] >= last - i)
                {
                    last = i;
                    k++;
                    break;
                }
            }
        }

        return k;
    }

    /**
     * 题解 https://leetcode-cn.com/problems/jump-game-ii/solution/tiao-yue-you-xi-ii-by-leetcode-solution/
     * 方法二：正向查找可到达的最大位置
     * 如果我们「贪心」地进行正向查找，每次找到可到达的最远位置，就可以在线性时间内得到最少的跳跃次数。
     * 
     * 104/104 cases passed (68 ms)
     * Your runtime beats 9.98 % of cpp submissions
     * Your memory usage beats 39.03 % of cpp submissions (15.8 MB)
     */
    int solve3(vector<int>& nums) {
        int maxPos = 0, end = 0, step = 0;
        int n = nums.size();

        for(int i = 0; i < n - 1; ++i)
        {
            //当前能到达的最远位置.. 初始情况为 0 + nums[0] 即为nums[0]
            if(maxPos >= i)
            {
                //如果第i个能到达更远的位置, 那么更新最远位置..
                maxPos = std::max(maxPos, i + nums[i]);
            }

            //到了最远位置? 就+1(// 到达上次跳跃能到达的右边界了 还没找到更优 那么就这么跳跃)
            if(i == end)
            {
                end = maxPos;//上一次完成跳跃。那么得到了下一次的最远跳跃位置
                ++step;// jump
            }
        }

        return step;
    }

    /**
     * DP 注意要从后往前递推，dp[i]表示当前位置i要走到末尾最少需要的步数。
     * 
     * 从后往前，如果当前位置能后直接到达终点就为1，
     *  如果不能，就看当前位置，往后面的J个位置，那个地方的步数最少，
     * 就选择最少的+1就是当前位置最少的步数。
     */
};
// @lc code=end

