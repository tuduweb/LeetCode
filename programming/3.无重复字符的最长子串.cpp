/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //map<char,int> charMap;
        #if 0
        int len = 0;
        for(string::iterator it = s.begin();it != s.end();++it)
        {
            string::iterator itb = it;
            for(string::iterator it2 = it;it2 != s.end();++it2)
            {
                if( (*it2 == *itb) && it2 - itb > len )
                {
                    len = it2 - itb;
                    itb = it2;
                }

            }
        }   
        return len;
        #endif

#if 0
        map<char,int> charMap;
        int len = 0,subLen = 0,right = 0;
        //对于取出来的数有两种情况..
        //Case 1 : 没有出现过 -> 更新Map len++
        //Case 2 : 出现过 -> 得到出现的位置 .. 当前位置 减去 上次出现的位置.. 得到一个长度subLen. 跟 len比较
        for(string::iterator it = s.begin();it != s.end();++it)
        {
			map<char,int>::iterator itr = charMap.find(*it);
            //如果找到了相同的 那么跟当前的最大值比一下..
            //如果没找到 就加到map里面
            if ((itr == charMap.end()) )//&& (itr->second != i)
            {
                //没有出现过 则插入到Map中.并且长度++
                charMap.insert({*it,it - s.begin() });//value,当前位置
                ++subLen;
            }else{
                //找到了相同的.那么计算subLen 并更新出现位置...
                if(subLen > len)
                    len = subLen;//更新一下len 到 subLen
                
                if(right > itr->second)
                {
                    subLen = (it - s.begin()) - right;//当前位置 - 上次位置.sub长度..
                }else{
                    subLen = (it - s.begin()) - itr->second;//当前位置 - 上次位置.sub长度..
                }
                
                right = itr->second;//右界                
                itr->second = it - s.begin();

                //啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
                
            }
            

        }
#endif


#if 0//垃圾方法 毁我青春
    //2019-5-1 16:37:55 把上面的Map改成数组的方式..看看效率上的区别.
    //卒卒卒 不能用数组
    int charMap[127] = {-1};//最长就是26个字母了

    int currentLen = 0,leftLimit = 0,maxLen = 0;
    for(string::iterator it = s.begin(); it != s.end(); ++it)
    {
        if(charMap[*it] == -1)
        {
            ++currentLen;
            charMap[*it] = it - s.begin();
        }else{
            if(charMap[*it] >= leftLimit)
            {
                leftLimit = charMap[*it];
                currentLen = it - s.begin() - leftLimit;
            }
            else
            {
                ++currentLen;
            }

            charMap[*it] = it - s.begin();
            
        }

        if(currentLen > maxLen)
            maxLen = currentLen;

    }

#endif


#if 0
    /*这是小王第一次使用Map和Iterator做题..记录一下
    √ Accepted
      √ 987/987 cases passed (32 ms)
      √ Your runtime beats 79.45 % of cpp submissions
      √ Your memory usage beats 77.47 % of cpp submissions (10.9 MB)
    */
    //记录出现过的字母的位置..
    map<char,int> charMap;
    int currentLen = 0,maxLen = 0,leftLimit = 0;

    for(string::iterator it = s.begin(); it != s.end(); ++it)
    {
        //查找当前字符串位置的值是否出现过?
        map<char,int>::iterator itChar = charMap.find(*it);
        
        //搜索到了底部还没有出现过..那么就是全新的字符..
        //对于这一串新的字符串的影响就是应该..增加当前字符串的计数大小.
        if( itChar == charMap.end() )
        {
            //
            ++currentLen;
            
            //leftLimit = it - s.begin();
            //把这个字符添加到Map中 表示已经出现过了..
            
            charMap.insert({*it,it - s.begin()});//字符串迭代器 取字符串的值/填位置值.
            
        }else{
            //当前的字符以前出现过..

            //更新最后出现的位置..在边界的右边..那么肯定是要更新边界了..
            //it-s.begin 是当前位置..当前位置.
            //itChar->second 是上次的位置..如果上次的位置在边界右边.那么
            if(itChar->second >= leftLimit)//itChar..才是找到的位置.用找到的位置跟边界进行对比才对
            {
                leftLimit = itChar->second;
                //最新位置在更右边.那么肯定是要更新limit的
                currentLen = it - s.begin() - leftLimit;
            }
            else
            {
                //最新的位置在界限的左边.代表可以忽略掉.
                ++currentLen;
            }

            //到了这里就算截止了..后面再长似乎也不会超过这里!

            //现在有一个currentLen..需要随着这里做变化..
            //currentLen 更新到maxLen 暂时放在每个循环都处理吧..

            itChar->second = it - s.begin();
        }

    //更新最长
    if(currentLen > maxLen)
        maxLen = currentLen;

    }
#endif

#if 0
    /*
    //把字符串迭代器改成了数组取值方式.效率提高了一些
    √ Accepted
      √ 987/987 cases passed (28 ms)
      √ Your runtime beats 83.1 % of cpp submissions
      √ Your memory usage beats 80.32 % of cpp submissions (10.7 MB)
    */
    map<char,int> charMap;
    int currentLen = 0,maxLen = 0,leftLimit = 0;

    for(int i = 0;i < s.length();++i)
    {
        map<char,int>::iterator itChar = charMap.find(s[i]);
        if( itChar == charMap.end() )
        {
            ++currentLen;
            charMap.insert({s[i],i});//字符串迭代器 取字符串的值/填位置值.
        }else{
            if(itChar->second >= leftLimit)
            {
                leftLimit = itChar->second;
                currentLen = i - leftLimit;
            }else{
                ++currentLen;
            }

            itChar->second = i;

        }
        if(currentLen > maxLen)
            maxLen = currentLen;
    }
#endif

#if 999
    /*leetCode-cn 高票
    √ Accepted
      √ 987/987 cases passed (28 ms)
      √ Your runtime beats 83.1 % of cpp submissions
      √ Your memory usage beats 83.93 % of cpp submissions (10.4 MB)
    */
    vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start)
            start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = max(maxLen, i - start);
    }
#endif


    return maxLen;

    }
};

