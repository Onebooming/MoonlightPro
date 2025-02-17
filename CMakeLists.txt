cmake_minimum_required(VERSION 3.0)

# 项目名称
project(MoonLightPro VERSION 1.0)


# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# cmake输出当前版本信息
message(STATUS "Current source directory: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "Current binary directory: ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "C++ compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ compiler version: ${CMAKE_CXX_COMPILER_VERSION}")

# 添加头文件搜索路径
include_directories(${CMAKE_SOURCE_DIR}/include)

# 添加源文件
add_executable(MoonLightPro main.cpp src/hello.cpp src/message.cpp src/capthreadapi.cpp)

# 额外编译
# add_executable(clientDemo clientDemo.cpp)
# add_executable(serverDemo serverDemo.cpp)

# 额外编译
add_executable(clientDemo1 src/mnsocket.cpp src/client/mnclientsocket.cpp src/client/clientdemo1.cpp)
add_executable(serverDemo1 src/mnepoll.cpp src/mnthreadpool.cpp src/mnsocket.cpp src/server/mnserversocket.cpp src/server/serverdemo1.cpp)

# 添加链接库
target_link_libraries(MoonLightPro pthread)
# target_link_libraries(clientDemo pthread)
# target_link_libraries(serverDemo pthread)
target_link_libraries(clientDemo1 pthread)
target_link_libraries(serverDemo1 pthread)

# 配置调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-unused-local-typedefs -Wno-unused-private-field")