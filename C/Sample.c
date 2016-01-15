//
//  Sample.c
//  RBCHOW
//
//  Created by RBCHOW on 16/01/15.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

    
#include "Sample.h"
#include <stdio.h>


void B_F2(C_Class B *Bthis)
{
       printf("It is B_Fun\n");
}
 
void A_Foo(C_Class A *Athis)
{
       printf("It is A.a=%d\n",Athis->a);//或者这里
//     exit(1);
//     printf("纯虚 不允许执行\n");//或者这里
}
 
void B_Foo(C_Class B *Bthis)
{
       printf("It is B.c=%d\n",Bthis->c);
}
 
void A_Creat(struct A* p)
{
       p->Foo=A_Foo;
       p->a=1;
       p->b=2; 
       p->A_this=p;
}
 
 
void B_Creat(struct B* p)
{
       p->Foo=B_Foo;
       p->a=11;
       p->b=12;      
       p->c=13;
       p->B_this=p;
}


