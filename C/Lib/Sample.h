//
//  Sample.h
//  RBCHOW
//
//  Created by RBCHOW on 16/01/15.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

#ifndef _SAMPLE_H
#define _SAMPLE_H


#ifndef C_Class
#define C_Class struct
#endif
 
C_Class A {
       C_Class A *A_this;
       void (*Foo)(C_Class A *A_this);
       int a;
       int b;
};
 
C_Class B{  //B继承了A
       C_Class B *B_this;  //顺序很重要
       void (*Foo)(C_Class B *Bthis); //虚函数
       int a;
       int b;
 
       int c;
};
 
 
void B_F2(C_Class B *Bthis);
 
void A_Foo(C_Class A *Athis);

void B_Foo(C_Class B *Bthis);
 
void A_Creat(struct A* p);
 
void B_Creat(struct B* p);




#endif

