/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        #if 0
        //  第一次想出来的算法..时间复杂度,空间复杂度都太高了..
        //  √ 1563/1563 cases passed (72 ms)
        //  √ Your runtime beats 42.29 % of cpp submissions
        //  √ Your memory usage beats 75.22 % of cpp submissions (10.5 MB)
        //
        ListNode* resultListNode = new ListNode(0);
        ListNode* result = resultListNode;
        int co = 0;
        //return resultListNode;
        for(;;)
        {
            //进位

            //相加..
            if( (resultListNode->val = l1->val + l2->val + co) / 10 )
            {
                resultListNode->val -= 10;//进位..
                co = 1;
                //在测试例子中.此时还是有next的..
            }else{
                co = 0;
            }



            //构建尾部自循环..
            if(l1->next == NULL)
            {
                //后面的为0就当成自循环了.
                l1->next = new ListNode(0);
                l1->next->next = l1->next;
            }

            if(l2->next == NULL)
            {
                //后面的为0就当成自循环了.
                l2->next = new ListNode(0);
                l2->next->next = l2->next;
            }

            //如果也不进位了.那么跳出循环
            if( (l1->next->next == l1->next) && (l2->next->next == l2->next) && (co == 0))
                break;
            
            //递推.
            l1 = l1->next;
            l2 = l2->next;
            //建立新的节点.
            resultListNode->next = new ListNode(0);
            //当前指向下一个..
            resultListNode = resultListNode->next;

            //
        }

        return result;
        #endif

        #if 0
        // 算法二.20190426改进
        //  √ Accepted
        //  √ 1563/1563 cases passed (40 ms)
        //  √ Your runtime beats 97.45 % of cpp submissions
        //  √ Your memory usage beats 93.5 % of cpp submissions (10.2 MB)
        ListNode* node = new ListNode(0);
        ListNode* result = node;

        for(;l1 != NULL && l2 != NULL; l1 = l1->next,l2 = l2->next)
        {
            node = (node->next = new ListNode( l1->val + l2->val ));
        }

        //整理后续值..

        if( (l1 != NULL) || (l2 != NULL) )
        {
            for(l1 = (l1 == NULL?l2:l1) ; l1 != NULL; l1 = l1->next )
            {
                node = ( node->next = new ListNode(l1->val) );
            }

        }


        //整理进位..

        for(l1 = result->next;l1 != NULL; l1 = l1->next)
        {
            if(l1->val > 9)
            {
                l1->val -= 10;
                if(l1->next != NULL)
                {
                    l1->next->val += 1;
                }else{
                    l1->next = new ListNode(1);
                }
            }
        }


        return result->next;
        #endif


        //TopVotedSolution ?
        //感觉很规范 自己写不出来的样子...
        //可是复杂度好像很高?
        //√ Accepted
        //  √ 1563/1563 cases passed (44 ms)
        //  √ Your runtime beats 84.34 % of cpp submissions
        //  √ Your memory usage beats 73.98 % of cpp submissions (11.7 MB)
		if (l1 == NULL and l2 == NULL) return NULL;
		else if (l1 == NULL) return l2; 
		else if (l2 == NULL) return l1; 

		int a = l1->val + l2->val;
		ListNode *p = new ListNode(a % 10);
		p->next = addTwoNumbers(l1->next,l2->next);
		if (a >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));
		return p;

    }
};

