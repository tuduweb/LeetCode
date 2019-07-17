/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        #define ALG_TYPE 2
        
        #if(ALG_TYPE == 1)
        /**
         * √ Accepted
            √ 55/55 cases passed (8 ms)
            √ Your runtime beats 72.63 % of cpp submissions
            √ Your memory usage beats 77.23 % of cpp submissions (8.6 MB)
         */

        if(!head) return NULL;

        ListNode *tempHead = new ListNode(0);
        tempHead->next = head;

        if(head->next)
            head = head->next;

        ListNode *temp1,*temp2;

        while(tempHead)
        {

            //有两个
            if(tempHead->next && tempHead->next->next)
            {
                temp1 = tempHead->next->next;
                temp2 = tempHead->next->next->next;//保存下一个Head
                //cout << tempHead->next << "||" << tempHead->next->next << "||";


                //头节点的下一个 指向 下一个的下一个
                //换了之后 下一个指向,刚才的下一个?
                tempHead->next->next->next = tempHead->next;//[1] [2] 2指向1 此时丢失2的next
                tempHead->next->next = temp2;//指向丢掉的
                tempHead->next = temp1;
                //cout << tempHead->next->next << "||" << tempHead->next << "||";

                //tempHead->next = temp2;//1指向丢失掉的next
                //tempHead->next->next = temp1;

                //break;
                tempHead = temp1->next;
            
            }else{
                break;
            }
        }

        return head;

        #elif(ALG_TYPE == 2)
        /**
         * √ Accepted
            √ 55/55 cases passed (8 ms)
            √ Your runtime beats 72.63 % of cpp submissions
            √ Your memory usage beats 97.01 % of cpp submissions (8.4 MB)
         */
        //如果为空 或者只有一个 那么直接返回head
        if(!head || !head->next) return head;
        
        //加入一个前序节点
        ListNode *tempHead = new ListNode(0),*temp;
        tempHead->next = head;
        head = head->next;//输出的时候需要改变从第二个起 所以在这里就改变一下

        std::cout << tempHead->next << "||" << tempHead->next->next << "||" << tempHead->next->next->next << "||";

        while(tempHead)
        {
            //如果下一个不存在或者下下个不存在(为了防止越界)
            if(!tempHead->next || !tempHead->next->next)
                break;
            /*** 存在两个后序 所以需要替换,如果一个不用了直接退出
             * [F] -> [1] ->[2] -> Other
             * [F] -> [2] 这里会丢失 [1] 所以 用一个temp来储存一下[1] 即 [F]->next
             * temp->next = [2]->next 即[1]->next = [2]->next
             * 再把[2]->[1] 即 {[F]->next->next}->next = temp
             ***/
            //储存[1]
            temp = tempHead->next;
            //[F]->{[1]->next} => [F]->[2]
            tempHead->next = temp->next;
            //[1]->next = [2]->next
            temp->next = tempHead->next->next;
            //[2]->[1]
            tempHead->next->next = temp;

            //改变头 为了递增
            tempHead = temp;

        }

        return head;

        #endif
    }
};

