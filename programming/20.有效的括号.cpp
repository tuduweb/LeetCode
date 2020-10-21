/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
class Solution {
public:
    bool isValid(string s) {
        #if 0
        /*
        √ Accepted
          √ 76/76 cases passed (8 ms)
          √ Your runtime beats 96.77 % of cpp submissions
          √ Your memory usage beats 68.45 % of cpp submissions (8.7 MB)
        */
        //常规题 使用栈 先进后出.
        stack<char> myStack;
        for(int i = 0;i < s.length();++i)
        {
            switch (s[i])
            {
            case '(':
            case '[':
            case '{':
                //入栈
                myStack.push(s[i]);
                break;
            //其他 出栈
            default:
                if( myStack.empty() || ( (myStack.top() == '(' && s[i] != ')')
                    || (myStack.top() == '[' && s[i] != ']')
                    || (myStack.top() == '{' && s[i] != '}')) )
                    return false;
                myStack.pop();
                break;
            }
        }
        return myStack.empty();
        #endif

        #if 2
        /*
        感觉这个方法有点偷鸡 可是也偷得不是很成功..
        √ Accepted
        √ 76/76 cases passed (8 ms)
        √ Your runtime beats 96.77 % of cpp submissions
        √ Your memory usage beats 78.5 % of cpp submissions (8.5 MB)
        */
        //入栈的时候优化.
        stack<char> myStack;
        for(int i = 0; i < s.length(); ++i)
        {
            switch (s[i])
            {
            case '(':
                myStack.push(')');
                break;
            case '[':
                myStack.push(']');
                break;
            case '{':
                myStack.push('}');
                break;
            default:
                if(myStack.empty() || myStack.top() != s[i])
                    return false;
                myStack.pop();
                break;
            }
        }
        return myStack.empty();
        #endif
    }
};

