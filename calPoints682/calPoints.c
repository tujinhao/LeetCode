#include <stdio.h>
#include <stdlib.h>
int calPoints(char **ops, int opsSize)
{
    if (0 >= opsSize)
        return 0;
    int stack[opsSize]; // 栈
    int top = -1;       // 栈顶指针
    int sum = 0;        // 累计得分
    for (int i = 0; i < opsSize; i++)
    {
        switch (ops[i][0])
        {
        case '+':
            // +获取前两轮和
            // 注意代码执行顺序 虽然 ++top 的意思是 top 加1后在使用，但是存在赋值运算符时。赋值运算符右边的会先执行 切记不是 是赋值运算符右边先执行不是左边
            stack[++top] = stack[top] + stack[top - 1];
            sum += stack[top];
            break;
        case 'D':
            // D获取上一轮的2倍
            stack[++top] = stack[top] * 2;
            sum += stack[top];
            break;
        case 'C':
            //直接出栈并减去无效分
            sum -= stack[top--];
            break;
        default:
            //正常得分入栈累加
            stack[++top] = atoi(ops[i]);
            sum += stack[top];
        }
    }
    return sum;

}
int main()
{
    char *ops[40] = {"5", "2", "C", "D", "+"};
    // char *pp = ops[100][1];
    // printf("%c\n",*pp);
    // char (*p1)[4] = ops[100][4];
    char **p2 = ops;
    int a[10] = {1,123,13123,12};
    printf("%d\n", a[-1]);

    
  //  calPoints(p2, 5);

    printf("%d\n", calPoints(p2, 5));

    //printf("%s\n", *(p2 + 1));

    printf("Hello\n");

    return 0;
}
