//
//  RBMacros.h
//  RBCHOW
//
//  Created by RBCHOW on 15/9/17.
//  Copyright (c) 2015年 www.zruibin.asia. All rights reserved.
//

#ifndef RBMACROS_H_
#define RBMACROS_H_

#define _DEBUG 1

#ifdef	_DEBUG
// ANSI C标准中有几个标准预定义宏（也是常用的）：
// __LINE__：在源代码中插入当前源代码行号；
// __FILE__：在源文件中插入当前源文件名；
// __DATE__：在源文件中插入当前的编译日期
// __TIME__：在源文件中插入当前编译时间；
// __STDC__：当要求程序严格遵循ANSI C标准时该标识被赋值为1；
// __cplusplus：当编写C++程序时该标识符被定义。

#define DLog(format, arg...) do { fprintf(stderr, "[%s:%d] " format , __FILE__, __LINE__, ##arg); } while (0)  

#else
#define DLog(format, ...)
#endif


#define SAFE_FREE(p) { if(p) { free(p); (p)=NULL; } }

#define EMPTY_STRING ""







#endif









