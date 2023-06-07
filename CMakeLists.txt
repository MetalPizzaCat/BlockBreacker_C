cmake_minimum_required(VERSION 3.0.0)
project(block_breaker VERSION 0.1.0 LANGUAGES C)

find_package(SDL2 REQUIRED)
include_directories(block_breaker ${SDL2_INCLUDE_DIRS})
add_executable(block_breaker main.c window.h window.c block.h block.c)
target_link_libraries(block_breaker ${SDL2_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
