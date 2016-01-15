//
//  Class.c
//  RBCHOW
//
//  Created by RBCHOW on 16/01/15.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

    
#include "Class.h"
#include <stdio.h>

void description(Class *obj)
{
    printf("%s -> %s\n", "This is Class!", obj->name);
}

void class_init(Class *obj)
{
    obj->super_class = NULL;
    obj->isa = obj;
    obj->name = "Class";
    obj->version = 1.0;
    obj->info = 1.0;
    obj->description = description;
}



