/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        #if 0
        //DFS 宽度有限搜索 按从上至下 从左至右的顺序先输出后遍历.
        
        //判别式.不相等就判定 判定否定式更为合适.
        if(p == NULL || q == NULL)
        {
            //同时为NULL return true
            if(p == NULL && q == NULL)
                return true;
            else
                return false;
        }else if(p->val == q->val)
        {
            //值相等 递归深度搜索 能有值且相等 代表肯定此时p,q.NULL
            if(!isSameTree(p->left,q->left) || !isSameTree(p->right,q->right))
                return false;
            return true;
        }
        return false;

        #endif

        #if 1
        //====================代码优化====================
        if(p == NULL || q == NULL)
            //同时为NULL return true
            return p == NULL && q == NULL;

        //值相等 递归调用搜索 能有值且相等 继续递归下去
        return (p->val == q->val)&&\
            isSameTree(p->left,q->left) &&\
            isSameTree(p->right,q->right);

        #endif
    }
};

