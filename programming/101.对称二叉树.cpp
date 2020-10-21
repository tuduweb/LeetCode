/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
//用递归的话这里还能省略
private:
    bool DFS(TreeNode* p,TreeNode* q)
    {
        if(p == NULL || q == NULL)
            //同时为NULL return true
            return p == NULL && q == NULL;

        //值相等 递归深度搜索 能有值且相等 继续递归下去
        return (p->val == q->val)&&\
            DFS(p->left,q->right) &&\
            DFS(p->right,q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        /***
         * Some Ideas 
         * 想要镜像对称 那么对应位置一定是相等的.
         * 继续使用DFS 因为不相等就直接能return false了
         * 对于对称 应该只要保证在遍历节点的时候 保持同步就行了..
         * Let`s do it
         ***/
        #if 1
        /*√ Accepted
            √ 195/195 cases passed (12 ms)
            √ Your runtime beats 76.19 % of cpp submissions
            √ Your memory usage beats 95.17 % of cpp submissions (14.6 MB)*/
        return !root || DFS(root->left,root->right);
        #endif
        
    }
};

