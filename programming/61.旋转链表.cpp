/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        return solve1(head, k);
    }

    /**
     * 自主：我也不知道算什么方法的方法
     * Accepted
     * 231/231 cases passed (4 ms)
     * Your runtime beats 96.52 % of cpp submissions
     * Your memory usage beats 70.48 % of cpp submissions (11.4 MB)
     */
    ListNode* solve1(ListNode* head, int k) {
        if(head == nullptr || k == 0) return head;
        ListNode* temp = head;
        int cnt = 0, cutPos;
        while(++cnt && temp->next != nullptr && (temp = temp->next));
        k = k % cnt;
        cutPos = cnt - k;
        
        temp->next = head;
        ListNode* newHead = head;
        while(--cutPos && (newHead = newHead->next));
        temp = newHead->next;
        newHead->next = nullptr;
        return temp;
    }
};
// @lc code=end

