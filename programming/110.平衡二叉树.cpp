/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
class Solution {
private:
    int searchTree(TreeNode* root) {
        int left = 0,right = 0;
        if(root->left != NULL)
            left = searchTree(root->left);
        if(root->right != NULL)
            right = searchTree(root->right);
        //-1 == false
        if(left == -1 || right == -1)
            return -1;
        if(left - right > 1 || right - left > 1)
            return -1;
        //否则返回树的最大值.
        return (left > right ? left : right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        #if 1
        /***
         * √ Accepted
            √ 227/227 cases passed (20 ms)
            √ Your runtime beats 87.45 % of cpp submissions
            √ Your memory usage beats 87.33 % of cpp submissions (16.6 MB)
         */
        if(root == NULL)
            return true;
        int out = searchTree(root);//(root == NULL) || searchTree(root) > 0;
        std::cout << out;
        return (root == NULL) || out > 0;
        #endif
    }
};

