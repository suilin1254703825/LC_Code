#include "stdafx.h"
#include <vector>
using namespace std;

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
[
"((()))",
"(()())",
"(())()",
"()(())",
"()()()"
]
*/
void DFSgenerateParenthesis(vector<string>& vecRet, string strParen, int nIndex, int nLeft, int nRight)
{
    if (nLeft == nIndex && nRight == nIndex)
    {
        vecRet.push_back(strParen);
    }

    if (nLeft < nIndex)
    {
        DFSgenerateParenthesis(vecRet, strParen + "(", nIndex, nLeft + 1, nRight);
    }

    if (nLeft > nRight)
    {
        DFSgenerateParenthesis(vecRet, strParen + ")", nIndex, nLeft, nRight + 1);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> vecParent;
    DFSgenerateParenthesis(vecParent, "", n, 0, 0);
    return vecParent;
}
