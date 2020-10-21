/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现strStr()
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        #if 0
        if(needle.empty() || (haystack.length() < needle.length()))
            return - (haystack.length() < needle.length());
        
        int pos = 0,//当前位置
            i = 0,//次位置,用来搜字符串
            restart = 0;//[important]还需要记录一下次位置 这样在重新搜索的时候不会丢失掉位置.
        

        for(; pos < haystack.length() ; ++pos)
        {
            //更新restart 条件 不在首位,重新找到.
            if(i >0 && restart > pos - i && haystack[pos] == needle[0])
            {
                //不在搜索时候的首位,会死循环.
                //还没找到符合条件的.如果已经找到,应该是 restart > 开始的位置.在这里的pos,i都是加上了的.所以不需要对数值进行处理
                //当前符合条件. 所以得记录下当前位置.当成下一次开始的位置.(注意跳出本循环的时候还会++)
                restart = pos - 1;
            }

            if(haystack[pos] == needle[i])
            {
                //符合条件.那么只需要i++即可..跳出本次循环.
                if(needle.length() == ++i)
                    return pos - needle.length() + 1;
            }else{
                //重新开始.条件应该是.符合重新查找..
                if(restart > pos - i - 1)
                    pos = restart;
                i = 0;
            }
        }

        return -1;
        #endif

        #if 1
        /*
        √ Accepted
          √ 74/74 cases passed (8 ms)
          √ Your runtime beats 90.84 % of cpp submissions
          √ Your memory usage beats 73.98 % of cpp submissions (9.2 MB)
        * 这个破题目搞了一个月!在6月14日完成了。在图书馆完成了流程图。呜呜呜。
        */
        if(needle.empty() || (haystack.length() < needle.length()))
            return - (haystack.length() < needle.length());

        int currentFindPos = 0,//待搜索的字符串的位置
            findStrPos = 0,//搜索指标的进行到的位置。
            nextFindStartPos = -1;//重新启动搜索的位置


        //外层条件 无论什么情况 hayStack都是要自增的
        for(; currentFindPos < haystack.length() ; ++currentFindPos)
        {


            //那么就需要一个地方更新nextFindStartPos这个值..条件. 没更新过(用字符判断应该最为合适! 因为可以排除掉findStrPos = 0 的情况) & 出现首字符
            if( (nextFindStartPos <= currentFindPos - findStrPos)&& findStrPos > 0 && (haystack[currentFindPos] == needle[0]))
            {
                //小于才要更新.
                nextFindStartPos = currentFindPos;
            }

            //更新restart条件 也就是非首位的首字符 的位置. 默认在首字符开始位置.
            if(haystack[currentFindPos] == needle[findStrPos])
            {
                ++findStrPos;
                if(findStrPos == needle.length())
                {
                    //完全符合条件了 return 起始位置 大约是 currentFindPos - findStrPos 的样子.. 需要带入值进行运算测试
                    return currentFindPos - findStrPos + 1;//大约是多减去了1
                }
            }else{
                //不等于的情况.需要把搜索位置返回到 nextFindStartPos 上
                if((nextFindStartPos > currentFindPos - findStrPos))
                {
                    currentFindPos = nextFindStartPos - 1;//因为外面还会增加1 
                    //std::cout<<"ReFind"<<nextFindStartPos;
                }else{
                    
                }
                findStrPos = 0;
            }


        }

        return -1;

    }
};

