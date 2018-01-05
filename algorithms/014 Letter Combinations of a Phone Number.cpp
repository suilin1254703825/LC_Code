#include "stdafx.h"
#include <vector>
using namespace std;

/*
** @brief: convert digit string to letter string array
** @param[in]: digits，The convert digit string
** return: the converted string array
Solution1：
1)本题难点在于，存在多组字符串的拼接。
2）在已知输入字符串数量的前提下，采取将中间拼接字符串存储在vector暂存便于后面的字符串的拼接。
3）拼接样例：
输入“23”：
（1）初始化一个string 的vector 初始值“”；
（2）处理“2”：
将2对应的“abc”的数组，将“”与“a”、“b”、“c”的字串拼接push_back进数组。删除首元素（中间暂存元素）“”。
（3）处理“3”：
将3对应的数组“def”，类似2操作：
将“a”与“d”、“e”、“f”的字串拼接push_back进数组，删除首元素（中间暂存元素）“a”.
将“b”与“d”、“e”、“f”的字串拼接push_back进数组，删除首元素（中间暂存元素）“b”.
将“c”与“d”、“e”、“f”的字串拼接push_back进数组，删除首元素（中间暂存元素）“c”.
"ad" "ae" "af" "bd" "be" "bf" "cd" "ce" "cf"
*/
vector<string> letterCombinationsDire(string digits) {
    vector<string > strNum = { "0", "1","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector <string> strRet;
    if (0 == digits.size())
    {
        return strRet;
    }
    strRet.push_back("");
    for (int i = 0; i < digits.size(); ++i)
    {
        int nSize = strRet.size();
        string strTmp = strNum[digits[i] - '0'];
        for (int j = 0; j < nSize; ++j)
        {
            for (int k = 0; k < strTmp.size(); ++k)
            {
                strRet.push_back(strRet[0] + strTmp[k]);
            }
            strRet.erase(strRet.begin());
        }
    }
    return strRet;
}

void DFSletterCombinations(vector<string>& vecRet, string digits, string strLetter, int nIndex)
{
    vector<string > strNum = { "0", "1","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    if (nIndex == digits.size())
    {
        vecRet.push_back(strLetter);
    }
    else
    {
        string strTmp = strNum[digits[nIndex] - '0'];
        for (int i = 0; i < strTmp.size(); ++i)
        {
            string strComb = strLetter + strTmp[i];
            DFSletterCombinations(vecRet, digits, strComb, nIndex + 1);
        }
    }
}
/*
** @brief: convert digit string to letter string array
** @param[in]: digits，The convert digit string
** return: the converted string array
Solution2：
1.利用DFS的思想进行枚举。
2.基本思路为：
2.1 判断字符串是否满足长度要求，满足则导入，否则继续遍历。
2.2 通过传入的数字字符串的长度进行DFS深度的控制。
*/
vector<string> letterCombinations(string digits) {
    vector<string > strNum = { "0", "1","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector <string> vecRet;
    if (0 == digits.size())
    {
        return vecRet;
    }
    string strTemp = "";
    DFSletterCombinations(vecRet, digits, strTemp, 0);

    return vecRet;
}

int main()
{
    vector<string> strRet;
    strRet = letterCombinations("23");
    cout << strRet << endl;

    getchar();
    return 0;
}

