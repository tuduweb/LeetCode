/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return solve1(matrix);
    }


    /**
     * Accepted
     * 23/23 cases passed (4 ms)
     * Your runtime beats 33.98 % of cpp submissions
     * Your memory usage beats 62.26 % of cpp submissions (6.7 MB)
     */

    vector<int> solve1(vector<vector<int>>& matrix) {
        vector<int > ans;

        int x = -1, y = 0, bias = 0;
        int m = matrix[0].size(), n = matrix.size();
        while(1) {
            while(x + bias < m - 1) {
                x++;
                ans.emplace_back(matrix[y][x]);
            }
            if(ans.size() == m * n) break;
            while(y + bias < n - 1) {
                y++;
                ans.emplace_back(matrix[y][x]);
            }
            if(ans.size() == m * n) break;
            while(x - bias > 0) {
                x--;
                ans.emplace_back(matrix[y][x]);
            }
            if(ans.size() == m * n) break;
            bias++;
            while(y - bias > 0) {
                y--;
                ans.emplace_back(matrix[y][x]);
            }

            if(ans.size() == m * n) break;
        }

        return ans;


    }
};

/**PYTHON
 *
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        res = []
        while matrix:
            # 削头（第一层）
            res += matrix.pop(0)
            # 将剩下的逆时针转九十度，等待下次被削
            matrix = list(zip(*matrix))[::-1]
        return res
*/

// @lc code=end

