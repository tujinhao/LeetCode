#include <stdio.h>

int search(int *nums, int numsSize, int target)
{
    int l = 0, r = numsSize - 1;
    int p = (r - l) / 2;
    for (int i = 0; i < numsSize; i++)
    {
        if (*(nums + p) == target)
        {
            return p;
            
        }
   
        

        else if (*(nums + p) > target)
        {
            r = p;
            p = l + (p - l -1) / 2;
            
        }
        else
        {
            l = p;
            p = p + (r - p +1) / 2;
        }
    }
    return -1;
}
int main()
{
    int nums[10] = {-1,0,3,5,9,12};
    int a = search(nums,6,3);

    printf("%d\n",a);

    return 0;
}
