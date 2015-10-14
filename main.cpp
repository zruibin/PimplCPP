//
//  main.cpp
//  RBCHOW
//
//  Created by RBCHOW on 15/6/6.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//


#include <iostream>
#include "Character.h"
#include "Attribute.h"
#include "ASM.h"
#include "RBMacros.h"
#include "HttpTest.h"
#include "ThreadTest.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    using RBSpace::Character;
    Character *ch = new Character;
    ch->getStr();
    ch->getStr2();
    
    delete ch;
    ch = NULL;

    DLog("test:%s", "zruibin\n");
    
    testASM001();

    // RBSpace::testHttpClient(); //测试curl
    RBSpace::threadTest(); //测试多线程

    return 0;
}








