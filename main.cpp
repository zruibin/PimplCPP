//
//  main.cpp
//  RBCHOW
//
//  Created by RBCHOW on 15/6/6.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//


#include <iostream>
#include "Character.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Character *ch = new Character;
    ch->getStr();
    ch->getStr2();
    
    delete ch;
    ch = NULL;
    
    return 0;
}
