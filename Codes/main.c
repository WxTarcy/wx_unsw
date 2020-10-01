#include <stdio.h>

int main ()
{
    int  var=10;
    int b=20;
    int  *ptr;
    int  *pptr;
    ptr=&var;
    pptr=&b;
    *ptr=*pptr+*ptr;
    //pptr=ptr;
    *pptr=2*(*ptr);
    /* 获取 var 的地址 */
    //ptr = &var;

    /* 使用运算符 & 获取 ptr 的地址 */
    //pptr = &ptr;

    /* 使用 pptr 获取值 */
    printf("Value of var = %d\n", var );
    printf("Value available at *ptr = %d\n", *ptr );
    printf("Value available at **pptr = %d\n", *pptr);
    printf("Value available at **pptr = %d\n", b);

    return 0;
}