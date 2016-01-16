//
//  main.c
//  RBCHOW
//
//  Created by RBCHOW on 16/01/15.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//



#include <stdio.h>
#include <stdlib.h>

#include "Class.h"
#include "Sample.h"

 

int main(int argc, char* argv[])
{
       C_Class A *ma,a;
       C_Class B *mb,b;
 
       A_Creat(&a);//实例化
       B_Creat(&b);
 
       mb=&b;
       ma=&a;
 
       ma=(C_Class A*)mb;//引入多态指针
       printf("%d\n",ma->a);//可惜的就是 函数变量没有private
       ma->Foo(ma);//多态
       a.Foo(&a);//不是多态了
       B_F2(&b);//成员函数，因为效率问题不使用函数指针



       Class *obj = alloc(Class);
       class_init(obj);
       printf("obj version:%d\n", obj->version);
       obj->name = "Class 2";
       obj->description(obj);
       printf("isa:%p -- obj:%p\n",  obj->isa, obj);

       // printf("var->%s\n", obj->vars->vars); //不可，有访问限制
       obj->printIVar(obj);

       release(obj);

       return 0;
}








