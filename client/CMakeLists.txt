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
include_directories(${CMAKE_SOURCE_DIR}/common/include)
include_directories(${Boost_INCLUDE_DIRS})

# 查找Boost库
find_package(Boost REQUIRED COMPONENTS system thread)
find_package(OpenSSL REQUIRED)

# 添加源文件列表
set(CLIENT_SOURCE_FILES 
    ../common/src/message.cpp 
    ../common/src/mnsocket.cpp 
    mnclientsocket.cpp 
    clientdemo1.cpp
)

# 编译
add_executable(client_demo_1 ${CLIENT_SOURCE_FILES})

# 添加链接库
target_link_libraries(client_demo_1 pthread ${Boost_LIBRARIES} OpenSSL::SSL OpenSSL::Crypto)

# 配置调试信息
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-unused-local-typedefs -Wno-unused-private-field")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

# 设置编译类型
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")