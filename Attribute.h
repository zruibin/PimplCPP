//
//  Attribute.h
//  RBCHOW
//
//  Created by RBCHOW on 15/6/6.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

/*
    https://gcc.gnu.org/onlinedocs/gcc/Function-Attributes.html
    http://gcc.gnu.org/onlinedocs/gcc-4.0.0/gcc/Function-Attributes.html
    __attribute__((constructor)) 在main() 之前执行,__attribute__((destructor)) 在main()执行结束之后执行.  
 */
// static  __attribute__((constructor)) void before();
// static  __attribute__((destructor)) void after();

static void before() __attribute__((constructor));
static void after() __attribute__((destructor));


#endif


























