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

    int solve2_stack_self(vector<int>& heights) {
        

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


    int solve2_stack_offical(vector<int>& heights) {
        

        stack<int> stk;
        int ans = 0;
        heights.push_back(0);//在最右边加一个0, 这样可以起到全部出栈的作用
        heights.insert(heights.begin(), 0);

        for(int i = 0; i < heights.size(); ++i) {
            
            //要保证是递增栈
            while(!stk.empty() && heights[i] < heights[stk.top()]) {
                
                int cur = stk.top();
                // 错误答案
                // ans = std::max(ans, heights[stk.top()] * (i - stk.top()));
                stk.pop();
                int left = stk.top() + 1;
                int right = i - 1;//这个是固定到上一个位置..毕竟是从当前位置开始清洗栈
                // 计算结果, 并清洗到非严格上升列
                ans = std::max(ans, heights[cur] * (right - left + 1));
                cout << heights[cur] * (right - left + 1) << " " << left << " " << right << " " << cur << " " << heights[cur] <<  endl; 
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


        /**
         * 2 3 1 2 的情况
         * 
         * 默认在头和尾插入两个[0]
         * 0 2 3 1 2 0
         * 在运行到最末尾时  STACK中存在着 0 1 2 
         * 当cur = 1时
         *  right = 5 - 1 = 4
         *  left = 0 + 1 = 1
         *  right - left + 1 = 4
         */


        return ans;
    }
};
// @lc code=end

