/*
在整数数组中，如果一个整数的出现频次和它的数值大小相等，我们就称这个整数为「幸运数」。

给你一个整数数组 arr，请你从中找出并返回一个幸运数。

如果数组中存在多个幸运数，只需返回 最大 的那个。
如果数组中不含幸运数，则返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-lucky-integer-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findLucky(int *arr, int arrSize)
{
    int *hash = (int *)malloc(sizeof(int) * arrSize);
    memset(hash, 0, sizeof(int) * arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] <= arrSize)
            hash[arr[i] - 1]++;
    }
    for (int i = arrSize - 1; i >= 0; i--)
    {
        if (hash[i] == i + 1)
            return i + 1;
    }
    return -1;
}

int main()
{
    int nums[10] = {0, 1, 0, 3, 0, 5, 6, 0};

    printf("Hello\n");
    printf("%d\n", findLucky(nums, 8));

    return 0;
}
