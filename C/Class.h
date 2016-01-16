//
//  Class.h
//  RBCHOW
//
//  Created by RBCHOW on 16/01/15.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//


#ifndef _CLASS_H
#define _CLASS_H

#include <stdlib.h>

#define alloc(Class) (Class *)malloc(sizeof(Class))
#define release(obj) { if(obj) { free(obj); (obj)=NULL; } }

typedef struct Ivar;

// typedef struct objc_class Class;

typedef struct Class /*必须定义*/
{
    Class *super_class;
    Class *isa;
    Ivar *vars;
    const char *name;
    long version;
    long info;
    void (*description)(Class *obj);

    void (*printIVar)(Class *obj);
}Class; /*可以不定义*/

/**
 * 默认构造函数
 * @return  模拟类的对象指针
 */
Class * class_init(void);

/**
 * 带初始化参数的构造函数
 * @param  name [description]
 * @return      [description]
 */
Class * class_init(const char *name);

void description(Class *obj);

void printIVar(Class *obj);

#endif
