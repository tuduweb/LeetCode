/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        return solve1(matrix);
    }

    /**
     * Accepted
     * 71/71 cases passed (96 ms)
     * Your runtime beats 7.85 % of cpp submissions
     * Your memory usage beats 72.89 % of cpp submissions (11.4 MB)
     */
    int solve1(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if(h == 0) return 0;
        int w = matrix[0].size();
        vector<vector<int > > dp(h, vector<int >(w, 0));
        
        //统计点的左侧有多少pixel
        for(int i = 0; i < h; ++i) {
            int cnt = 0;
            for(int j = 0; j < w; ++j) {
                if(matrix[i][j] == '1')
                {
                    cnt++;
                }else{
                    cnt = 0;
                }
                dp[i][j] = cnt;
            }
        }

#if 0
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
#endif
        /**
         * 1 0 1 0 0 
         * 1 0 1 2 3 
         * 1 2 3 4 5 
         * 1 0 0 1 0 
         */

        //应用
        int ans = 0;
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                
                int width = dp[i][j];//current
                int area = width * 1;

                //遍历h 从i-1开始时因为有初始状态
                for(int k = i - 1; k >= 0; --k) {
                    width = std::min(dp[k][j], width);
                    area = std::max(area, width * (i - k + 1));
                }

                ans = std::max(ans, area);
            }
        }

        return ans;
    }
    
};
// @lc code=end

