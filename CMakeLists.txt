cmake_minimum_required(VERSION 3.10)

# 设置项目名称和语言
project(SportsMeetingSystem VERSION 1.0 LANGUAGES CXX)

# 设置 C++ 标准 (推荐设定为 C++11 或以上，由于涉及结构体和文件操作，C++11足够)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定可执行文件输出目录为当前工程根目录下的 bin/ 文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

# 将 include/ 目录加入到编译器的寻找头文件路径中
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 显式列出所有源文件 (防止由于 glob 引起的文件新增不重新构建问题)
# 当你在 src 目录下增加新的 .cpp 文件时，记得更新这个列表
set(SOURCES
    src/main.cpp
    src/input_module.cpp
    src/match_module.cpp
    src/query_module.cpp
    src/utils.cpp
)

# 生成可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})

# （可选）配置编译时的警告级别，良好的习惯有助于提前发现野指针、未初始化等 Bug
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()
