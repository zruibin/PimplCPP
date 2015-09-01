# 遍历所有源文件并将所有目标文件指定到自定义obj目录下，但VPATH自动搜索并自动拼接
# 自定义obj自动生成与自动删除
# 添加生成静态库与动态库

PROJECT=./obj/main
MYLIB=
SYSLIB=-lpthread
CFLAG=-g
CC=g++
GCC=g++
OBJDIR=obj/

# 当前目录下带路径的所有后缀为.c的源文件
SRCS = $(shell find . -name '*.cpp')

# 要过滤的目录类型
FILTEROBJ = . ./obj

# 列出当前目录下的所有目录并过滤自定义要过滤的并转换的目录
DIRSUNSUBST = $(filter-out $(FILTEROBJ), $(shell find . -type d))
DIRS = $(foreach n, $(DIRSUNSUBST), $(subst ./, , $(n)))

# 创建目录
MKDIROBJ = $(shell mkdir -p $(OBJDIR))

# 将当前目录下所有带路径的.c源文件后缀改为.o
SRCSTOOBJECTS = $(SRCS:%.cpp=%.o)

# 去除所有.c文件的带路径中的./
SOURCES = $(foreach n, $(SRCS), $(subst ./, , $(n)))

# 将带路径的.o文件去除路径只保留文件名与后缀
OBJECTS = $(foreach n, $(SRCSTOOBJECTS), $(notdir $(n)))

# 拼接所有路径
VPATH = $(foreach n,$(DIRS), $(n):)

# 指定目录下生生成的带路径的.o文件
OBJS= $(foreach n,$(OBJECTS), $(OBJDIR)$(n))

$(MKDIROBJ):

$(PROJECT):$(OBJS)
	$(GCC) -o $@ $^

	# 生成静态库
	ar rc $(OBJDIR)lib.a $(OBJS)
	# 生成动态库
	# gcc $(SOURCES) -I -fPIC -shared -o $(OBJDIR)lib.so 

$(OBJDIR)%.o:%.cpp
	$(GCC) -c -o $@ $<


.PHONY : clean show

clean:
	rm -f $(OBJDIR)/*.o $(PROJECT)
	rm -f $(OBJDIR)lib.a
	rm -f $(OBJDIR)lib.so
	rmdir -p $(OBJDIR)



show:
	@echo '要过滤的目录类型:' $(FILTEROBJ)
	@echo '过滤的但没有转换的目录:' $(DIRSUNSUBST)
	@echo '列出当前目录下的所有目录并过滤自定义要过滤的并转换的目录:' $(DIRS)
	@echo '创建目录-MKDIROBJ:' $(OBJDIR)
	@echo '当前目录下带路径的所有后缀为.cpp的源文件:' $(SRCS)
	@echo '将当前目录下所有带路径的.cpp源文件后缀改为.o:' $(SRCSTOOBJECTS)
	@echo '去除所有.cpp文件的带路径中的./:' $(SOURCES)
	@echo '将带路径的.o文件去除路径只保留文件名与后缀:' $(OBJECTS)
	@echo '拼接所有路径:' $(VPATH)
	@echo '指定目录下生生成的带路径的.o文件:' $(OBJS)













