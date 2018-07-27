/*
从排序数组中删除重复项
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
*/
#include <iostream>
#include <vector>
#include "data_struct.h"

/*
时间复杂度：O(n)
空间复杂度：O(1)
45ms的运行时间 耗时太长考虑不删除数据项的方案
*/
int removeDuplicates(vector<int>& nums) {
    if (nums.size() < 2)
    {
        return nums.size();
    }

    for (auto iter = nums.begin(); iter < nums.end() - 1; )
    {
        if (*iter == *(iter + 1))
        {
            iter = nums.erase(iter);
        }
        else
        {
            ++iter;
        }
    }
    return nums.size();
}


int removeDuplicates(vector<int>& nums) {
    int i = 0, j = 1;
    for (; i < nums.size(); ++i)
    {
        if (nums[j] != nums[i])
        {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;

}

int main(int argc, char const *argv[])
{
    /* code */
    
    return 0;
}
