//
//  Class.c
//  RBCHOW
//
//  Created by RBCHOW on 16/01/15.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

    
#include "Class.h"
#include <stdio.h>
#include <string.h>

typedef struct Ivar
{
    const char *var;
};


Class * Class_init(void)
{
    Class *obj = alloc(Class);
    obj->super_class = NULL;
    obj->isa = obj;
    obj->name = "Class";
    obj->version = 1.0;
    obj->info = 1.0;
    obj->description = description;
    obj->copy = copy;
    obj->printIVar = printIVar;

    obj->vars->var = "varName";

    return obj;
}

Class * Class_init(const char *name)
{
    Class *obj = Class_init();
    obj->name = name;
    return obj;
}


void description(Class *obj)
{
    printf("%s -> %s\n", "This is Class!", obj->name);
}

Class * copy(Class *obj)
{
    Class *object = alloc(Class);
    
    /**
     * 函数原型: void *memcpy(void*dest, const void *src, size_t n);
     * 功能: 由src指向地址为起始地址的连续n个字节的数据复制到以destin指向地址为起始地址的空间内。
     * 头文件: #include<string.h>
     * 返回值: 函数返回一个指向dest的指针。
     */
    memcpy(object, obj, sizeof(Class));

    return object;
}

void printIVar(Class *obj)
{
    printf("var printIVar ->%s\n", obj->vars->var);
}

