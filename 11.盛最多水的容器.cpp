/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        #if 1
        int rightP = height.size() - 1,leftP = 0;
        int maxArea = 0,area = 0,flag = 0;      
        //如果找到最大值.再进行计算?
        //面积 min(h(Left),h(Right)) * (Right - Left)

        while(leftP < rightP)
        {
            area = min(height[leftP],height[rightP]) * 
        }

        #endif
    }
};

