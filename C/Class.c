//
//  Class.c
//  RBCHOW
//
//  Created by RBCHOW on 16/01/15.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

    
#include "Class.h"
#include <stdio.h>

typedef struct Ivar
{
    const char *var;
};


Class * class_init(void)
{
    Class *obj = alloc(Class);
    obj->super_class = NULL;
    obj->isa = obj;
    obj->name = "Class";
    obj->version = 1.0;
    obj->info = 1.0;
    obj->description = description;
    obj->printIVar = printIVar;

    obj->vars->var = "varName";

    return obj;
}

Class * class_init(const char *name)
{
    Class *obj = class_init();
    obj->name = name;
    return obj;
}


void description(Class *obj)
{
    printf("%s -> %s\n", "This is Class!", obj->name);
}

void printIVar(Class *obj)
{
    printf("var printIVar ->%s\n", obj->vars->var);
}

