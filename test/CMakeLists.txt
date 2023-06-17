cmake_minimum_required(VERSION 3.25)

project(YSDesignPatternTest
    LANGUAGES CXX)

execute_process(COMMAND ${CMAKE_COMMAND} -S ./.. -B ./../build -DCMAKE_INSTALL_PREFIX=${CMAKE_INSTALL_PREFIX})
execute_process(COMMAND ${CMAKE_COMMAND} --build ./../build --target install)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ysDesignPatternTest main.cpp)

target_include_directories(ysDesignPatternTest
    PUBLIC ${CMAKE_INSTALL_PREFIX}/inc)

# VS 시작프로젝트 설정
if (MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ysDesignPatternTest)
endif()