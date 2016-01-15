//
//  Class.h
//  RBCHOW
//
//  Created by RBCHOW on 16/01/15.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//


#ifndef _CLASS_H
#define _CLASS_H


#define alloc(Class) (Class *)malloc(sizeof(Class))
#define release(obj) { if(obj) { free(obj); (obj)=NULL; } }


// typedef struct objc_class Class;

typedef struct Class /*必须定义*/
{
    Class *super_class;
    Class *isa;
    const char *name;
    long version;
    long info;
    void (*description)(Class *obj);
}Class; /*可以不定义*/


void description(Class *obj);

void class_init(Class *obj);


#endif
