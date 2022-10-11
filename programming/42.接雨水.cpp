/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        return solve2_offical(height);
    }

    /**
     * 官方题解 动态规划
     * Accepted
     * 320/320 cases passed (4 ms)
     * Your runtime beats 92.97 % of cpp submissions
     * Your memory usage beats 7.61 % of cpp submissions (14.2 MB)
     */
    int solve1(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        vector<int > leftMax(n);
        leftMax[0] = height[0];
        //找出i位置左边最大的
        for(int i = 1; i < n; ++i)
        {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }

        vector<int > rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for(int j = n - 2; j >= 0; --j)
        {
            rightMax[j] = std::max(rightMax[j + 1], height[j]);
        }

        int ans = 0;
        //求和
        for(int i = 0; i < n - 1; ++i)
        {
            ans += std::min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }

    /**
     * 题解 单调栈!! [important]
     * https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
     * 
     * 当前高度小于等于栈顶高度，入栈，指针后移。
     * 当前高度大于栈顶高度，出栈，
     * 计算出当前墙和栈顶的墙之间水的多少，
     * 然后计算当前的高度和新栈的高度的关系，重复第 2 步。
     * 直到当前墙的高度不大于栈顶高度或者栈空，然后把当前墙入栈，指针后移。
     * 
     * Accepted
     * 320/320 cases passed (4 ms)
     * Your runtime beats 92.88 % of cpp submissions
     * Your memory usage beats 13.77 % of cpp submissions (14.1 MB)
     */
    int solve2_offical(vector<int>& height) {
        stack<int> stk;
        int sum = 0;
        for(int i = 0; i < height.size(); ++i) {
            while(!stk.empty() && height[i] > height[stk.top()]) {
                int h = height[stk.top()];
                stk.pop();//出栈..h1 h2 h[current] 有水
                
                //没有接水的界了 那就装不了水了
                if(stk.empty())
                    break;
                
                int distance = i - stk.top() - 1;//3 4 5 -> 5 - 3 -1
                int minHeight = std::min(height[stk.top()], height[i]);
                //减去接水的那一层的高度..高度差
                sum += distance * (minHeight - h);
            }
            //没有元素或者是递减状态时 就入栈
            stk.push(i);
        }
        
        return sum;
    }
};
// @lc code=end

