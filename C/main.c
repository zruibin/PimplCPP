
#include <stdio.h>
#include <assert.h>

#include "Class.h"
#include "Sample.h"


int main(int argc, char* argv[])
{
    C_Class A *ma,a;
    C_Class B *mb,b;

    A_Creat(&a);//实例
    B_Creat(&b);
    mb=&b;
    ma=&a;

    ma=(C_Class A*)mb;//引入多态指针
    printf("%d\n",ma->a);//可惜的就是 函数变量没有priva
    ma->Foo(ma);//多态
    a.Foo(&a);//不是多态了
    B_F2(&b);//成员函数，因为效率问题不使用函数指针

    bool t = true;
    if (t) printf("true\n");

    if (!t) {
        printf("false\n");
    } else {
        printf("true\n");
    }


//    Class *obj = Class_init();
    Class *obj = Class_initWithName("Class with init Name");
    printf("obj version:%ld\n", obj->version);
    // obj->name = "Class 2";
    obj->description(obj);
    printf("isa:%p -- obj:%p\n",  obj->isa, obj);

    // printf("var->%s\n", obj->vars->vars); //不可，有访问限制
    obj->printIVar(obj);

    printf("------------------------------\n");
    Class *temp = obj->copy(obj);
    temp->name = "temp object";
    temp->description(temp);
    obj->description(obj);
    printf("------------------------------\n");

    release(obj);
    assert(temp != NULL);
    release(temp);

    return 0;
}
