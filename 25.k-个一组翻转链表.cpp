/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        #define ALG_TYPE 1
        #if ALG_TYPE == 1
        /**
         * √ Accepted
            √ 81/81 cases passed (24 ms)
            √ Your runtime beats 97.02 % of cpp submissions
            √ Your memory usage beats 70.88 % of cpp submissions (10 MB)
         */

        if(k == 0 || !head) return head;
        //k的值小于或等于链表长度
        stack<ListNode*> listNodeStack;

        ListNode* tempHead = new ListNode(0);
        tempHead->next = head;
        head = tempHead;//首部
        ListNode* temp = tempHead;

        while(1)
        {
            for(int i = 0;i < k;++i){
                if(temp = temp->next)
                    listNodeStack.push(temp);
                else
                    return head->next;
            }
            tempHead->next->next = temp->next;//掰一下
            temp = tempHead;


            for(int i = 0;i < k;++i){
                temp->next = listNodeStack.top();
                listNodeStack.pop();
                temp = temp->next;
            }

            tempHead = temp;
        }


/*
        temp->next = listNodeStack.top();
        listNodeStack.pop();
        temp = temp->next;
        temp->next = listNodeStack.top();
        listNodeStack.pop();
        //temp = temp->next;
 */
        //return head->next;


        #endif
    }
};

