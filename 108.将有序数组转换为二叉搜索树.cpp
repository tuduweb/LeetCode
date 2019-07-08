/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* buildTree(vector<int>& nums,int left,int right) {
        if(right < left)
            return NULL;
        int mid = left + (right - left)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums,left,mid - 1);
        root->right = buildTree(nums,mid + 1,right);
        return root;

    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        #if 1
        /***
         * 基础题目 来源网络
         * 构建平衡二叉树
         */
        /***
         * √ Accepted
            √ 32/32 cases passed (20 ms)
            √ Your runtime beats 98 % of cpp submissions
            √ Your memory usage beats 58.8 % of cpp submissions (21 MB)
         */
        return buildTree(nums,0,nums.size() - 1);
        #endif
    }
};

