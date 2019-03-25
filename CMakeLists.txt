cmake_minimum_required(VERSION 3.13) #必须要
project(algorithm_learning)          #必须要
set(CMAKE_CXX_STANDARD 11)     #必须要


include_directories(./)        #添加头文件路径##可有可无
link_directories(./)           #添加库文件路径##可有可无


set(INC_DIR Solution.h)        #可有可无
set(LIB_DIR Solution.cpp)      #可有可无


add_library(Solution SHARED ${INC_DIR} ${LIB_DIR})   #添加动态库，不加SHARED默认是静态库##必须要
#link_libraries(Solution)                            #link_libraries 的作用和 target_link_libraries相同,可以2选1##必须要
add_executable(algorithm_learning test.cpp)          #添加可执行文件##必须要
target_link_libraries(algorithm_learning Solution)   #链接库文件##必须要