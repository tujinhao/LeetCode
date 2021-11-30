#include <stdio.h>

void moveZeroes(int* nums, int numsSize){
    int j = 0;
    for(int i = 0;i < numsSize ; i++){
        if(*(nums + i) != 0){
            if(i > j){
            *(nums + j) = *(nums + i);
            *(nums + i) = 0;
            }
            j++;
            

        }
        

    }


}


int main()
{
    int nums[10] = {0,1, 0, 3, 0, 5,6,0};

	printf("Hello\n");
	moveZeroes(nums,7);
    for(int i = 0 ; i < 7;i++){
        printf("%d",*(nums + i));
    }
	return 0; 

}