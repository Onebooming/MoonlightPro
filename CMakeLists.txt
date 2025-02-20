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
include_directories(${CMAKE_SOURCE_DIR}/src/http/core)
include_directories(${CMAKE_SOURCE_DIR}/src/http/app)
include_directories(${Boost_INCLUDE_DIRS})

# 查找Boost库
find_package(Boost REQUIRED COMPONENTS system thread)
find_package(OpenSSL REQUIRED)


# 添加源文件
add_executable(MoonLightPro main.cpp src/hello.cpp src/message.cpp src/capthreadapi.cpp)


# 额外编译
add_executable(clientDemo1 src/message.cpp src/mnsocket.cpp src/client/mnclientsocket.cpp src/client/clientdemo1.cpp)
add_executable(serverDemo1 src/message.cpp src/mnepoll.cpp src/mnthreadpool.cpp src/mnsocket.cpp src/server/mnserversocket.cpp src/server/serverdemo1.cpp)

# http server client
add_executable(httpclient src/client/mnhttpclientdemo.cpp)
add_executable(httpserver src/mnjson.cpp src/mnlog.cpp src/http/core/mnhttpserver.cpp src/http/app/app_hello.cpp src/http/app/app_admin_info.cpp src/server/mnhttpserverdemo.cpp)

# 添加链接库
target_link_libraries(MoonLightPro pthread)
target_link_libraries(clientDemo1 pthread)
target_link_libraries(serverDemo1 pthread)

target_link_libraries(httpclient pthread protobuf Boost::system Boost::thread OpenSSL::SSL OpenSSL::Crypto)
target_link_libraries(httpserver pthread protobuf Boost::system Boost::thread OpenSSL::SSL OpenSSL::Crypto)

# 配置调试信息
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-value -Wno-unused-local-typedefs -Wno-unused-private-field")