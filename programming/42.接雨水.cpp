/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        return solve1(height);
    }

    /**
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
};
// @lc code=end

