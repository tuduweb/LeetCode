/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        /***
         * 注意到 ListNode 是有序链表
         * √ Accepted
            √ 165/165 cases passed (16 ms)
            √ Your runtime beats 94.29 % of cpp submissions
            √ Your memory usage beats 21.28 % of cpp submissions (9.3 MB)
         ***/
        #if 0
        //为空..
        if(head == NULL)
            return head;
        ListNode* subHead = head;
        ListNode* temp = head;
        while(temp->next != NULL)
        {
            if(temp->next->val == subHead->val)
            {
                //相等 递推temp
            }else{
                //不相等 更新subHead->next,更新subHead
                subHead->next = temp->next;//指向下一个不同的点
                subHead = temp->next;//更新head 指向temp
            }
            temp = temp->next;

        }
        //处理最后一个节点
        subHead->next = temp->next;//指向下一个不同的点

        return head;
        #endif

        #if 1
        /***
         * √ Accepted
            √ 165/165 cases passed (20 ms)
            √ Your runtime beats 83.39 % of cpp submissions
            √ Your memory usage beats 85.39 % of cpp submissions (9 MB)
        **/
        //条件判断
        if(head == NULL)
            return head;
        
        ListNode* temp = head;

        while(temp->next != NULL)
        {
            if(temp->next->val == temp->val)
            {
                //直接递推更新下一个节点.
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
        }
        return head;
        #endif

    }
};

