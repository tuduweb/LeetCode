/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class DictTree{
public:
    std::string word;
    std::vector<DictTree*> childrens;

    DictTree(): childrens(26, nullptr), word("") {}
};


class Solution {
public:
    vector<string> res;
    int rows, cols;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
        if(rows == 0) return res;


        DictTree root;
        //build tree
        for(auto word: words) {
            DictTree* cur = &root;
            for(auto c: word) {
                if(cur->childrens[c - 'a'] == nullptr) {
                    cur->childrens[c - 'a'] = new DictTree;
                }
                cur = cur->childrens[c - 'a'];
            }
            cur->word = word;
        }

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                dfs(board, &root, i, j);
            }
        }

        return res;

    }

    void dfs(vector<vector<char>>& board, DictTree* root, int y, int x) {
        char c = board[y][x];
        if(c == '.' || root->childrens[c - 'a'] == nullptr) return;
        root = root->childrens[c - 'a'];
        if(root->word != "") {
            res.push_back(root->word);
            root->word = "";
        }
        //dfs loop
        board[y][x] = '.';
        if(y > 0) dfs(board, root, y - 1, x);
        if(y < board.size() - 1) dfs(board, root, y + 1, x);
        if(x > 0) dfs(board, root, y, x - 1);
        if(x < board[0].size() - 1) dfs(board, root, y, x + 1);
        board[y][x] = c;
    }


};
// @lc code=end

