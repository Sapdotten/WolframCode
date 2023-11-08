cmake_minimum_required (VERSION 3.11)
project (WolframCode CXX)
set(CMAKE_CXX_STANDARD 23)

if(MSVC)
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

add_library(linked_list STATIC "include/linked_list/linked_list.cpp" "include/linked_list/node.cpp")
target_include_directories(linked_list PUBLIC "include/linked_list")

add_executable (${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} linked_list)
