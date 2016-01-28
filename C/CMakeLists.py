#! /usr/bin/python
# coding=utf-8
# 
# CMake.py
# zruibin.asia
#
# Created by Ruibin.Chow on 2016/01/27.
# Copyright (c) 2016年 www.zruibin.asia. All rights reserved.
#

import os, os.path, shutil

MAIN_DIR = './'
BUILD_DIR = 'build'

CMakeLists = 'CMakeLists.txt'

SUB_MAKELISTS_CONTENT = """
# 查找当前目录下的所有源文件
# 并将名称保存到变量中
aux_source_directory(. %s)

# 生成链接库
add_library(%s ${%s})
"""

MAIN_MAKELISTS_CONTENT = """
cmake_minimum_required(VERSION 2.8)
project(%s)

message(${PROJECT_SOURCE_DIR})

set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_C_FLAGS "-g -EL -Wa,-mips32r2 -march=24kf -mtune=24kf -I/home/zhangyx/baisiqiao/cs_rootfs_1.2.27/cross_rootfs/include -L/home/zhangyx/baisiqiao/cs_rootfs_1.2.27/cross_rootfs/lib")
set(CMAKE_CXX_COMPILER "gcc")

# Add header file include directories
include_directories(%s)

# Add block directories
#add_subdirectory(dir)
%s

# Add the source in project root directory
aux_source_directory(. DIRSRCS)

# Target
add_executable(${PROJECT_NAME} ${DIRSRCS})
target_link_libraries(${PROJECT_NAME} %s)
"""

includeList = []
libList = []


def convert_character(string, origin_string, replace_string):
    """用指定的字符替换文本中指定的字符"""
    string = string.replace(origin_string, replace_string)
    return string

def writeContentToFile(fileName, content, mode='w'):
    """以特定的方式向文件写内容"""
    fp = open(fileName, mode)
    fp.write(content)
    fp.close()
    pass

def genEverySubDirCMakeList(DIR, Files):
    if DIR == MAIN_DIR:
        return  

    fileName = DIR + '/' + CMakeLists
    lib = convert_character(DIR, '.', '')
    lib = convert_character(lib, '/', '_')
    lib = 'lib' + lib
    lib_src = lib + '_SRCS'
    content = SUB_MAKELISTS_CONTENT % (lib_src, lib, lib_src)
    writeContentToFile(fileName, content)
    
    includeList.append(DIR)
    libList.append(lib)
    pass

def make(DIR):
    """返回指定目录下所有文件的集合"""
    claenAll()
    array = []
    for root, dirs, files in os.walk(DIR):
        genEverySubDirCMakeList(root, files)
        # print includeList
        # print libList
    project_name = 'Main'
    includeStr = " ".join(includeList)
    libStr = " ".join(libList)

    add_subdirectory = ''
    for include in includeList:
        add_subdirectory = add_subdirectory + '\n' + ('add_subdirectory(%s)' % include)
          
    content = MAIN_MAKELISTS_CONTENT % (project_name, includeStr, add_subdirectory, libStr)
    print content
    fileName = MAIN_DIR + '/' + CMakeLists
    writeContentToFile(fileName, content)
    os.mkdir(MAIN_DIR + BUILD_DIR)  
    pass

def  claenAll():
    if os.path.exists(MAIN_DIR + BUILD_DIR):
        shutil.rmtree(MAIN_DIR + BUILD_DIR)
    for root, dirs, files in os.walk(MAIN_DIR):
        targetFile = root + '/' + CMakeLists
        if os.path.exists(targetFile):
            os.remove(targetFile)
    pass


if __name__ == '__main__':
    make(MAIN_DIR)
    # claenAll()
    pass





