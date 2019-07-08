/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return string();
        int minSize = (strs.at(0)).size();
        int pos = 1;
        //计算最小的长度..
        for(;pos < strs.size();++pos)
            if(minSize > (strs.at(pos)).size())
                minSize = (strs.at(pos)).size();

        for(pos = 0;pos < minSize;++pos)//位置的循环.
        {
            //品种的循环.
            for(int num = 1;num < strs.size();++num)
            {
                if( (strs.at(num - 1)).at(pos) != (strs.at(num)).at(pos) )
                    continue;//继续判断相邻

                //不相等的情况.直接输出结果.
                goto result;
            
            }
            //全部满足条件.继续判断下一个位置

            //

        }

        result:
            return (strs.at(0)).substr(0,pos);//从goto出来.没全部相等 需要-1;直接出来 由于增大了,所以还是-1
    }
};

