/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        #define ALG_TYPE 1

        #if (ALG_TYPE == 1)
        /**
         * √ Accepted
            √ 131/131 cases passed (260 ms)
            √ Your runtime beats 22.4 % of cpp submissions
            √ Your memory usage beats 51.2 % of cpp submissions (11.8 MB)
         */

        if(lists.empty()) return NULL;

        ListNode *head = new ListNode(0),*temp = head;

        vector< pair<int,int> > numsOrderCon;
        for(int i = 0; i < lists.size(); ++i)
            if(lists[i])
                numsOrderCon.push_back(pair((lists[i])->val,i));

        sort(numsOrderCon.rbegin(),numsOrderCon.rend());

        for(auto &x : numsOrderCon) std::cout<< x.first << "|";

        //return head;

        while(numsOrderCon.size() > 0)
        {
            //sort(numsOrderCon.begin(),numsOrderCon.end());

            temp = temp->next = new ListNode(numsOrderCon.back().first);
            auto tempPair = numsOrderCon.back();
            numsOrderCon.pop_back();
            if( lists[ tempPair.second ]->next )
            {
                lists[ tempPair.second ] = lists[ tempPair.second ]->next;
                numsOrderCon.insert(upper_bound(numsOrderCon.begin(),numsOrderCon.end(),pair(lists[ tempPair.second ]->val,tempPair.second)),pair(lists[ tempPair.second ]->val,tempPair.second));
                sort(numsOrderCon.rbegin(),numsOrderCon.rend());
            }

        }

        return head->next;

        #endif
    }
};

