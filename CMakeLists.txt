cmake_minimum_required(VERSION 3.0)
project(gemtexttohtml)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp)

add_executable(gemtexttohtml main.cpp gemtranslator.cpp gemtranslator.h fdparser.cpp fdparser.h)
