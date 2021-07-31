/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        rotate2(matrix);
    }

    /**
     * 数学题?
     * Accepted
     * 21/21 cases passed (4 ms)
     * Your runtime beats 43.84 % of cpp submissions
     * Your memory usage beats 41.98 % of cpp submissions (6.9 MB)
     */
    void rotate1(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int > > ans(n, vector<int>(n));

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                ans[i][j] = matrix[n - 1 - j][i];
            }
        }

        matrix = ans;
    }

    /**
     * 对空间的优化：找规律
     * i,j <- n-1-j,i <- n-1-i,n-1-j <- j,n-1-i <- i,j
     * 
     * Accepted
     * 21/21 cases passed (0 ms)
     * Your runtime beats 100 % of cpp submissions
     * Your memory usage beats 54.22 % of cpp submissions (6.9 MB)
     */
    void rotate2(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; ++i) {
            for(int j = 0; j < (n + 1)/2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = temp;
            }
        }
    }

};
// @lc code=end

