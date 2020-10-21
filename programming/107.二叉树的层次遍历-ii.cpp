/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        #if 1
        /***
         * √ Accepted
            √ 34/34 cases passed (24 ms)
            √ Your runtime beats 41.52 % of cpp submissions
            √ Your memory usage beats 83.33 % of cpp submissions (13.7 MB)
         */
        vector<vector<int>> c;
        //vector<vector<int>>::reverse_iterator it;
        
        if(root == NULL)
            return c;

        std::queue<TreeNode*> q;
        q.push(root);
        int levelCnt = 1,levelNum = 0;
        vector<int> tempC;

        while(!q.empty())
        {
            root = q.front();
            q.pop();
            levelCnt--;

            tempC.push_back(root->val);//它怎么知道遍历到哪一层了呢!

            //弹入队列
            if(root->left != NULL)
                q.push(root->left);

            if(root->right != NULL)
                q.push(root->right);
            
            if(levelCnt == 0)
            {
                //新的一层 这时上一层所有的节点已经POP.其儿子节点已经PUSH 切换到下一层
                levelCnt = q.size();
                c.insert(c.begin(),tempC);//插入首部
                tempC.clear();
            }
        }
        return c;
        #endif
    }
};

