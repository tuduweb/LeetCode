/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        #if 0
        //以下算法不满足题目要求…
        //题目要求利用l1 l2的所有节点!
        ListNode *node = new ListNode(0);
        ListNode *result = node;//保存结果节点

        //第一步 需要比较大小 穿插加入新的链表中.
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val)
            {
                node = node->next = new ListNode(l1->val);
                l1 = l1->next;
            }else{
                node = node->next = new ListNode(l2->val);
                l2 = l2->next;
            }
        }
        if(l1 != NULL)
        {
            node->next = l1;
        }else if(l2 != NULL)
        {
            node->next = l2;
        }
        return result->next;
        #endif

        #if 2
        //Top Voted

        //如果l1不存在 或者 l1,l2存在且 l1VAL > L2VAL .为了串葫芦/串小的葫芦..
        if( !l1 || l2 && l1->val > l2->val ) swap(l1,l2);

        //如果l1还有葫芦可以串 那么开串.且结果是下一个葫芦 vs 另一串
        if(l1) l1->next = mergeTwoLists(l1->next,l2);//l1,l2还是葫芦..
        return l1;//返回葫芦
        #endif

    }
};

