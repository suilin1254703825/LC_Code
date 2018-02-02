#include "stdafx.h"
#include <vector>
using namespace std;

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.
The brackets must close in the correct order,
"()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
bool isValid(string s) {
    stack<char> stStack;
    for (int i = 0; i < s.size(); ++i)
    {
        if ('{' == s[i] || '[' == s[i] || '(' == s[i])
        {
            stStack.push(s[i]);
        }
        else if (stStack.empty())
        {
            return false;
        }
        else if (('}' == s[i] || ']' == s[i]))
        {
            // } - { = 2 , ] - [ = 2
            if (s[i] - 2 == stStack.top())
            {
                stStack.pop();
            }
            else
            {
                return false;
            }
        }
        else if (')' == s[i])
        {
            // ) - ( = 1
            if (s[i] - 1 == stStack.top())
            {
                stStack.pop();
            }
            else
            {
                return false;
            }
        }
    }

    if (stStack.empty())
    {
        return true;
    }
    return false;
}
