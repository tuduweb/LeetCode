/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve1(board);
    }

    /**
     * 学习了题解 自主完成 .. 哈希表?
     * Accepted
     * 507/507 cases passed (28 ms)
     * Your runtime beats 41.3 % of cpp submissions
     * Your memory usage beats 35.25 % of cpp submissions (19 MB)
     * 
     * 由于board中的整数限定在1到9的范围内，
     * 因此可以分别建立哈希表来存储任一个数在相应维度上是否出现过。
     * 维度有3个：所在的行，所在的列，所在的box，注意box的下标也是从左往右、从上往下的。
     * 链接：https://leetcode-cn.com/problems/valid-sudoku/solution/36-jiu-an-zhao-cong-zuo-wang-you-cong-shang-wang-x/
     */
    bool solve1(vector<vector<char>>& board) {
        vector<vector<bool > > row(9, vector<bool >(9, false));
        vector<vector<bool > > col(9, vector<bool >(9, false));
        vector<vector<bool > > box(9, vector<bool >(9, false));

        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.') continue;
                int item = board[i][j] - '1';
                if(row[i][item]) return false;
                if(col[j][item]) return false;
                if(box[i/3*3 + j/3][item]) return false;
                row[i][item] = col[j][item] = box[i/3*3 + j/3][item] = true;
            }
        }

        return true;

    }
};
// @lc code=end

