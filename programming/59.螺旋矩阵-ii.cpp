/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        return solve1(n);
    }

    /**
     * 自主完成
     * Accepted
     * 20/20 cases passed (0 ms)
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 36.32 % of cpp submissions (6.5 MB)
     */
    vector<vector<int>> solve1(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int x  = -1, y = 0;
        int i = 0, bias = 0;
        while(i < n * n) {
            while(x < n - bias - 1) {
                i++;
                x++;
                matrix[y][x] = i;
            }
            while(y < n - bias - 1) {
                i++;
                y++;
                matrix[y][x] = i;
            }
            while(x > bias) {
                i++;
                x--;
                matrix[y][x] = i;
            }
            bias++;
            while(y > bias) {
                i++;
                y--;
                matrix[y][x] = i;
            }
        }
        return matrix;
    }
};
// @lc code=end

