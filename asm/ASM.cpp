//
//  ASM.cpp
//  RBCHOW
//
//  Created by RBCHOW on 15/9/16.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

#include "ASM.h"
#include <stdio.h>

void testASM001(void)
{
    int x = 10, y;   
    __asm("movl %1, %%eax;" "movl %%eax, %0;" :"=r"(y) :"r"(x) :"%eax"); 
    printf("y=%d\n", y);
}

// int plus(void)
// {
//     int a,b,c;
//     a=2;
//     b=1;

//     __asm(
//     "add %1,%0\n\t":"+r"(a):"r"(b)
//     );

//     printf("c=%d\n", c);
//     return 0;
// }









