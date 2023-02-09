if (CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    message(FATAL_ERROR YSDesignPattern must be subdirectory)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(submodules/YSUtility)

target_include_directories(${target_name} PUBLIC ./)
target_compile_features(${target_name} PUBLIC cxx_std_20)