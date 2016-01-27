cmake_minimum_required(VERSION 2.8)
project(CTest)

message(${PROJECT_SOURCE_DIR})

set(CMAKE_C_COMPILER "gcc")
#set(CMAKE_C_FLAGS "-g -EL -Wa,-mips32r2 -march=24kf -mtune=24kf -I/home/zhangyx/baisiqiao/cs_rootfs_1.2.27/cross_rootfs/include -L/home/zhangyx/baisiqiao/cs_rootfs_1.2.27/cross_rootfs/lib")
set(CMAKE_CXX_COMPILER "gcc")

# Add the source in project root directory
aux_source_directory(. DIRSRCS)

# Add header file include directories
include_directories(./ ./Lib)

# Add block directories
add_subdirectory(Lib)


# Target
add_executable(${PROJECT_NAME} ${DIRSRCS})
target_link_libraries(${PROJECT_NAME} C_LIB)

