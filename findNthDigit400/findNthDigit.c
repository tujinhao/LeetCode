#include <stdio.h>
#include <math.h>
//未完成
int findNthDigit(int n)
{
    // 找数学规律，先判断n所在的数的位数，如下
    // 如果把0排除
    // 一位数的总字符数 1 * 9
    // 两位数的总字符数 2 * 90
    // 三位数的总字符数 3 * 900
    // 四位数的总字符数 4 * 9000
    // 五位数的总字符数 5 * 90000
    // 以此类推，可以看作 j * i，i *= 10，j++

    int i, j;
    // 用如上规律判断n所在数的位数
    // 需要考虑越界问题，由于j = 9时，i * j = 9 * 900000000 > 2^31-1
    // 所以在j = 9时提前结束循环，并且我们可以知道n一定是一个9位数
    for (i = 9, j = 1; j < 9; j++, i *= 10)
    {
        n -= i * j;
        if (n < 0)
        {
            break;
        }
    }
    // 如果循环是因为n被减为负数停止的，那么把n最后减的数加回去
    // 如果循环时因为j = 9停止的，这时候我们直接判断其为9位数但没有减，所以不用加
    if (j < 9)
    {
        n += i * j;
    }
    // 此时的n为j位数的字符数量
    // n在第x + 1个数内
    // n是第x + 1个数的第y位
    int x = n / j;
    int y = n % j;
    // 如果y=0则n是第x个数的最后一位
    if (y == 0)
    {
        int num = pow(10, j - 1) + x - 1;
        return num % 10;
    }
    // 否则就是第x + 1个数的第y位
    else
    {
        int num = pow(10, j - 1) + x;
        return ((num / (int)pow(10, j - y) % 10));
    }
}

int main()
{
    printf("%d\n",findNthDigit(9));

    printf("Hello\n");

    return 0;
}
