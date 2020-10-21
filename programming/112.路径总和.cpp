/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
#include <stack>
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        #if 1
        /***
         * √ Accepted
            √ 114/114 cases passed (16 ms)
            √ Your runtime beats 92.07 % of cpp submissions
            √ Your memory usage beats 45.2 % of cpp submissions (19.8 MB)
         */
        //使用stack的是迭代法
        std::stack<TreeNode*> s;
        if(!root) return false;
        s.push(root);
        while(!s.empty())
        {
            root = s.top();//从栈顶取出来
            s.pop();//删掉
            //更新value.

                //以后的都不可能.退出..怎么退呢..那就是不push进去呀.我真是个鬼才!

                if(root->left)
                {
                    root->left->val += root->val;
                    s.push(root->left);
                }
                if(root->right)
                {
                    root->right->val += root->val;
                    s.push(root->right);
                }
                if(!root->left && !root->right)
                {
                    //左右都为空.该结账了..
                    if(root->val == sum)
                        return true;
                }
            

            
            
        }
        return false;
        #endif
    }
};

