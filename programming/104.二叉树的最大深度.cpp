/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
//private int DFS(T)  BFS
public:
    int maxDepth(TreeNode* root) {
        #if 0
        /***
         * 递归深度
         * √ Accepted
            √ 39/39 cases passed (24 ms)
            √ Your runtime beats 66.76 % of cpp submissions
            √ Your memory usage beats 13.04 % of cpp submissions (19.6 MB)
         */
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
        {
            //叶子结点.
            return 1;
        }else if(root->left != NULL && root->right != NULL)
        {
            return max(maxDepth(root->left),maxDepth(root->right)) + 1;
        }
        return (root->left != NULL ? maxDepth(root->left) : maxDepth(root->right)) + 1;
        #endif
        #if 1
        /***
         * √ Accepted
            √ 39/39 cases passed (12 ms)
            √ Your runtime beats 94.86 % of cpp submissions
            √ Your memory usage beats 16.96 % of cpp submissions (19.5 MB)
         */
        //这样效率上会有问题吗?毕竟为NULL的时候也会调用递归…
        if(root == NULL)
            return 0;
        return max(maxDepth(root->left),maxDepth(root->right)) + 1;
        /*
        if(root->left != NULL && root->right != NULL)
        {
            return max(maxDepth(root->left),maxDepth(root->right)) + 1;
        }
        return (root->left != NULL ? maxDepth(root->left) : maxDepth(root->right)) + 1;
         */
        #endif

    }
};

