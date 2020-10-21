/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
public:
    int minDepth(TreeNode* root) {
        #if 0
        /***
         * 最小深度
         * 如果一边还存在枝节，另外一边不存在。那么直接中断.返回.
         */
        //以下无法处理[1,2]这种究极简单的情况..只能加一个计数器了?
        if(root == NULL)
            return 0;
        return min(minDepth(root->left),minDepth(root->right)) + 1;
        #endif
        #if 1
        /**
         * √ Accepted
            √ 41/41 cases passed (24 ms)
            √ Your runtime beats 72.75 % of cpp submissions
            √ Your memory usage beats 50.75 % of cpp submissions (19.8 MB)
         */
        
        if(!root) return 0;
        int L = minDepth(root->left), R = minDepth(root->right);
        //第一层的特殊情况 那就是 1 0
        return (L && R ? min(L,R) : max(L,R) ) + 1;
        #endif
    }
};

