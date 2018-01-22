#include "stdafx.h"
#include <vector>
using namespace std;

/*
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

/*
** @brief: convert digit string to letter string array
** @param[in]: digits��The convert digit string
** return: the converted string array
Solution��
1)�����ѵ����ڣ����ڶ����ַ�����ƴ�ӡ�
2������֪�����ַ���������ǰ���£���ȡ���м�ƴ���ַ����洢��vector�ݴ���ں�����ַ�����ƴ�ӡ�
3��ƴ��������
���롰23����
��1����ʼ��һ��string ��vector ��ʼֵ������
��2������2����
��2��Ӧ�ġ�abc�������飬�������롰a������b������c�����ִ�ƴ��push_back�����顣ɾ����Ԫ�أ��м��ݴ�Ԫ�أ�������
��3������3����
��3��Ӧ�����顰def��������2������
����a���롰d������e������f�����ִ�ƴ��push_back�����飬ɾ����Ԫ�أ��м��ݴ�Ԫ�أ���a��.
����b���롰d������e������f�����ִ�ƴ��push_back�����飬ɾ����Ԫ�أ��м��ݴ�Ԫ�أ���b��.
����c���롰d������e������f�����ִ�ƴ��push_back�����飬ɾ����Ԫ�أ��м��ݴ�Ԫ�أ���c��.
"ad" "ae" "af" "bd" "be" "bf" "cd" "ce" "cf"
*/
vector<string> letterCombinations2(string digits) {
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
** @param[in]: digits��The convert digit string
** return: the converted string array
Solution��
1.����DFS��˼�����ö�١�
2.����˼·Ϊ��
2.1 �ж��ַ����Ƿ����㳤��Ҫ���������룬�������������
2.2 ͨ������������ַ����ĳ��Ƚ���DFS��ȵĿ��ơ�
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
    vector<string> nums = {};
    nums = letterCombinations("23");
    for (vector<string> tmp in nums)
    {
        cout << tmp << endl;
    }

    getchar();
    return 0;
}

