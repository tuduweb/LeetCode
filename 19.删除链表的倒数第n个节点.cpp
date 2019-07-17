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
        /**
         * √ Accepted
            √ 208/208 cases passed (12 ms)
            √ Your runtime beats 62.77 % of cpp submissions
            √ Your memory usage beats 98.2 % of cpp submissions (8.3 MB)
         */

        //相差n
        int i = 0,j = 0;
        ListNode *currentNode = head,*prevNNode = head;

        while(currentNode->next)
        {
            i++;
            if(++j > n)
                prevNNode = prevNNode->next;
            currentNode = currentNode->next;
        }

        //std::cout << i << '|' << n << "|||" << j;

        /***
         * "删除过程有三种情况"
         * 需要删除的部分在最头部 那么把输出的位置 ->next即可
         * 需要删除的部分在中间 那么正常.需要删除的节点的上一个节点的next指向 next的next
         * 需要删除的部分靠近尾部 那么没有next->next.把需要删除的节点的上一节点的next指向null (n=1)
        ****/

       //核心: 找规律
        
        if(i == n - 1)
            return head->next;
        else if(n == 1)
            prevNNode->next = NULL;
        else
            prevNNode->next = prevNNode->next->next;

        return head;



        #endif
    }
};

