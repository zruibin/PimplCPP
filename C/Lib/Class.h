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

#ifndef __cplusplus

typedef char bool;
//typedef char BOOL;
//typedef char boolean;

#define false 0;
#define true !0;

#endif /* __cplusplus */

void print(void);


typedef struct Ivar Ivar;
typedef struct objc_class Class;

typedef struct objc_class
{
    Class *super_class;
    Class *isa;
    Ivar *vars;
    const char *name;
    long version;
    long info;
    void (*description)(Class *obj);

    Class * (*copy)(Class *obj);

    void (*printIVar)(Class *obj);
}Class;

/**
 * 默认构造函数
 * @return  模拟类的对象指针
 */
Class * Class_init(void);

/**
 * 带初始化参数的构造函数
 * @param  name [description]
 * @return      [description]
 */
Class * Class_initWithName(const char *name);

/**
 * 深拷贝函数
 * @param  obj 源拷贝对象
 * @return     结果对象
 */
Class * copy(Class *obj);

void description(Class *obj);

void printIVar(Class *obj);




#endif


