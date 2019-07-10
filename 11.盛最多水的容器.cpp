/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        #if 1
        /**
         * √ Accepted
            √ 50/50 cases passed (20 ms)
            √ Your runtime beats 90.23 % of cpp submissions
            √ Your memory usage beats 94.33 % of cpp submissions (9.6 MB)
         */
        int rightP = height.size() - 1,leftP = 0;
        int maxArea = 0,h = 0;      
        //如果找到最大值.再进行计算?
        //面积 min(h(Left),h(Right)) * (Right - Left)

        while(leftP < rightP)
        {
            h = min(height[leftP],height[rightP]);
            maxArea = max(maxArea,(rightP - leftP) * h);
            while(height[leftP] <= h && leftP < rightP) leftP++;
            while(height[rightP] <= h && leftP < rightP) rightP--;
        }
        
        return maxArea;

        #endif
    }
};

