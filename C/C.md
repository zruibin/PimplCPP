[http://blog.csdn.net/fupozsl/article/details/1779850](http://blog.csdn.net/fupozsl/article/details/1779850)

>在面向对象的语言里面，出现了类的概念。这是编程思想的一种进化。所谓类：是对特定数据的特定操作的集合体。所以说类包含了两个范畴：数据和操作。而C语言中的struct仅仅是数据的集合。

####1．实例：下面先从一个小例子看起

```
#ifndef C_Class
#define C_Class struct
#endif

C_Class A {
	C_Class A *A_this;
	void (*Foo)(C_Class A *A_this);
	int a;
	int b;
};

C_Class B{ //B继承了A
	C_Class B *B_this; //顺序很重要
	void (*Foo)(C_Class B *Bthis); //虚函数
	int a;
	int b;
	int c;
};

void B_F2(C_Class B *Bthis)
{
	printf("It is B_Fun\n");
}

void A_Foo(C_Class A *Athis)
{
	printf("It is A.a=%d\n",Athis->a);//或者这里
	// exit(1);
	// printf("纯虚 不允许执行\n");//或者这里
}

void B_Foo(C_Class B *Bthis)
{
	printf("It is B.c=%d\n",Bthis->c);
}

void A_Creat(struct A* p)
{
	p->Foo=A_Foo;
	p->a=1;
	p->b=2;
	p->A_this=p;
}

void B_Creat(struct B* p)
{
	p->Foo=B_Foo;
	p->a=11;
	p->b=12;
	p->c=13;
	p->B_this=p;
}

int main(int argc, char* argv[])
{
	C_Class A *ma,a;
	C_Class B *mb,b;
	A_Creat(&a);//实例化
	B_Creat(&b);
	mb=&b;
	ma=&a;
	ma=(C_Class A*)mb;//引入多态指针
	printf("%d\n",ma->a);//可惜的就是 函数变量没有private
	ma->Foo(ma);//多态
	a.Foo(&a);//不是多态了
	B_F2(&b);//成员函数，因为效率问题不使用函数指针
	
	return 0;
}
```

#####输出结果：

```
11
It is B.c=13
It is A.a=1
It is B_Fun
```

####2．类模拟解说：

>我在网上看见过一篇文章讲述了类似的思想（据说C＋＋编程思想上有更加详细的解说，
可惜我没空看这个了，如果有知道的人说一说吧）。但是就象C++之父说的：“C++和C是两种
语言”。所以不要被他们在语法上的类似就混淆使用，那样有可能会导致一些不可预料的事情
发生。

>其实我很同意这样的观点，本文的目的也不是想用C模拟C＋＋，用一个语言去模拟另外
一个语言是完全没有意义的。我的目的是想解决C语言中，整体框架结构过于分散、以及数据
和函数脱节的问题。

>C语言的一大问题是结构松散，虽然现在好的大型程序都基本上按照一个功能一个文件的
设计方式，但是无法做到更小的颗粒化――原因就在于它的数据和函数的脱节。类和普通的
函数集合的最大区别就在于这里。类可以实例化，这样相同的函数就可以对应不同的实例化
类的变量。

>自然语言的一个特点是概括：比如说表。可以说手表，钟表，秒表等等，这样的描述用
面向对象的语言可以说是抽象（继承和多态）。但是我们更要注意到，即使对应于手表这个
种类，还是有表链的长度，表盘的颜色等等细节属性，这样细微的属性如果还用抽象，就无
法避免类膨胀的问题。所以说类用成员变量来描述这样的属性。这样实例并初始化不同的
类，就描述了不同属性的对象。

>但是在C语言中，这样做是不可能的（至少语言本身不提供这样的功能）。C语言中，如
果各个函数要共享一个变量，必须使用全局变量（一个文件内）。但是全局变量不能再次实
例化了。所以通常的办法是定义一个数组。以往C语言在处理这样的问题的时候通常的办法就
是这样，比如说socket的号，handel等等其实都是数组的下标。（不同的连接对应不同的
号，不同的窗口对应不同的handel，其实这和不同的类有不同的成员变量是一个意思）
个人认为：两种形式（数组和模拟类）并无本质的区别（如果不考虑虚函数的应用的
话），它们的唯一区别是：数组的办法将空间申请放在了“模块”内，而类模拟的办法将空间
申请留给了外部，可以说就这一点上，类模拟更加灵活。

####3．其他的话：

>我的上述思想还是很不成熟的，我的目的是想让C语言编程者能够享受面向对象编程的更
多乐趣。我们仅仅面对的是浩瀚的“黑箱”，我们的工作是堆砌代码，而且如果要更改代码功
能的时候，仅仅换一个黑箱就可以了。

>而更大的目的是促使这样的黑箱的产生。或许有一天，一种效率很好，结构很好的语言
将会出现。那个时候编程是不是就会象说话一样容易了呢？

>相信很多人都看过设计模式方面的书，大家有什么体会呢？Bridge，Proxy，Factory这些设
计模式都是基于抽象类的。使用抽象对象是这里的一个核心。

>其实我觉得框架化编程的一个核心问题是抽象，用抽象的对象构建程序的主体框架，这
是面向对象编程的普遍思想。用抽象构建骨架，再加上多态就形成了一个完整的程序。由于C
＋＋语言本身实现了继承和多态，使用这样的编程理念（理念啥意思？跟个风，嘿嘿）在C＋
＋中是十分普遍的现象，可以说Virtual（多态）是VC的灵魂。

>但是，使用C语言的我们都快把这个多态忘光光了。我常听见前辈说，类？多态？我们用
的是C，把这些忘了吧。很不幸的是，我是一个固执的人。这么好的东西，为啥不用呢。很高
兴的，在最近的一些纯C代码中，我看见了C中的多态！下面且听我慢慢道来。


1. VC中的Interface是什么

Interface：中文解释是接口，其实它表示的是一个纯虚类。不过我所要说的是，在VC中
的Interface其实就是struct，查找Interface的定义，你可以发现有这样的宏定义：

```
#Ifndef Interface
#define Interface struct
#endif
```

而且，实际上在VC中，如果一个类有Virtual的函数，则类里面会有vtable，它实际上是一个
虚函数列表。实际上C＋＋是从C发展而来的，它不过是在语言级别上支持了很多新功能，在C
语言中，我们也可以使用这样的功能，前提是我们不得不自己实现。


2．C中如何实现纯虚类（我称它为纯虚结构）


比较前面，相信大家已经豁然开朗了。使用struct组合函数指针就可以实现纯虚类。
例子： 

```
typedef struct {
	void (*Foo1)();
	char (*Foo2)();
	char* (*Foo3)(char* st);
}MyVirtualInterface;
```

这样假设我们在主体框架中要使用桥模式。（我们的主类是DoMyAct，接口具体实现类是
Act1，Act2）下面我将依次介绍这些“类”。（C中的“类”在前面有说明，这里换了一个，是使
用早期的数组的办法）

主类DoMyAct： 主类中含有MyVirtualInterface* m_pInterface; 主类有下函数：

```
DoMyAct_SetInterface(MyVirtualInterface* pInterface)
{
	m_pInterface= pInterface;
}
DoMyAct_Do()
{
if(m_pInterface==NULL) return;
	m_pInterface->Foo1();
	c=m_pInterface->Foo2();
}
```

子类Act1：实现虚结构，含有MyVirtualInterface st[MAX]; 有以下函数：

```
MyVirtualInterface* Act1_CreatInterface()
{
	index=FindValid() //对象池或者使用Malloc ！应该留在外面申请，实例化
	if(index==-1) return NULL;
	St[index].Foo1=Act1_Foo1; // Act1_Foo1要在下面具体实现
	St[index].Foo2=Act1_Foo2;
	St[index].Foo3=Act1_Foo3;
	Return &st [index];
}
```

子类Act2同上。

在main中，假设有一个对象List。List中存贮的是MyVirtualInterface指针，则有：

```
if( (p= Act1_CreatInterface()) != NULL)
	List_AddObject(&List, p); //Add All
	While(p=List_GetObject()){
	DoMyAct_SetInterface(p);//使用Interface代替了原来大篇幅的Switch Case
	DoMyAct_Do();//不要理会具体的什么样的动作，just do it
}
```

FREE ALL。

>在微系统里面，比如嵌入式，通常使用对象池的技术，这个时候可以不用考虑释放的问
题（对象池预先没有空间，使用Attach，在某个函数中申请一个数组并临时为对象池分配空
间，这样函数结束，对象池就释放了）

>但是在Pc环境下，由于程序规模比较大，更重要的是一些特殊的要求，使得对象的生命
周期必须延续到申请的那个函数体以外，就不得不使用malloc，实际上即使在C＋＋中，new
对象的自动释放始终是一个令人头疼的问题，新的标准引入了智能指针。但是就我个人而
言，我觉得将内存释放的问题完全的交给机器是不可信任的，它只能达到准最佳。
你知道设计Java的垃圾回收算法有多困难吗？现实世界是错综复杂的，在没有先验条件
下，要想得到精确的结果及其困难。所以我说程序员要时刻将free记在心上，有关程序的健
壮性和自我防御将在另外一篇文章中讲述。


3．纯虚结构的退化

>下面我们来看看如果struct里面仅仅有一个函数是什么？ 这个时候如果我们不使用
struct，仅仅使用函数指针又是什么？ 我们发现，这样就退化为普通的函数指针的使用
了。

>所以说，有的时候我觉得面向对象仅仅是一种形式，而不是一种技术。是一种观点，而
不是一种算法。但是，正如炭，石墨和钻石的关系一样，虽然分子式都是C，但是组成方法不
一样，表现就完全不一样了！
有的时候，我们经常被编程中琐碎的事情所烦恼，而偏离了重心，其实程序可进化的特
性是很重要的。有可能，第一次是不成功的，但是只要可进化，就可以发展。


4．进阶――类结构树，父类不是纯虚类的类


前面仅仅讲的是父类是纯虚结构的情况 (面向对象建议的是所有类的基类都是从纯虚类
开始的), 那么当类层次比较多的情况下，出现父类不是纯虚结构怎么办呢。嘿嘿，其实在C
中的实现比C＋＋要简单多了。因为C中各个函数是分散的。


在这里使用宏定义是一个很好的办法：比如两个类Act1，ActByOther1“继承”Act1：

```
MyVirtualInterface* ActByOther1_CreatInterface()
{
	index=FindValid() //对象池或者使用Malloc
	if(index==-1) return NULL;
	St[index].Foo1= ActByOther1_Foo1; // Act1_Foo1要在下面具体实现
	St[index].Foo2= ActByOther1_Foo2;
	St[index].Foo3= ActByOther1_Foo3;
	Return &st [index];
}

＃define ActByOther1_Foo1 Act1_Foo1 //这就是继承 嘿嘿
ActByOther1_Foo2（）{} // 可以修改其实现
ActByOther1_DoByOther() {} //当然就可以添加新的实现咯
```

5．实例――可以参见H264的源码，其中NalTool就是这样的一个纯虚结构。

类模拟中使用了大量的函数指针，结构体等等，有必须对此进行性能分析，以便观察这样的
结构对程序的整体性能有什么程度的影响。

1．函数调用的开销

```
#define COUNTER XX
void testfunc()
{
int i,k=0;
for(i=0;i<YY;i++){k++;}
}
```

>在测试程序里面，我们使用的是一个测试函数，函数体内部可以通过改变YY的值来改变
函数的耗时。测试对比是 循环调用XX次函数，和循环XX次函数内部的YY循环。
结果发现，在YY足够小，X足够大的情况下，函数调用耗时成为了主要原因。所以当一个
“简单”功能需要“反复”调用的时候，将它编写为函数将会对性能有影响。这个时候可以使用
宏，或者inline关键字。

>但是，实际上我设置XX＝10000000（1千万）的时候，才出现ms级别的耗时，对于非实时
操作（UI等等），即使是很慢的cpu（嵌入式10M级别的），也只会在XX＝10万的时候出现短
暂的函数调用耗时，所以实际上这个是可以忽略的。


2．普通函数调用和函数指针调用的开销

```
void (*tf)();
tf=testfunc;
```

测试程序修改为一个使用函数调用，一个使用函数指针调用。测试发现对时间基本没有
什么影响。（在第一次编写的时候，发现在函数调用出现耗时的情况下（XX＝1亿），函数指
针的调用要慢（release版本），调用耗时350：500。后来才发现这个影响是由于将变量申请
为全局的原因，全局变量的访问要比局部变量慢很多）。


3．函数指针和指针结构访问的开销

```
struct a {
void (*tf)();
};
```

测试程序修改为使用结构的函数指针，测试发现对时间基本没有什么影响。其实使用结
构并不会产生影响，因为结构的访问是固定偏移量的。所以结构变量的访问和普通变量的访
问对于机器码来说是一样的。

测试结论：使用类模拟的办法对性能不会产生太大的影响。

```
#include 
#include 
#define VIRTUAL
struct vtable /*虚函数表*/
{ 
    int (*p_geti)(void *); /*虚函数指针*/ 
    void (*p_print)(); /*虚函数指针*/
};

struct shape /*类shape*/
{
    void *vptr; /*虚表指针 - 指向vtable*/ 
    int i;
};

struct circle /*类circle*/
{ 
    void *vptr; /*虚表指针 - 指向vtable*/ 
    int i;
};

struct rectangle /*类rectangle*/
{ 
    void *vptr; /*虚表指针 - 指向vtable*/ 
    int i;
};

//------------------------------------
//print() - 虚函数 
/*真正调用的函数,在其内部实现调用的多态*/

VIRTUAL void print(void *self) /*参数是对象指针*/
{ 
    const struct vtable * const *cp = self; 
    (*cp)->p_print();
}

void shape_print()
{ 
    printf("this is a shape!\n");
}

void circle_print(){ 
    printf("this is a circle!\n");
}

void rectangle_print() 
{ 
    printf("this is a rectangle!\n");
}

//------------------------------------------------------
//geti() - 虚函数 

VIRTUAL int geti(void *self)
{ 
    const struct vtable * const *cp = self; 
    return (*cp)->p_geti(self); /*这一行出问题*/
}

int shape_geti(struct shape *self) /*具体函数实现时,参数还要是其类型指针*/
{ 
    return self->i;
}

int circle_geti(struct circle *self) /*具体函数实现时,参数还要是其类型指针*/
{
    return self->i;
}

int rectangle_geti(struct rectangle *self) /*具体函数实现时,参数还要是其类型指针*/
{ 
    return self->i;
}

int main(int argc, char *argv[])
{ 
    struct shape _shape; /*shape的对象_shape*/ 
    struct circle _circle; /*circle的对象_circle*/ 
    struct rectangle _rectangle; /*rectangle的对象_rect*/ /*声名虚表*/ 
    struct vtable shape_vtable; /*shape对象的vtable*/ 
    struct vtable circle_vtable; /*circle对象的vtable*/ 
    struct vtable rectangle_vtable; /*rectangle的虚表*/ /*给类分配虚表*/ 
    _shape.vptr = &shape_vtable; /*将虚表挂上*/ 
    _circle.vptr = &circle_vtable; /*将虚表挂上*/
    _rectangle.vptr = &rectangle_vtable; /*将虚表挂上*/ 
    
    /*给虚表对应相应的函数*/ 
    shape_vtable.p_print = shape_print;     /*赋值相应的函数*/ 
    circle_vtable.p_print = circle_print; /*赋值相应的函数*/ 
    rectangle_vtable.p_print = rectangle_print; /*赋值相应的函数*/ 
    
    /*给虚表对应相应的函数*/ 
    shape_vtable.p_geti = shape_geti;
    circle_vtable.p_geti = circle_geti; 
    rectangle_vtable.p_geti = rectangle_geti; /*动态联编实现多态*/ 
    
    /*因类型的不同而作出不同的反映*/ 
    print(&_shape); print(&_circle); 
    print(&_rectangle); 
    _shape.i = 5; 
    _circle.i = 19; 
    _rectangle.i = 1; 
    
    /*动态联编实现多态*/ 
    /*因类型的不同而作出不同的反映*/ 
    printf("_shape's i is : %d\n", geti(&_shape)); 
    printf("_circle's i is : %d\n", geti(&_circle)); 
    printf("_rectangle's i is : %d\n", geti(&_rectangle)); 
    
    system("PAUSE");
    
    return 0;
}
```


-

###C语言中的面向对象思想   
      
>  经常听见别人说面向对象的程序设计，以前在学校上课的时候，也有开面向对象程序设计这门课。可是不幸的是，这些都是以C＋＋，甚至VC＋＋为基础的。而更加不幸的是，多年以来我一直是一个C的使用者。在学校的时候，我主要做的是硬件上的驱动层，和底层功能层。在工作以后，又做的是手机上的软件开发，所有这些都是和C离不开的。虽然我不得不说，C＋＋是一门很好的语言，但是它的编译速度，代码效率，编译后的代码大小都限制了它在嵌入式上的应用。（但现在的嵌入式CPU越来越快，内存容量变大。我觉得用C＋＋也应该没有什么问题。这使我觉得似乎是嵌入式编译器的限制。虽然菲利普和TI好像都有C＋＋的编译器，但是似乎没人用这个。难道是太贵了？   但不管怎么说，嵌入式应用中，C语言的普遍使用是肯定的）   
    
>那么在面向过程的时代产生的C语言能否使用面向对象的思想呢？我认为是肯定可以的，C＋＋不过是在语言级别上加入了对对象的支持，同时提供了丰富的对象库。而在C语言下，我们只好自力更生了。   
    

####一、面向对象思想的目的是框架化，手段是抽象   
    
>相信很多人都明白面向对象讲了什么：类，抽象类，继承，多态。但是是什么原因促使这些概念的产生呢？   
    
>打个比方说：你去买显示器，然而显示器的品牌样式是多种多样的，你在买的过程中发生的事情也是不可预测的。对于这样的事情，我们在程序语言中如何去描述呢。面向对象的思想就是为了解决这样的问题。编写一个程序（甚至说是一个工程），从无到用是困难的，从有到丰富是更加困难的。面向对象将程序的各个行为化为对象，而又用抽象的办法将这些对象归类（抽象），从而将错综复杂的事情简化为几个主要的有机组合（框架化）。   
    
>其实我们的身边很多东西都是这样组成的：比如说电脑：电脑是由主板，CPU加上各种卡组成的。这就是一个框架化。而忽略不同的CPU，不同的主板，不同的声卡，网卡，显卡的区别，这就是抽象。再比如说现在的教育网：是由主核心节点：清华，北大，北邮等几个，然后是各个子节点，依次组成了整个教育网网络。   
    
>所以我觉得面向对象的编程思想就是：一个大型工程是分层次结构的，每层又由抽象的结构连接为整体（框架化），各个抽象结构之间是彼此独立的，可以独立进化（继承，多态）。层次之间，结构之间各有统一的通讯方式（通常是消息，事件机制）。   
    
####二、以前C语言编程中常用的“面向对象”方法   
    
>其实C语言诞生以来，人们就想了很多办法来体现“面向对象”的思想。下面就来说说我所知道的方法。先说一些大家熟悉的东东，慢慢再讲诡异的。呵呵      
      
   
1. 宏定义：   
        
有的人不禁要问，宏定义怎么扯到这里来了，我们可以先看一个简单的例子：   
  
```
＃define   MacroFunction     Afunction   
```

   然后在程序里面你调用了大量的AFunction，但是有一天，你突然发现你要用BFunction了，（不过AFunction又不能不要，很有可能你以后还要调用），这个时候，你就可以＃define   MacroFunction     Bfunction来达到这样的目的。
   
      
当然，不得不说这样的办法是too simple，sometime na&iuml;ve的，因为一个很滑稽的问题是如果我一般要改为BFunction，一半不变怎么办？那就只好查找替换了。   

    
2．静态的入口函数，保证函数名相同，利用标志位调用子函数：
   
	
这样的典型应用很多，比如说网卡驱动里面有一个入口函数Nilan（int   FunctionCode，Para*）。具体的参数是什么记不清楚了。不过NiLan的主体是这样的：
	
```
Long Nilan(int FunctionCode，Para*){   
    
Switch(FunctionCode){   
    
Case SendPacket: send(….)   
    
Case ReceivePacket: receive(…)   
    
…..   
    
}   
```

  写到这里大家明白什么意思了吧。保证相同的函数名就是说：网卡驱动是和pNA+协议栈互连的，那么如何保证pNA+协议栈和不同的驱动都兼容呢，一个简单的办法就是仅仅使用一个入口函数。通过改变如果函数的参数值，来调用内部的各个函数。这样的做法是可以进化的：如果以后想调用新的函数，增加相应的函数参数值就好了。如果我们将网卡驱动和pNA+协议栈看作两个层的话，我们可以发现：   
    
  层与层之间的互连接口是很小的（这里是一个入口函数），一般是采用名字解析的办法而不是具体的函数调用（利用FunctionCode调用函数，Nilan仅仅实现名字解析的功能）――！接口限制和名字解析   
    
  接口限制：层与层之间仅仅知道有限的函数   
    
  名字解析：层与层之间建立共同的名字与函数的对应关系，之间利用名字调用功能。   
    
    
    
3．CALLBACK函数。   
    
  我觉得这是C语言的一个创举，虽然它很简单，就象如何把鸡蛋竖起来一样，但是你如果没想到的话，嘿嘿。如果说静态入口函数实现了一个可管理的宏观的话，CallBack就是实现了一个可进化的微观：它使得一个函数可以在不重新编译的情况下实现功能的添加！但是在最最早期的时候，也有蛮多人持反对态度，因为它用了函数指针。函数指针虽然灵活，但是由于它要访问内存两次才可以调用到函数，第一次访问函数指针，第二次才是真正的函数调用。它的效率是不如普通函数的。但是在一个不太苛刻的环境下，函数调用本身就不怎么耗时，函数指针的性能又不是特别糟糕，使用函数指针其实是一个最好的选择。但是函数指针除了性能，最麻烦的地方就是会导致程序的“支离破碎”。试想：在程序中，你读到一个函数指针的时候，如果你愣是不知道这个函数指针指向的是哪个函数，那个感觉真的很糟糕。（可以看后面的文章，要使用先进的程序框架，避免这样的情况）   
    
####三、Event和Message   
    
  看了上面的描述，相信大家多少有些明白为什么要使用Event和Message了。具体的函数调用会带来很多的问题（虽然从效率上讲，这样做是很好的）。为了提高程序的灵活性，Event和Message的办法产生了。用名字解析的办法代替通常的函数调用，这样，如果双方对这样的解析是一致的话，就可以达到一个统一。不过Event和Message的作用还不仅仅是如此。   
    
  Event和Message还有建立进程间通信的功能。进程将自己的消息发给“控制中心”（简单的就是一个消息队列，和一个while循环不断的取消息队列的内容并执行），控制程序得到消息，分发给相应的进程，这样其他进程就可以得到这个消息并进行响应。   
    
  Event和Message是很灵活的，因为你可以随时添加或者关闭一个进程，（仅仅需要添加分发消息的列表就可以了）Event和Message从程序实现上将我觉得是一样的，只不过概念不同。Event多用于指一个动作，比如硬件发生了什么事情，需要调用一个什么函数等等。Message多用于指一个指示，比如什么程序发生了什么操作命令等等。   
    
####四、小结   
    
  其实编程序和写文章一样，都是先有一个提纲，然后慢慢的丰富。先抽象化得到程序的骨架，然后再考虑各个方面的其他内容：程序极端的时候会发生什么问题？程序的这个地方的功能现在还不完善，以后再完善会有什么问题？程序是不是可以扩展的？  


--

[http://blog.chinaunix.net/uid-20804770-id-2369713.html](http://blog.chinaunix.net/uid-20804770-id-2369713.html)


```
#include <stdio.h>
#include <malloc.h>
//本程序用于研究用C中的struct结构模拟C++中的类，以函数指针的方式为struct添加对成员函数的支持
//定义一个“类”
typedef  struct _myclass 
{ 
		int a;
		int b;
		int (*max)(int c,int d);
		int (*min)(int c,int d);
		int (*addab)(struct _myclass *t);
} myclass; 

//类成员函数１，２的操作数与类成员变量无关，那么函数的定义方法和C++中一样
int mbmax(int a,int b){
	return (a>b?a:b);
	}
	
int mbmin(int a,int b){
	return (b<a?b:a);
	}
	
//类成员函数的操作数与类成员变量有关，那么该函数需要当前类实例的地址做为输入，有没有高手可以不用当前类实例的地址就可以解决这个问题？
//进一步需要指出的是，如果一个成员函数通过调用其它成员函数间接操作了类成员变量，那么这个函数也需要传入当前的类实例地址
//唉，有没有办法自动获得这个this指针呢。。。。。。。
int mbaddab(myclass *t){
	return t->a+t->b;
	}

//相当于C++的类构造函数，用于创建一个类实例，并初始化这个类实例,构造函数命名采用　类名init 的方式。
myclass * myclassinit(){
	 myclass *t=(myclass  *) malloc(sizeof(myclass));
	 t->a=1;
	 t->b=1;
	 t->max=mbmax;
	 t->min=mbmin;
	 t->addab=mbaddab;
	 return t;
	}

	
int main(){
	myclass *tt=myclassinit();  //类的创建方法只要一条语句就可以完成，达到了和C++中new类似的效果
	
	printf("the max number is %d\n",tt->max(4,8));
	printf("the min number is %d\n",tt->min(4,8));
	printf("a plus b is %d\n",tt->addab(tt));
	return 0;
}

```