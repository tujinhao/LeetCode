#include <stdio.h>
int numSubarraysWithSum(int *nums, int numsSize, int goal)
{
    int left1 = 0, left2 = 0, right = 0, sum1 = 0, res = 0, sum2 = 0;
    for (right = 0; right < numsSize; right++)
    {
        sum1 += *(nums + right);
        sum2 += *(nums + right);
        while (left1 <= right && sum1 > goal)
        {
            sum1 -= *(nums + left1++);
           
        }
        while (left2 <= right && sum2 >= goal)
        {
            sum2 -= *(nums + left2++);
           
        }
        res +=left2 - left1;
    }
    return res;
}

int main()
{
    int nums[10] = {1, 0, 1, 0, 1,0}, goal = 2;
    printf("%d\n", sizeof(nums) / 4);

    int res = numSubarraysWithSum(nums, 6, 2);
    printf("%d\n", res);

    return 0;
}
