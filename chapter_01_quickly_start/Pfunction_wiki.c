/* 例一：函数指针直接调用 */
/*
 * 这个文件 是从wiki上抄过来的，说明了函数指针的用法，在主函数中定义一个指针指向函数的地址，
 * 之后可以直接将指针变量作为函数名称来使用。这说明函数在申明之后就有一个固定的地址，我之前打印出
 * 的函数地址都一样是有道理的，可以试试打印函数里面的变量的地址来验证老刘的说法。
 * 
 * 
 */
# ifndef __cplusplus
    # include <stdio.h>
# else
    # include <cstdio>
# endif

int max(int x, int y)
{
    return x > y ? x : y;
}

int main(void)
{
    /* p 是函数指针 */
    int (* p)(int, int) = & max; // &可以省略
    int a, b, c, d;

    printf("please input 3 numbers:");
    scanf("%d %d %d", & a, & b, & c);

    /* 与直接调用函数等价，d = max(max(a, b), c) */
    d = p(p(a, b), c); 

    printf("the maxumum number is: %d\n", d);

    return 0;
}
