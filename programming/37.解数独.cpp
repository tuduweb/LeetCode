/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve1(board);
    }

    /**
     * 自主完成 用时..一小时左右 很慢……
     * Accepted
     * 6/6 cases passed (8 ms)
     * Your runtime beats 66.22 % of cpp submissions
     * Your memory usage beats 21.89 % of cpp submissions (6.4 MB)
     */
    vector<vector<bool > > row;
    vector<vector<bool > > col;
    vector<vector<bool > > box;
    vector<vector<char>> temp;
    bool hasAns = false;

    void solve1(vector<vector<char>>& board) {
        row.assign(9, vector<bool>(9, false));
        col.assign(9, vector<bool>(9, false));
        box.assign(9, vector<bool>(9, false));
        temp.assign(9, vector<char>(9));
        //填充阶段
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                temp[i][j] = board[i][j];
                if(board[i][j] == '.') continue;
                int item = board[i][j] - '1';
                row[i][item] = col[j][item] = box[i/3*3 + j/3][item] = true;
            }
        }
        solve1_item(board, 0, 0);
    }

    void solve1_item(vector<vector<char>>& board, int x, int y) {
        if(hasAns) return;
        if(y == 9) {
            hasAns = true; return;
        }
        if(temp[y][x] != '.')
        {

            solve1_item(board, (x + 1) % 9, y + (x + 1) / 9);

        }else{

            for(int num = 0; num < 9; ++num) {
                //cout << "x " << x << " y " << y << " num " << num << " v " << solve1_checkValid(x, y, num) << endl;
                if(solve1_checkValid(x, y, num)) {
                    //可以填
                    row[y][num] = col[x][num] = box[y/3*3 + x/3][num] = true;
                    board[y][x] = num + '1';
                    solve1_item(board, (x + 1) % 9, y + (x + 1) / 9);
                    if(hasAns) break;//需要跳出条件!!
                    row[y][num] = col[x][num] = box[y/3*3 + x/3][num] = false;
                }
            }

        }


    }

    //val = num - 1
    inline bool solve1_checkValid(int x, int y, int val) {
        return (!row[y][val] && !col[x][val] && !box[y/3*3 + x/3][val]);
    }
};
// @lc code=end

