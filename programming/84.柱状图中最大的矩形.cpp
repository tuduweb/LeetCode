/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return solve2_stack_offical(heights);
    }

    /**
     * Time Limit Exceeded
     */
    int solve1(vector<int>& heights) {
        
        //int n = height.size();
        int ans = 0;
        for(int i = 0; i < heights.size(); ++i) {
            int res = heights[i];
            int minHeight = heights[i];
            for(int k = i - 1; k >= 0; --k) {
                minHeight = std::min(minHeight, heights[k]);
                res = std::max(res, minHeight * (i - k + 1));
            }
            ans = std::max(res, ans);
        }

        return ans;

    }

    int solve2_stack_offical(vector<int>& heights) {
        

        stack<int> stk;
        int ans = 0;
        heights.push_back(0);//在最右边加一个0, 这样可以起到全部出栈的作用

        for(int i = 0; i < heights.size(); ++i) {
            
            //要保证是递增栈
            while(!stk.empty() && heights[i] < heights[stk.top()]) {
                
                //计算结果, 并清洗到非严格上升列
                ans = std::max(ans, heights[stk.top()] * (i - stk.top()));
                stk.pop();
            }

            //大于等于即入栈
            stk.push(i);
        }

        // int right = stk.top();
        // while(!stk.empty()) {
        //     ans = std::max(ans, (right - stk.top() + 1) * heights[stk.top()]);
        //     stk.pop();
        // }

        /**
         * 最后看下标为 1，高度为 1 的矩形，它的左边和右边其实都没有元素了，
         * 它就是整个柱形数组里高度最低的柱形，计算它的宽度，就是整个柱形数组的长度。
         */

        return ans;
    }
};
// @lc code=end

