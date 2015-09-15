//
//  Character.cpp
//  RBCHOW
//
//  Created by RBCHOW on 15/6/6.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

    
#include "Character.h"
#include <stdio.h>

namespace RBSpace {
    
    
class Character::CharacterImpl
{
public:
    CharacterImpl(int _num)
    {
        this->num = _num;
        this->description();
    }
    
    int getNmu()
    {
//        printf("num:%d\n", this->num);
        return this->num;
    }
    
private:
    int num;

    void description(void) const
    {
        printf("Character::CharacterImpl->description\n");
    }
};


Character::Character(void)
{
    this->imp = new Character::CharacterImpl(1);
    this->imp->description();
}

Character::~Character(void)
{
    delete this->imp;
    this->imp = NULL;
}

int Character::getStr() 
{
    printf("num:%d\n", this->imp->getNmu());
    return 0;
}

int Character::getStr2()
{
    printf("num+num:%d\n", this->imp->getNmu() + this->imp->getNmu());
    return 0;
}
    
} // end of namespace








