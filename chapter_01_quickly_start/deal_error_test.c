#include<stdio.h>
 
int main(void) {
 
    char a[100];
    int i = 0, j = 0;
 
    printf("input:");
    fgets(a, 100, stdin);  // gcc中 gets puts函数不能用!! stdin 键盘输入.
    for (i = 0; * (a + i) != '\0'; i++) {
        if (*(a + i) != ' ')
            a[j++] = a[i] ;
    }
    a[j] = '\0';    //这里一定要记得加上'\0'结束符,j在最后
    //一次执行的时候已经自加1了,所以这里不是a[j+1]='\0'.
    printf("output:");
    fputs(a, stdout);
 
    return 0;
}
