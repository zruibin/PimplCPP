//
//  Character.h
//  RBCHOW
//
//  Created by RBCHOW on 15/6/6.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

//http://blog.csdn.net/lihao21/article/details/47610309

#ifndef CHARACTER_H_
#define CHARACTER_H_

namespace RBSpace {
 
class Character {
    
public:
    Character(void);
    virtual ~Character(void);

    int getStr();
    int getStr2();

private:

    class CharacterImpl;
    CharacterImpl *imp;
};   
    
    
 
} // end of namespace

#endif

