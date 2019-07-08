/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
class Solution {
public:
    string addBinary(string a, string b) {
        /*
        Top Voted Solution
        核心就是swap(a,b) 好像很多算法里面都有这个关键的一步？需要好好总结
        */
        #if 1
        /*
        耗时一小时 真的是菜到自己忍无可忍了!
        √ Accepted
        √ 294/294 cases passed (8 ms)
        √ Your runtime beats 87.56 % of cpp submissions
        √ Your memory usage beats 64.42 % of cpp submissions (8.5 MB)
         */


        #define R11 ('1'+'1')
        //直接把b加到a上面吧..

        int co = a.length() - b.length();

        if(co > 0)
        {
            b.insert(b.begin(),co,'0');
        }else if(co < 0)
        {
            a.insert(a.begin(),-co,'0');
        }

        co = 0;

        //插入顺序和赋值迭代器的顺序似乎影响很大.需要去看一下
        string::reverse_iterator ita = a.rbegin();
        string::const_reverse_iterator itb = b.rbegin();


        //情况 0+1 = 1    0+0 = 0   1+1 = 11
        
        while(ita != a.rend() && itb != b.rend())
        {
                            std::cout << co;
            
            if(*ita + *itb + co >= R11)
            {
                *ita += *itb + co - '2';
                co = 1;
            }else{
                *ita += *itb + co - '0';//2进制 所以跟前面相差了2
                co = 0;
            }
            ita++;
            itb++;
        }
        if(co)
        {
            //该进位却没有进位
            a.insert(a.begin(),'1');
        }

        return a;
        #endif

        #if 0
        /* Case 2 */
        #endif

    }
};

