/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        #if 1

        //相差n
        int i = 0,j = n;
        ListNode *currentNode = head,*prevNNode = head;

        while(currentNode)
        {
            i++;
            if(--j >= 0)
                prevNNode = prevNNode->next;
            currentNode = currentNode->next;
        }

        std::cout << i << '|' << n;
        if(i == n)
            return head->next;
        else if(i == n + 1)
            prevNNode->next = NULL;
        else
            prevNNode->next = prevNNode->next->next;

        return head;



        #endif
    }
};

